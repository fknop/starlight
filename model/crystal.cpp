#include "crystal.h"


Crystal::Crystal(const Point & p, double r, int m) :
    Element(Element::Type::CRYSTAL),
    center {p}, rad {r}, mod {m}
{
    if (r <= 0)
        throw std::string("Le rayon doit être strictement strictement positif");
}

Crystal::Crystal(const Crystal & crystal) : Element(Element::Type::CRYSTAL)
{
    this->center = crystal.center;
    this->mod = crystal.mod;
    this->rad = crystal.rad;
}

const Point & Crystal::getCenter() const
{
    return center;
}

int Crystal::getModifier() const
{
    return mod;
}

double Crystal::getRadius() const
{
    return rad;
}

std::ostream & operator<<(std::ostream & out, const Crystal & c)
{
    out << "Crystal --- Center : " << c.center << " , Radius : " << c.rad
        << " , Modifier : " << c.mod;
    return out;
}
