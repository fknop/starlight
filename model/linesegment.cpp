#include "model/linesegment.h"
#include "model/geometry.h"
#include "model/umath.h"


LineSegment::LineSegment(const Point& p1, const Point& p2)
{
   if (p1 == p2)
   {
       std::cout << p1 << std::endl;
       std::cout << p2 << std::endl;
   }
      // throw std::string("Un segment doit contenir deux points différents");

    if (p1.x() < p2.x() ||
            (umath::equals(p1.x(), p2.x()) && p1.y() < p2.y()))
    {
        this->start_ = p1;
        this->end_ = p2;
    }
    else if (p1.x() > p2.x()
             || (umath::equals(p1.x(), p2.x()) && p1.y() > p2.y()))
    {
        this->start_ = p2;
        this->end_ = p1;
    }
}

bool LineSegment::contains(const Point& p) const
{
    return ((std::min(start_.x(), end_.x()) < p.x() ||
             umath::equals(std::min(start_.x(), end_.x()), p.x())) &&
            (std::max(start_.x(), end_.x()) > p.x() ||
             umath::equals(std::max(start_.x(), end_.x()), p.x())) &&
            (std::min(start_.y(), end_.y()) < p.y() ||
             umath::equals(std::min(start_.y(), end_.y()), p.y())) &&
            (std::max(start_.y(), end_.y()) > p.y() ||
             umath::equals(std::max(start_.y(), end_.y()), p.y())));
}

void LineSegment::translate(double x, double y)
{
    this->start_.set_position(this->start_.x() + x, this->start_.y() + y);
    this->end_.set_position(this->end_.x() + x, this->end_.y() + y);
}

void LineSegment::rotate(const Point& pivot, double angle)
{
    double pivotX = pivot.x();
    double pivotY = pivot.y();
    double xpad   = start_.distance(pivot);
    double len    = start_.distance(end_);
    double alpha  = -Geometry::slope_to_rad(start_, end_) + angle;
    this->translate(-pivotX, -pivotY);
    double new_start_x = 0 - (xpad * std::cos(alpha));
    double new_start_y = 0 + (xpad * std::sin(alpha));
    double new_end_x = 0 + ((len - xpad) * std::cos(alpha));
    double new_end_y = 0 - ((len - xpad) * std::sin(alpha));
    start_.set_position(new_start_x, new_start_y);
    end_.set_position(new_end_x, new_end_y);
    this->translate(pivotX, pivotY);
}

bool LineSegment::operator==(const LineSegment& ls) const
{
    return (this->start_ == ls.start_ && this->end_ == ls.end_)
            || (this->start_ == ls.end_ && this->end_ == ls.start_);
}

Line LineSegment::to_line() const
{
    return Line(start_, end_);
}
