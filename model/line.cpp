#include "geometry.h"
#include "line.h"
#include "umath.h"
#include "constants.h"


Line::Line(const Point& origin, double angle)
{
   this->origin_ = origin;
   this->angle_ = angle;
}

Line::Line(const Point& p1, const Point& p2)
{
   this->origin_ = p1;
   this->angle_ = Geometry::slope_to_rad(p1, p2);
}

bool operator==(const Line& l1, const Line& l2)
{
    return l1.angle_ == l2.angle_ && l1.origin_ == l2.origin_;
}

double Line::get_x(double y) const
{
    if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (M_PI_2)))
    {
        return origin_.x();
    }
    else if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (0)))
    {
        return 1; // on décide de renvoyer 1 car x peut prendre n'importe quelle valeur
    }
    else
    {
        double slope = Geometry::rad_to_slope(angle_);
        double b     = origin_.y() - (slope * origin_.x());
        return ((y - b) / slope);
    }
}
double Line::get_y(double x) const
{
    if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (0)))
    {
        return origin_.y();
    }
    else if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (M_PI_2)))
    {
        return 1; // on décide de renvoyer 1 car y peut prendre n'importe quelle valeur.
    }
    else
    {
        double slope = Geometry::rad_to_slope(angle_);
        double b     = origin_.y() - (slope * origin_.x());
        return (slope * x) + b;
    }
}



