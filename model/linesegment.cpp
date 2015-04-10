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

bool LineSegment::operator==(const LineSegment& ls) const
{
    return this->start_ == ls.start_ && this->end_ == ls.end_;
}
