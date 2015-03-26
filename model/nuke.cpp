#include "nuke.h"

Nuke::Nuke(const Point & p, int r) : pos {p}, rad {r}
{
    // TODO : valider rad

}

const Point &Nuke::getLocation() const
{
    return pos;
}

int Nuke::getRadius() const
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
