#include "point.h"

Point::Point(int a, int b) : x {a}, y {b}
{}

Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
}

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

