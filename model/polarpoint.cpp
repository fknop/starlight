#include <cmath>

#include "polarpoint.h"


PolarPoint::PolarPoint(const Point& p)
{
   distance_ = Point(0,0).distance(p);
   angle_ = std::atan2(p.y(), p.x());
}

PolarPoint::PolarPoint(double distance, double angle)
                : distance_{distance}, angle_{angle}
{
    if (distance < 0)
        throw std::string("La distance ne peut pas être négative");
}

Point PolarPoint::to_point()
{
    double x = this->distance_ * std::cos(this->angle_);
    double y = this->distance_ * std::sin(this->angle_);
    return Point(x,y);
}

std::ostream& operator<<(std::ostream& out, const PolarPoint& p)
{
    out << "Angle : " << p.angle_ << " Distance  : " << p.distance_;
}
