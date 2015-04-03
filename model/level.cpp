#include <string>
#include <vector>

#include "geometry.h"
#include "level.h"


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

    Point pSource = this->source_.position();
    double radians = this->source_.angle();
    Line ray(pSource, radians);

    compute_ray(ray, 600);

}

bool Level::compute_ray(Line& line, int wl)
{
    bool continueRay;

    Intersection intersection = get_closest_intersection(line);


    Line newLine(line);
    Element::Type type = intersection.element().type();
    switch (type)
    {
    case Element::Type::CRYSTAL:
        break;
    case Element::Type::DEST:
        this->dest_.set_lighted_up(true);
        continueRay = false;
        //Notifie vue -> Allumer la dest.
        // bool = gagner ?
        break;
    case Element::Type::LENS:
        continueRay = true;
        break;
    case Element::Type::MIRROR:
        continueRay = true;
        break;
    case Element::Type::NUKE:
        continueRay = false;
        break;
    case Element::Type::WALL:
        continueRay = false;
        break;
    }

    if (continueRay)
        compute_ray(newLine, wl);

}


const Intersection& Level::get_closest_intersection(const Line& line)
{
    std::vector<Intersection> intersections;

    std::vector<Point> points;
    if (this->dest_.to_rectangle().intersects(line, points) > 0)
    {
         for (auto &i : points)
            intersections.push_back(Intersection(i, this->dest_));
    }

    for (auto &i : this->walls_)
    {
        Point * p = nullptr;
        if (line.intersects(i.to_line_segment(), &p))
            intersections.push_back(Intersection(Point(*p), i));

        delete p;
    }

    for (auto &i : this->lenses_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points) > 0)
        {
            for (auto &j : points)
                intersections.push_back(Intersection(j, i));
        }
    }

    for (auto &i : this->mirrors_)
    {
        Point* p = nullptr;
        if (line.intersects( i.to_line_segment(), &p))
            intersections.push_back(Intersection(Point(*p), i));

        delete p;
    }

    for (auto &i : this->nukes_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(j, i));
        }
    }

    for (auto &i : this->crystals_)
    {
        points.clear();
        if (i.to_ellipse().intersects(line, points))
        {
            for (auto &j : points)
                intersections.push_back(Intersection(j, i));
        }
    }

    // Supression des points du mauvais coté
    for (auto i = intersections.begin(); i != intersections.end();)
    {
        if (!Geometry::is_on_good_side(line, (*i).point()))
            i = intersections.erase(i);
        else
            ++i;
    }


    // Trier les points
    // Retourner l'interesction la plus proche



}

void Level::notify(Observable * obs)
{
    for (Observer * o : this->observers_)
        o->notify(obs);
}

