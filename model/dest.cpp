#include "dest.h"

Dest::Dest(const Point & p, double e) : pos {p}, edge {e}
{
    // TODO : valider edge

    //Que faut-il vérifier ?
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
