#include "wall.h"


Wall::Wall(const Point& p1, const Point& p2, bool movable) : Element(Element::Type::WALL),
    start_ {p1}, end_ {p2}, movable_{movable}
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
    this->movable_ = movable_;
}

LineSegment Wall::to_line_segment()
{
    return LineSegment(this->start(), this->end());
}


std::ostream& operator<<(std::ostream& out, const Wall& w)
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

void Wall::translate(double x, double y)
{
    if (movable_)
    {
        this->start_.set_position(start_.x() + x, start_.y() + y);
        this->end_.set_position(end_.x() + x, end_.y() + y);
        notify_all(std::string("TRANSLATE_WALL"));
    }
}

void Wall::rotate(double r)
{
    if (movable_)
    {
        LineSegment ls = to_line_segment();
        double center_x = (ls.start().x() + ls.end().x()) / 2;
        double center_y = (ls.start().y() + ls.end().y()) / 2;
        ls.rotate(Point(center_x, center_y), r);
        this->start_ = ls.start();
        this->end_ = ls.end();
        notify_all(std::string("ROTATE_WALL"));
    }
}
