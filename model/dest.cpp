#include "dest.h"

Dest::Dest(const Point & p, double e) : Element(Element::Type::DEST), pos {p}, edge {e}
{
    if (e <= 0)
        throw std::string("La longueur doit être strictement supérieure à 0");
}

const Point & Dest::getPosition() const
{
    return pos;
}

double Dest::getEdge() const
{
    return edge;
}

bool Dest::isLightedUp() const
{
    return light;
}

void Dest::setLightedUp(const bool q)
{
    light = q;
}

std::ostream & operator<<(std::ostream & out, const Dest & d)
{
    out << "Dest --- Position : " << d.pos <<  " , Edge : " << d.edge <<
        " , lighted up : " << d.light;
    return out;
}
