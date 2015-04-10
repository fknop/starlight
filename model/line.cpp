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



