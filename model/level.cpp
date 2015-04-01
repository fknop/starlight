#include "level.h"

#include <string>
#include "Geometry.h"

using namespace std;

Level::Level(double w, double h) : width_ {w}, height_ {h},
    walls_ { {{.0, .0}, {.0, h}}, {{.0, h}, {w, h}},
            {{w, h}, {w, .0}}, {{w, .0}, {.0, .0}} }
{
    if (w <= 0 || h <= 0)
        throw std::string("La taille et la longueur "
            "du plateau doivent etre strictement positives");

}

const Source & Level::source() const
{
    return source_;
}

void Level::set_source(const Source & value)
{
    source_ = value;
}

const Dest & Level::dest() const
{
    return dest_;
}

void Level::set_dest(const Dest & value)
{
    dest_ = value;
}

const vector<Wall> & Level::walls() const
{
    return walls_;
}

const vector<Mirror> & Level::mirrors() const
{
    return mirrors_;
}

const vector<Crystal> & Level::crystals() const
{
    return crystals_;
}

const vector<Lens> & Level::lenses() const
{
    return lenses_;
}

const vector<Ray> & Level::rays() const
{
    return rays_;
}

void Level::set_rays(const vector<Ray> & value)
{
    rays_ = value;
}

void Level::set_walls(const std::vector<Wall> & value)
{
    walls_ = value;
}

void Level::set_crystals(const std::vector<Crystal>& value)
{
    crystals_ = value;
}

void Level::set_nukes(const std::vector<Nuke>& value)
{
    nukes_ = value;
}

void Level::set_lenses(const std::vector<Lens>& value)
{
    lenses_ = value;
}

void Level::set_mirrors(const std::vector<Mirror>& value)
{
    mirrors_ = value;
}

const vector<Nuke> & Level::nukes() const
{
    return nukes_;
}

int Level::height()
{
    return height_;
}

int Level::width()
{
    return width_;
}

void Level::add_mirror(const Mirror & m)
{
    mirrors_.push_back(m);
}

void Level::add_nuke(const Nuke & n)
{
    nukes_.push_back(n);
}

void Level::add_wall(const Wall & w)
{
    walls_.push_back(w);
}

void Level::add_crystal(const Crystal & c)
{
    crystals_.push_back(c);
}

void Level::add_lens(const Lens & l)
{
    lenses_.push_back(l);
}

void Level::add_ray(const Ray & r)
{
    rays_.push_back(r);
}

//template <class T>
void Level::compute_rays()
{

    Point pSource = this->source_.getPosition();
    double radians = this->source_.getAngle();
    Line ray(pSource, radians);

}

//template <class T>
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
        dest_.setLightedUp(true);
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

    if (dest_.toRectangle().intersects(line, points))
        std::cout << "intersects";


    for (auto &i : walls_)
    {

    }

    for (auto &i : lenses_)
    {

    }

    for (auto &i : mirrors_)
    {

    }

    for (auto &i : nukes_)
    {

    }

    for (auto &i : crystals_)
    {

    }


}

void Level::notify(Observable * obs)
{
    for (Observer * o : observers)
        o->notify(obs);
}

