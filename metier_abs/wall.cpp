#include "wall.h"

Wall::Wall(const Point & p1, const Point & p2) : start {p1}, end {p2}
{

    if (p1 == p2)
    {

    }

    if (p1.isInvalid() || p2.isInvalid())
    {

    }


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
