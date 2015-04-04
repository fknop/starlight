#include <string>
#include <vector>

#include "geometry.h"
#include "level.h"
#include "algorithm"


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

void Level::compute_ray(Line& line, int wl)
{
    bool continueRay;
    Intersection* intersection = get_closest_intersection(line);
    Element::Type type = intersection->element().type();



    this->rays_.push_back(Ray(line.origin(), intersection->point()));

    switch (type)
    {
    case Element::Type::CRYSTAL:
        //Crystal* crystal = dynamic_cast<Crystal*> (intersection.element());
        break;
    case Element::Type::DEST:
        this->dest_.set_lighted_up(true);
        continueRay = false;
        //Notifie vue -> Allumer la dest.
        // bool = gagner ?

        break;
    case Element::Type::LENS:
        //mur ou passer
        continueRay = true;
        break;
    case Element::Type::MIRROR:
        //reflexion
        continueRay = true;
        break;
    case Element::Type::NUKE:
        continueRay = false;
        break;
    case Element::Type::WALL:
        continueRay = false;
        break;
    }

    // TODO
    Line newLine(intersection->point(), M_PI);


    if (continueRay)
        compute_ray(newLine, wl);

}


Intersection* Level::get_closest_intersection(const Line& line)
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
        {
            intersections.push_back(Intersection(Point(*p), i));

            std::cout << *p;
        }


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

    std::sort(intersections.begin(), intersections.end(),
        [line](const Intersection& a, const Intersection& b) -> bool
    {
        double distanceA = a.point().distance(line.origin());
        double distanceB = b.point().distance(line.origin());
        return distanceA < distanceB;
    });



    return new Intersection(intersections.at(0));
}

void Level::notify(Observable * obs)
{
    for (Observer * o : this->observers_)
        o->notify(obs);
}

