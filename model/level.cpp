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

}

bool Level::compute_ray(Line & line, int wl)
{
    bool continueRay;

    Intersection intersection = get_closest_intersection(line);



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

}


const Intersection& Level::get_closest_intersection(Line& line)
{
    std::vector<Intersection> intersections;
    std::vector<Point> points;

    if (this->dest_.to_rectangle().intersects(line, points))
        std::cout << "intersects";


    for (auto &i : this->walls_)
    {

    }

    for (auto &i : this->lenses_)
    {

    }

    for (auto &i : this->mirrors_)
    {

    }

    for (auto &i : this->nukes_)
    {

    }

    for (auto &i : this->crystals_)
    {

    }


}

void Level::notify(Observable * obs)
{
    for (Observer * o : this->observers_)
        o->notify(obs);
}

