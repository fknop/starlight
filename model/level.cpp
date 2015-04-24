#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#include "model/level.h"

#include "utils/constants.h"
#include "utils/umath.h"


Level::Level(double w, double h) : width_ {w}, height_ {h},
    walls_ { {{.0, .0}, {.0, h}, false}, {{.0, h}, {w, h}, false},
    {{w, h}, {w, .0}, false}, {{w, .0}, {.0, .0}, false} },
    check_collisions_{true}, handle_dest_{true}, handle_nukes_{true}
{
    if (w <= 0 || h <= 0)
        throw std::string("La taille et la longueur "
                          "du plateau doivent etre strictement positives");
}

void Level::compute_rays()
{
    if (!rays_.empty())
        rays_.clear();

    if (source_.on())
    {
        Line ray(source_.pos(), source_.angle());
        compute_ray(ray, source_.pos(), source_.wavelength());
    }

    notify_all(std::string("RECOMPUTE"));
}

void Level::compute_ray(const Line& line, const Point& start, int wl)
{
    Nuke * nuke = nullptr;
    Mirror * mirror = nullptr;
    Lens * lens = nullptr;
    Crystal * crystal = nullptr;
    Point * new_line_origin = nullptr;
    Element::Type type;
    double angle = line.alpha();
    double new_wl = wl;
    bool continue_ray = false;

    get_intersections(line, start);

    type = intersections_.at(0).element_->type();
    new_line_origin = intersections_.at(0).point_;

    switch (type)
    {
        case Element::Type::CRYSTAL:
        {
            crystal = static_cast<Crystal *> (intersections_.at(0).element_);
            new_wl += crystal->modifier();

            if (intersections_.at(1).element_ == crystal)
                new_line_origin = intersections_.at(1).point_;

            continue_ray = true;
            break;
        }

        case Element::Type::DEST:
        {
            if (handle_dest_)
                dest_.set_lighted_up(true);

            continue_ray = false;
            break;
        }

        case Element::Type::LENS:
        {
            lens = static_cast<Lens *> (intersections_.at(0).element_);
            continue_ray = (wl >= lens->wl_min() && wl <= lens->wl_max());

            if (continue_ray && intersections_.at(1).element_ == lens)
                    new_line_origin = intersections_.at(1).point_;
            break;
        }

        case Element::Type::MIRROR:
        {
            mirror = static_cast<Mirror *> (intersections_.at(0).element_);
            angle = get_reflection_angle(angle, mirror->angle());
            continue_ray = true;
            break;
        }

        case Element::Type::NUKE:
        {
            nuke = static_cast<Nuke *> (intersections_.at(0).element_);
            if (handle_nukes_)
                nuke->set_lighted_up(true);

            continue_ray = false;
            break;
        }

        case Element::Type::WALL:
        case Element::Type::SOURCE:
        {
            continue_ray = false;
            break;
        }
    }

    rays_.push_back(Ray(start,
                       *(intersections_.at(0).point_),
                        wl));

    if (continue_ray)
    {
        Line newLine(Point(*new_line_origin), angle);
        compute_ray(newLine, *new_line_origin, new_wl);
    }
}

void Level::get_intersections(const Line& line, const Point& start)
{
    intersections_.clear();

    // Ajout des intersections au vecteur d'intersections
    if (!(start == source_.pos())) // Pour eviter que le rayon se bloque directement...
        this->source_intersections(line, start);

    this->walls_intersections(line, start);
    this->mirrors_intersections(line, start);
    this->lenses_intersections(line, start);
    this->dest_intersections(line, start);
    this->nukes_intersections(line, start);
    this->crystals_intersections(line, start);

    // Trie les intersections selon leur distance par rapport
    // à l'origine du rayon
    this->sort_intersections(start);
}

double Level::get_reflection_angle(double ray_angle, double m_alpha)
{
    if (umath::angle_equals_pi(ray_angle, m_alpha))
        return umath::to_positive_angle(ray_angle + PI);

    return umath::to_positive_angle(ray_angle + PI + (2 * (m_alpha + PI_2 - ray_angle)));
}

void Level::dest_intersections(const Line& line,
                               const Point& start)
{
    std::vector<Point> points;
    if (umath::intersects(dest_.to_rectangle(), line, points) > 0)
    {
        for (auto &i : points)
        {
            if (umath::is_on_trajectory(line, start, i))
                intersections_.push_back(Intersection(new Point(i), &this->dest_));
        }
    }
}

void Level::source_intersections(const Line& line,
                                 const Point& start)
{
    std::vector<Point> points;
    if (umath::intersects(source_.to_rectangle(), line, points) > 0)
    {
        for (auto &i : points)
        {
            if (umath::is_on_trajectory(line, start, i))
                intersections_.push_back(Intersection(new Point(i), &source_));
        }
    }
}

