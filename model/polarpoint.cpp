#include "polarpoint.h"

#include <cmath>

/*
 * Distance (0,0) et (x,y)
 * x = distance * cos (angle)
 * y = distance * sin (angle)
 * cos(angle) = x / distance
 * angle = arcos(x / distance)
*/
PolarPoint::PolarPoint(const Point& p)
{
   distance = Point(0,0).distance(p);
   angle = std::acos(p.getX() / distance);
}

PolarPoint::PolarPoint(double distance, double angle)
                : distance{distance}, angle{angle}
{
    if (distance < 0)
        throw "La distance ne peut pas être négative";
}

void PolarPoint::setAngle(double a)
{
    this->angle = a;
}

double PolarPoint::getAngle() const
{
    return this->angle;
}

void PolarPoint::setDistance(double d)
{
    if (distance < 0)
      this->distance = d;
    throw "La distance ne peut pas être négative";
}

double PolarPoint::getDistance() const
{
    return this->distance;
}

const Point& PolarPoint::toPoint() const
{
    double x = distance * std::cos(angle);
    double y = distance * std::sin(angle);
    const Point &p = Point(x,y);
    return p;
}

PolarPoint::~PolarPoint()
{

}
