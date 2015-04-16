#include <cmath>

#include "point.h"
#include "umath.h"


Point::Point(double x, double y) : x_ {x}, y_ {y}
{}

Point::Point(const Point &p)
{
    this->x_ = p.x_;
    this->y_ = p.y_;
}

double Point::distance(const Point& p) const
{
    return sqrt(pow(this->x_ - p.x_, 2) + pow(this->y_ - p.y_, 2) );
}

bool operator <(const Point& p1, const Point& p2)
{
    return p1.x_ < p2.x_ || p1.y_ < p2.y_;
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << "( " << p.x_ << " , " << p.y_ << " )";
    return out;
}

bool Point::operator==(const Point& p) const
{
    return umath::equals(p.x_, this->x_) && umath::equals(p.y_, this->y_);
}

const Point& Point::operator =(const Point& p2)
{
    this->x_ = p2.x_;
    this->y_ = p2.y_;

    return *this;
}


