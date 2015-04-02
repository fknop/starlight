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

const Source & Level::source() const
{
    return this->source_;
}

void Level::set_source(const Source & value)
{
    this->source_ = value;
}

const Dest & Level::dest() const
{
    return this->dest_;
}

void Level::set_dest(const Dest & value)
{
    this->dest_ = value;
}

const std::vector<Wall> & Level::walls() const
{
    return this->walls_;
}

const std::vector<Mirror> & Level::mirrors() const
{
    return this->mirrors_;
}

const std::vector<Crystal> & Level::crystals() const
{
    return this->crystals_;
}

const std::vector<Lens> & Level::lenses() const
{
    return this->lenses_;
}

const std::vector<Ray> & Level::rays() const
{
    return this->rays_;
}

void Level::set_rays(const std::vector<Ray> & value)
{
    this->rays_ = value;
}

void Level::set_walls(const std::vector<Wall> & value)
{
    this->walls_ = value;
}

void Level::set_crystals(const std::vector<Crystal>& value)
{
    this->crystals_ = value;
}

void Level::set_nukes(const std::vector<Nuke>& value)
{
    this->nukes_ = value;
}

void Level::set_lenses(const std::vector<Lens>& value)
{
    this->lenses_ = value;
}

void Level::set_mirrors(const std::vector<Mirror>& value)
{
    this->mirrors_ = value;
}

const std::vector<Nuke> & Level::nukes() const
{
    return this->nukes_;
}

int Level::height()
{
    return this->height_;
}

int Level::width()
{
    return this->width_;
}

void Level::add_mirror(const Mirror & m)
{
    this->mirrors_.push_back(m);
}

void Level::add_nuke(const Nuke & n)
{
    this->nukes_.push_back(n);
}

void Level::add_wall(const Wall & w)
{
    this->walls_.push_back(w);
}

void Level::add_crystal(const Crystal & c)
{
    this->crystals_.push_back(c);
}

void Level::add_lens(const Lens & l)
{
    this->lenses_.push_back(l);
}

void Level::add_ray(const Ray & r)
{
    this->rays_.push_back(r);
}

//template <class T>
void Level::compute_rays()
{

    Point pSource = this->source_.position();
    double radians = this->source_.angle();
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

