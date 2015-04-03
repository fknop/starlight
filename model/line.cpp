#include "geometry.h"
#include "line.h"
#include "umath.h"


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

bool Line::intersects(const Line &l, Point ** intersection) const
{
    double x, y,
           b1, b2,
           slope1, slope2;

    // Même droite ou parallèles
    if ((*this == l) ||
            (std::fmod(this->angle_, M_PI) == std::fmod(l.angle_, M_PI)))
    {
        *intersection = nullptr;
        return false;
    }

    // Même origine donc intersection == origin
    if (this->origin_ == l.origin_)
    {
        *intersection = new Point(this->origin_);
        return true;
    }

   // Droites verticales
   if (umath::double_equals(std::abs(std::fmod(this->angle_, M_PI)), (M_PI_2)))
   {
       vertical_line_intersection(*this, l, intersection);
   }
   else if (umath::double_equals(std::abs(std::fmod(l.angle_, M_PI)), (M_PI_2)))
   {
       vertical_line_intersection(l, *this, intersection);
   }
   // droites non verticales
   else
   {
       slope1 = Geometry::rad_to_slope(this->angle_);
       slope2 = Geometry::rad_to_slope(l.angle_);
       b1     = this->origin_.y() - (slope1 * this->origin_.x());
       b2     = l.origin_.y()     - (slope2 * l.origin_.x());
       x      = (b2 - b1) / (slope1 - slope2);
       y      = (slope2 * x) + b2;

       *intersection = new Point(x, y);
   }

   return true;
}

bool Line::intersects(const LineSegment &ls, Point ** intersection) const
{
    Point start = ls.start();
    Point end = ls.end();
    double rad = Geometry::slope_to_rad(start, end);

    if ((intersects(Line(start, rad), intersection)) &&
         (ls.contains(**intersection)))
            return true;

    delete *intersection;
    *intersection = nullptr;
    return false;
}

bool operator==(const Line& l1, const Line& l2)
{
    return l1.angle_ == l2.angle_ && l1.origin_ == l2.origin_;
}

// méthode privée
bool Line::vertical_line_intersection(const Line& verticalL, const Line& line,
                                      Point** intersection)
{
    double x     = verticalL.origin_.x();
    double slope = Geometry::rad_to_slope(line.angle_);
    double b     = line.origin_.y() - (slope * line.origin_.x());
    double y     = (x * slope) + b;
    *intersection = new Point(x,y);
    return true;
}
