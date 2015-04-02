#include <cmath>

#include "polarpoint.h"


PolarPoint::PolarPoint(const Point& p)
{
   distance_ = Point(0,0).distance(p);
   angle_ = std::atan2(p.x(), p.y());
}

PolarPoint::PolarPoint(double distance, double angle)
                : distance_{distance}, angle_{angle}
{
    if (distance < 0)
        throw std::string("La distance ne peut pas être négative");
}

Point * PolarPoint::to_point()
{
    double x = this->distance_ * std::cos(this->angle_);
    double y = this->distance_ * std::sin(this->angle_);
    return new Point(x,y);
}

PolarPoint::~PolarPoint()
{

}
