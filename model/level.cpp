#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "geometry.h"
#include "level.h"
#include "constants.h"

Level::Level(double w, double h) : width_ {w}, height_ {h},
    walls_ { {{.0, .0}, {.0, h}}, {{.0, h}, {w, h}},
{{w, h}, {w, .0}}, {{w, .0}, {.0, .0}} }
{
    if (w <= 0 || h <= 0)
        throw std::string("La taille et la longueur "
                          "du plateau doivent etre strictement positives");
}

void Level::compute_rays()
{
    if (this->rays_.size() > 0)
        this->rays_.clear();

    if (source_.on())
    {
        Line ray(this->source_.pos(), this->source_.angle());
        State state = compute_ray(ray, this->source().pos(), this->source_.wavelength());

        switch (state)
        {
        case State::WIN:
            notify_all(std::string("GAME_WON"));
            break;
        case State::LOSE:
            notify_all(std::string("GAME_LOST"));
            break;
        case State::CONTINUE:
        case State::STOP:
            notify_all(std::string("CONTINUE"));
            break;
        }
    }
    else
    {
        notify_all(std::string("CLEAR_RAYS"));
    }
}

Level::State Level::compute_ray(Line& line, const Point& start, int wl)
{
    double angle = line.alpha();
    Nuke* nuke = nullptr;
    Mirror* mirror = nullptr;
    Lens* lens = nullptr;
    Crystal* crystal = nullptr;
    Point* new_line_origin = nullptr;
    State state;
    Element::Type type;

    get_intersections(line, start);

    type = this->intersections_.at(0).element()->type();
    new_line_origin = this->intersections_.at(0).point();

    switch (type)
    {
        case Element::Type::CRYSTAL:
        {
            crystal = dynamic_cast<Crystal*> (this->intersections_.at(0).element());
            wl += crystal->modifier();

            if (this->intersections_.at(1).element() == crystal)
                new_line_origin = this->intersections_.at(1).point();

            state = State::CONTINUE;
            break;
        }

        case Element::Type::DEST:
        {
            this->dest_.set_lighted_up(true);
            state = State::WIN;
            break;
        }

        case Element::Type::LENS:
        {
            lens = dynamic_cast<Lens*> (this->intersections_.at(0).element());
            if (wl >= lens->wl_min() && wl <= lens->wl_max())
            {
                if (this->intersections_.at(1).element() == lens)
                    new_line_origin = this->intersections_.at(1).point();
                state = State::CONTINUE;
            }
            else
            {
                state = State::STOP;
            }

            break;
        }

        case Element::Type::MIRROR:
        {
            mirror = dynamic_cast<Mirror*> (this->intersections_.at(0).element());
            angle = get_reflection_angle(angle, mirror->angle());
            state =  State::CONTINUE;
            break;
        }

        case Element::Type::NUKE:
        {
            nuke = dynamic_cast<Nuke*> (this->intersections_.at(0).element());
            nuke->set_lighted_up(true);
            state = State::LOSE;
            break;

        }

        case Element::Type::WALL:
        {
            state = State::STOP;
            break;
        }
    }

    this->rays_.push_back(Ray(start,
                          *(this->intersections_.at(0).point()),
                          wl));


    if (state == State::CONTINUE)
    {
        Line newLine(Point(*new_line_origin), angle);
        return compute_ray(newLine, *new_line_origin, wl);
    }
    else
    {
        return state;
    }
}

void Level::get_intersections(const Line& line, const Point& start)
{
    this->intersections_.clear();
    std::vector<Point> points;
    Point p;

    // Ajout des intersections au vecteur d'intersections
    walls_intersections(line, this->intersections_, p);
    mirrors_intersections(line, this->intersections_, p);
    lenses_intersections(line, this->intersections_, points);
    dest_intersections(line, this->intersections_, points);
    nukes_intersections(line, this->intersections_, points);
    crystals_intersections(line, this->intersections_, points);

    // Suppression des intersections du mauvais côté.
    erase_wrongs_intersections(line, this->intersections_, start);
    // Trie les intersections selon leur distance par rapport
    // à l'origine du rayon
    sort_intersections(line, this->intersections_, start);
}

double Level::get_reflection_angle(double angle, double alpha)
{
    if (alpha < 0)
    {
        alpha = (2*M_PI) + alpha;
        alpha = std::fmod(alpha, M_PI);
    }

    double p = std::fmod((M_PI_2 + alpha), (M_PI));
    if (p < 0)
    {
        p = (2*M_PI) + p;
        p = std::fmod(p, M_PI);
    }

    double angle_ray_p = p - (std::fmod(angle, M_PI));
    return std::fmod((angle + M_PI + (2 * angle_ray_p)), (2*M_PI));
}

void Level::dest_intersections(const Line &line,
                               std::vector<Intersection>& intersections,
                               std::vector<Point>& points)
{
    if (Geometry::intersects(this->dest_.to_rectangle(), line, points) > 0)
    {
        for (auto &i : points)
            intersections.push_back(Intersection(new Point(i), &this->dest_));
    }
}