void Level::walls_intersections(const Line& line,
                                const Point& start)
{
    bool is_point;
    LineSegment ls;
    Point p;

    for (auto &i : walls_)
    {
        if (umath::intersects(line, i.to_line_segment(), p, ls, is_point))
        {
            if (!is_point)
            {
                if (start.distance(ls.start()) < start.distance(ls.end()))
                    p = Point(ls.start());
                else
                    p = Point(ls.end());
            }
            if (umath::is_on_trajectory(line, start, p))
                intersections_.push_back(Intersection(new Point(p), &i));
        }
    }
}

void Level::lenses_intersections(const Line& line,
                                 const Point& start)
{
    for (auto &i : lenses_)
    {
        std::vector<Point> points;

        if (umath::intersects(i.to_ellipse(), line, points))
        {
            for (auto &j : points)
            {
                if (umath::is_on_trajectory(line, start, j))
                    intersections_.push_back(Intersection(new Point(j), &i));
            }
        }
    }
}

void Level::mirrors_intersections(const Line& line,
                                  const Point& start)
{
    bool is_point;
    LineSegment ls;
    Point p;

    for (auto &i : mirrors_)
    {
        if (umath::intersects(line, i.to_line_segment(), p, ls, is_point))
        {
            if (!is_point)
            {
                if (start.distance(ls.start()) < start.distance(ls.end()))
                    p = Point(ls.start());
                else
                    p = Point(ls.end());
            }
            if (umath::is_on_trajectory(line, start, p))
                intersections_.push_back(Intersection(new Point(p), &i));
        }
    }
}

void Level::nukes_intersections(const Line& line,
                                const Point& start)
{
    for (auto &i : nukes_)
    {
        std::vector<Point> points;

        if (umath::intersects(i.to_ellipse(), line, points))
        {
            for (auto &j : points)
            {
                if (umath::is_on_trajectory(line, start, j))
                    intersections_.push_back(Intersection(new Point(j), &i));
            }
        }

    }
}

void Level::crystals_intersections(const Line& line,
                                   const Point& start)
{
    for (auto &i : crystals_)
    {
        std::vector<Point> points;

        if (umath::intersects(i.to_ellipse(), line, points))
        {
            for (auto &j : points)
            {
                if (umath::is_on_trajectory(line, start, j))
                    intersections_.push_back(Intersection(new Point(j), &i));
            }
        }
    }
}

void Level::sort_intersections(const Point& start)
{
    // Expression lambda servant à trier les intersections
    // dans l'ordre croissant selon leur distance
    // par rapport au point de départ.
    std::sort(intersections_.begin(), intersections_.end(),
              [start](const Intersection& a, const Intersection& b) -> bool
    {
        int distance_a = a.point_->distance(start);
        int distance_b = b.point_->distance(start);
        return (distance_a < distance_b);
    });
}

bool Level::check_collisions(const LineSegment& segment, Mirror * mirror)
{
    std::vector<Point> points;
    Point p;
    LineSegment ls;
    bool intersects = false;
    bool is_point;

    for (auto &i : walls_)
    {
        if (!intersects)
            intersects = umath::intersects(segment, i.to_line_segment(), p, ls, is_point);
    }

    for (auto &i : mirrors_)
    {
        if (!intersects && !(i == *mirror))
            intersects = umath::intersects(segment, i.to_line_segment(), p, ls, is_point);
    }

    for (auto &i : lenses_)
    {
        if (!intersects)
            intersects = (umath::intersects(i.to_ellipse(), segment, points) > 0);
    }

    for (auto &i : nukes_)
    {
        if (!intersects)
            intersects = (umath::intersects(i.to_ellipse(), segment, points) > 0);
    }

    for (auto &i : crystals_)
    {
        if (!intersects)
            intersects = (umath::intersects(i.to_ellipse(), segment, points) > 0);
    }

    if (!intersects)
        intersects = (umath::intersects(dest_.to_rectangle(), segment, points) > 0);

    if (!intersects)
        intersects = (umath::intersects(source_.to_rectangle(), segment, points) > 0);

    return intersects;
}

void Level::notify(Observable * o, const std::string& msg, const std::vector<std::string>& args)
{
    bool ask_translate = msg.compare("ASK_TRANSLATE") == 0;
    bool ask_rotate    = msg.compare("ASK_ROTATE") == 0;
    bool recompute = !ask_translate && !ask_rotate && msg.compare("LIGHTED_UP") != 0;

    if (check_collisions_ && (ask_rotate || ask_translate))
    {
        Mirror * mirror = static_cast<Mirror*> (o);
        LineSegment segment = mirror->to_line_segment();

        if (ask_translate)
        {
            std::stringstream ssx(args.at(0));
            std::stringstream ssy(args.at(1));
            double x = (ssx >> x, x);
            double y = (ssy >> y, y);
            segment.translate(x, y);
        }
        else if (ask_rotate)
        {
            std::stringstream ss(args.at(0));
            double angle = (ss >> angle, angle);
            segment.rotate(mirror->pivot(), angle);
        }

        // Le mirroir est empéché de se déplacer si collision.
        mirror->set_movable(!check_collisions(segment, mirror));
    }
    else if (recompute)
    {
        compute_rays();
    }
}
