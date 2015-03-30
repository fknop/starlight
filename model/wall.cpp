#include "wall.h"

Wall::Wall(const Point & p1, const Point & p2) : start {p1}, end {p2}
{
    if (p1 == p2)
        throw std::string("Les deux extrémités du murs ne peuvent pas êtres égales");


    if (p1 < Point(0, 0))
        throw std::string("le mur ne peut pas être en dehors du jeu");

}

const Point & Wall::getStart() const
{
    return start;
}

const Point & Wall::getEnd() const
{
    return end;
}

std::ostream & operator<<(std::ostream & out, const Wall & w)
{
    out << "Wall --- Start : "  << w.start << ", End : " << w.end;
    return out;
}
