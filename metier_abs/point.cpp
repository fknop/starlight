#include "point.h"

Point::Point(int a, int b) : x {a}, y {b}
{}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int a)
{
    x = a;
}

void Point::setY(int a)
{
    y = a;
}

void Point::setLocation(int a, int b)
{
    x = a;
    y = b;
}

bool Point::isInvalid() const
{
    return x < 0 || y < 0;
}

std::ostream & operator<<(std::ostream & out, const Point & p)
{
    out << "( " << p.x << " , " << p.y << " )";
    return out;
}

bool operator==(Point& p1, Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}
