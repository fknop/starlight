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
