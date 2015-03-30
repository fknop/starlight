#include "linesegment.h"
#include "Geometry.h"

LineSegment::LineSegment(const Point& start, const Point& end)
{
    this->start = start;
    this->end = end;
}

const Point& LineSegment::getStart() const
{
    return this->start;
}

const Point& LineSegment::getEnd() const
{
    return this->end;
}

void LineSegment::setStart(const Point& start)
{
    this->start = start;
}

void LineSegment::setEnd(const Point &end)
{
    this->end = end;
}
