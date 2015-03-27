#include "crystal.h"


Crystal::Crystal(const Point & p, double r, int m) : center {p}, rad {r},
mod {m}
{
    // TODO : valider rad (et mod ?)
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
