#include "wall.h"


Wall::Wall(const Point & p1, const Point & p2) : Element(Element::Type::WALL),
    start_ {p1}, end_ {p2}
{
    if (p1 == p2)
        throw std::string("Les deux extrémités du murs ne peuvent pas êtres égales");


    if (p1 < Point(0, 0))
        throw std::string("le mur ne peut pas être en dehors du jeu");

}

Wall::Wall(const Wall& wall) : Element(Element::Type::WALL)
{
    this->start_ = wall.start_;
    this->end_ = wall.end_;
}

LineSegment Wall::to_line_segment()
{
    return LineSegment(this->start(), this->end());
}


std::ostream & operator<<(std::ostream & out, const Wall & w)
{
    out << "Wall --- Start : "  << w.start_ << ", End : " << w.end_;
    return out;
}

bool Wall::operator ==(const Wall& w) const
{
    return
     start_ == w.start_ &&
     end_ == w.end_;
}
