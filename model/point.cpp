#include "point.h"
#include <cmath>

Point::Point(double a, double b) : x {a}, y {b}
{}

Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::setX(double a)
{
    x = a;
}

void Point::setY(double a)
{
    y = a;
}

void Point::setLocation(double a, double b)
{
    x = a;
    y = b;
}

double Point::distance(const Point &p)
{
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2) );
}

bool operator <(const Point& p1, const Point& p2)
{
    return p1.x < p2.x || p1.y < p2.y;
}

std::ostream & operator<<(std::ostream & out, const Point & p)
{
    out << "( " << p.x << " , " << p.y << " )";
    return out;
}

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}



