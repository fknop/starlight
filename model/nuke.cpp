#include "nuke.h"

Nuke::Nuke(const Point & p, double r) : Element(Element::Type::NUKE),
    pos {p}, rad {r}
{
    if (r <= 0)
        throw std::string("Le rayon doit être strictement supérieur à 0");

}

const Point& Nuke::getLocation() const
{
    return pos;
}

double Nuke::getRadius() const
{
    return rad;
}

bool Nuke::isLightedUp() const
{
    return light;
}

void Nuke::setLightedUp(bool q)
{
    light = q;
}

std::ostream & operator<<(std::ostream & out, const Nuke & s)
{
    out << "Nuke --- Position : " << s.pos << " , Radius : " << s.rad <<
        " On : " << s.light;
    return out;
}
