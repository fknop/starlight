#include "polarpoint.h"

#include <cmath>


PolarPoint::PolarPoint(const Point& p)
{
   distance = Point(0,0).distance(p);
   angle = std::atan2(p.getX(), p.getY());
}

PolarPoint::PolarPoint(double distance, double angle)
                : distance{distance}, angle{angle}
{
    if (distance < 0)
        throw std::string("La distance ne peut pas être négative");
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

Point * PolarPoint::toPoint()
{
    double x = distance * std::cos(angle);
    double y = distance * std::sin(angle);
    return new Point(x,y);
}

PolarPoint::~PolarPoint()
{

}
