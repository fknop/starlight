#include "geometry.h"
#include "linesegment.h"


LineSegment::LineSegment(const Point& start, const Point& end)
{
    this->start_ = start;
    this->end_ = end;
}

bool LineSegment::contains(const Point& p) const
{
    return ((std::min(this->start_.x(), this->end_.x()) <= p.x()) &&
            (std::max(this->start_.x(), this->end_.x()) >= p.x()) &&
            (std::min(this->start_.y(), this->end_.y()) <= p.y()) &&
            (std::max(this->start_.y(), this->end_.y()) >= p.y()));
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
    double alpha  = Geometry::slope_to_rad(start_, end_) + angle;
    this->translate(-pivotX, -pivotY);
    double new_start_x = 0 - (xpad * std::cos(alpha));
    double new_start_y = 0 + (xpad * sin(alpha));
    double new_end_x = 0 + ((len - xpad) * std::cos(alpha));
    double new_end_y = 0 - ((len - xpad) * std::sin(alpha));

    start_.set_position(new_start_x, new_start_y);
    end_.set_position(new_end_x, new_end_y);
    this->translate(pivotX, pivotY);
}

bool LineSegment::operator==(const LineSegment& ls) const
{
    return this->start_ == ls.start_ && this->end_ == ls.end_;
}
