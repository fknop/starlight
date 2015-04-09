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

//// méthode privée
//bool Line::vertical_line_intersection(const Line& verticalL, const Line& line,
//                                      Point** intersection)
//{
//    double x     = verticalL.origin_.x();
//    double slope = Geometry::rad_to_slope(line.angle_);
//    double b     = line.origin_.y() - (slope * line.origin_.x());
//    double y     = (x * slope) + b;
//    *intersection = new Point(x,y);
//    return true;
//}
