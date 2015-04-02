#include <cmath>

#include "point.h"


Point::Point(double x, double y) : x_ {x}, y_ {y}
{}

Point::Point(const Point &p)
{
    this->x_ = p.x_;
    this->y_ = p.y_;
}

double Point::x() const
{
    return this->x_;
}

double Point::y() const
{
    return this->y_;
}

void Point::set_x(double x)
{
    this->x_ = x;
}

void Point::set_y(double y)
{
    this->y_ = y;
}

void Point::set_position(double x, double y)
{
    this->x_ = x;
    this->y_ = y;
}

double Point::distance(const Point &p)
{
    return sqrt(pow(this->x_ - p.x_, 2) + pow(this->y_ - p.y_, 2) );
}

bool operator <(const Point& p1, const Point& p2)
{
    return p1.x_ < p2.x_ || p1.y_ < p2.y_;
}

std::ostream & operator<<(std::ostream & out, const Point & p)
{
    out << "( " << p.x_ << " , " << p.y_ << " )";
    return out;
}

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x_ == p2.x_ && p1.y_ == p2.y_;
}

const Point& Point::operator =(const Point& p2)
{
    this->x_ = p2.x_;
    this->y_ = p2.y_;

    return *this;
}