void Level::walls_intersections(const Line &line,
                                std::vector<Intersection>& intersections,
                                Point& p)
{
    bool is_point;
    for (auto &i : this->walls_)
    {
        if (Geometry::intersects(line, i.to_line_segment(), p, is_point))
            intersections.push_back(Intersection(new Point(p), &i));
    }
}

void Level::lenses_intersections(const Line &line,
                                 std::vector<Intersection>& intersections,
                                 std::vector<Point>& points)
{
    for (auto &i : this->lenses_)
    {
        points.clear();
        if (Geometry::intersects(i.to_ellipse(), line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }
}

void Level::mirrors_intersections(const Line &line,
                                  std::vector<Intersection>& intersections,
                                  Point& p)
{
    bool is_point;
    for (auto &i : this->mirrors_)
    {
        if (Geometry::intersects(line, i.to_line_segment(), p, is_point))
            intersections.push_back(Intersection(new Point(p), &i));
    }
}

void Level::nukes_intersections(const Line& line,
                                std::vector<Intersection>& intersections,
                                std::vector<Point>& points)
{
    for (auto &i : this->nukes_)
    {
        points.clear();
        if (Geometry::intersects(i.to_ellipse(), line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }
}

void Level::crystals_intersections(const Line &line,
                                   std::vector<Intersection>& intersections,
                                   std::vector<Point>& points)
{
    for (auto &i : this->crystals_)
    {
        points.clear();
        if (Geometry::intersects(i.to_ellipse(), line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }
}

void Level::erase_wrongs_intersections(const Line& line,
                                       std::vector<Intersection>& intersections,
                                       const Point& start)
{
    for (auto i = intersections.begin(); i != intersections.end(); )
    {
        if (!Geometry::is_on_good_side(line, start, *(*i).point()))
            i = intersections.erase(i);
        else
            ++i;
    }
}

///////////////////// TO CHECK ///////////////
void Level::sort_intersections(const Line &line,
                               std::vector<Intersection>& intersections,
                               const Point& start)
{
    std::sort(intersections.begin(), intersections.end(),
              [start](const Intersection& a, const Intersection& b) -> bool
    {
        int distance_a = a.point()->distance(start);
        int distance_b = b.point()->distance(start);
        return (distance_a < distance_b);
    });
}

bool Level::check_collisions(const LineSegment& segment, Mirror * mirror)
{
    std::vector<Point> points;
    Point p;
    bool intersects = false;
    bool is_point;

    for (auto &i : this->walls_)
    {
        if (!intersects)
            intersects = Geometry::intersects(segment, i.to_line_segment(), p, is_point);
    }

    for (auto &i : this->mirrors_)
    {
        if (!intersects && !(i == *mirror))
            intersects = Geometry::intersects(segment, i.to_line_segment(), p, is_point);
    }

    for (auto &i : this->lenses_)
    {
        if (!intersects)
            intersects = (Geometry::intersects(i.to_ellipse(), segment, points) > 0);
    }

    for (auto &i : this->nukes_)
    {
        if (!intersects)
            intersects = (Geometry::intersects(i.to_ellipse(), segment, points) > 0);
    }

    for (auto &i : this->crystals_)
    {
        if (!intersects)
            intersects = (Geometry::intersects(i.to_ellipse(), segment, points) > 0);
    }

    if (!intersects)
        intersects = (Geometry::intersects(this->dest_.to_rectangle(), segment, points) > 0);

    if (!intersects)
        intersects = (Geometry::intersects(this->source_.to_rectangle(), segment, points) > 0);

    return intersects;
}

void Level::notify(Observable* obs, std::string msg, const std::vector<std::string>& args)
{
    bool ask_translate = msg.compare("ASK_TRANSLATE") == 0;
    bool ask_rotate    = msg.compare("ASK_ROTATE") == 0;
    bool recompute = msg.compare("TRANSLATE_MIRROR") == 0 ||
                     msg.compare("ROTATE_MIRROR") == 0 ||
                     msg.compare("SOURCE_ON") == 0;

    if (ask_rotate || ask_translate)
    {
        Mirror *mirror = dynamic_cast<Mirror*> (obs);
        LineSegment segment = mirror->to_line_segment();

        if (ask_translate)
        {
            std::stringstream ssx(args.at(0));
            std::stringstream ssy(args.at(1));
            double x = (ssx >> x, x);
            double y = (ssy >> y, y);
            segment.translate(x, y);
            if (check_collisions(segment, mirror))
                mirror->set_movable(false);
        }
        else if (ask_rotate)
        {
            // TO FIX
            std::stringstream ss(args.at(0));
            double angle = (ss >> angle, angle);
            segment.rotate(mirror->pivot(), angle);
            if (check_collisions(segment, mirror))
                mirror->set_movable(false);
            // TO FIX
        }
    }
    else if (recompute)
    {
           compute_rays();
    }





}

