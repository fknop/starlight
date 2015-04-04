#include <string>
#include <vector>
#include <algorithm>

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

    add_mirror(Mirror(Point(30, 500), 29, 58, -M_PI_4));
    Point pSource = this->source_.position();
    double radians = this->source_.angle();
    Line ray(pSource, radians);

    compute_ray(ray, 600);

}

Level::State Level::compute_ray(Line& line, int wl)
{
    State state;
    double angle = line.angle();
    Intersection* intersection = get_closest_intersection(line);
    Element::Type type = intersection->element()->type();

    this->rays_.push_back(Ray(line.origin(), *intersection->point()));

    Nuke* nuke = nullptr;
    Mirror* mirror = nullptr;
    Lens* lens = nullptr;
    Crystal* crystal = nullptr;

    switch (type)
    {

    case Element::Type::CRYSTAL:
    {
        crystal = dynamic_cast<Crystal*> (intersection->element());
        wl += crystal->modifier();
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
        lens = dynamic_cast<Lens*> (intersection->element());
        if (wl >= lens->wl_min() && wl <= lens->wl_max())
            state = State::CONTINUE; // ou stop
        else
            state = State::STOP;
        break;
    }

    case Element::Type::MIRROR:
    {
        mirror = dynamic_cast<Mirror*> (intersection->element());
        double mirrorAngle =
                mirror->angle() < 0 ? (2*M_PI) + mirror->angle() : mirror->angle();

        double a = line.angle() > M_PI ? line.angle() - M_PI : line.angle() + M_PI;
        double b = std::abs(a - mirrorAngle);
        double c = a + (2* std::abs(M_PI_2 - b));
        angle = c;

        std::cout << "Angle mirroir : " << Geometry::rad_to_deg(mirror->angle()) << std::endl;
        std::cout << "Angle rayon : " << Geometry::rad_to_deg(line.angle()) << std::endl;
        std::cout << "Angle =/= axe X mirroir : " << Geometry::rad_to_deg(a) << std::endl;
        std::cout << "Angle =/= Mirroir  : " << Geometry::rad_to_deg(b) << std::endl;
        state = State::CONTINUE;
        break;
    }

    case Element::Type::NUKE:
    {

        nuke = dynamic_cast<Nuke*> (intersection->element());
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

    if (state == State::CONTINUE)
    {
        Line newLine(Point(*intersection->point()), angle);
        compute_ray(newLine, wl);
    }

    delete intersection;
    return state;


}


Intersection* Level::get_closest_intersection(const Line& line)
{
    std::vector<Intersection> intersections;

    std::vector<Point> points;
    if (this->dest_.to_rectangle().intersects(line, points) > 0)
    {
        for (auto &i : points)
            intersections.push_back(Intersection(&i, &this->dest_));
    }

    for (auto &i : this->walls_)
    {
        Point * p = nullptr;
        if (line.intersects(i.to_line_segment(), &p))
        {
            intersections.push_back(Intersection(new Point(*p), &i));
        }
        delete p;
    }

    for (auto &i : this->lenses_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points) > 0)
        {
            for (auto &j : points)
                intersections.push_back(Intersection(&j, &i));
        }
    }

    for (auto &i : this->mirrors_)
    {
        Point* p = nullptr;
        if (line.intersects( i.to_line_segment(), &p))
            intersections.push_back(Intersection(new Point(*p), &i));

        delete p;
    }

    for (auto &i : this->nukes_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }

    for (auto &i : this->crystals_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(new Point(j), &i));
        }
    }

    // Supression des points du mauvais coté
    for (auto i = intersections.begin(); i != intersections.end();)
    {
        if (!Geometry::is_on_good_side(line, *(*i).point()))
            i = intersections.erase(i);
        else
            ++i;
    }

    std::sort(intersections.begin(), intersections.end(),
              [line](const Intersection& a, const Intersection& b) -> bool
    {
        double distanceA = a.point()->distance(line.origin());
        double distanceB = b.point()->distance(line.origin());
        return distanceA < distanceB;
    });

    return new Intersection(intersections.at(0));
}

void Level::notify(Observable * obs)
{
//    for (Observer * o : this->observers_)
//        o->notify(obs);
}

