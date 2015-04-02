#include "geometry.h"
#include "linesegment.h"


LineSegment::LineSegment(const Point& start, const Point& end)
{
    this->start_ = start;
    this->end_ = end;
}

const Point& LineSegment::get_start() const
{
    return this->start_;
}

const Point& LineSegment::get_end() const
{
    return this->end_;
}

void LineSegment::set_start(const Point& start)
{
    this->start_ = start;
}

void LineSegment::set_end(const Point &end)
{
    this->end_ = end;
}
