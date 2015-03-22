#include "linesegment.h"
#include "Geometry.h"

LineSegment::LineSegment(const Point& p1, const Point& p2)
{
    this->p1 = p1;
    this->p2 = p2;
    this->slope = Geometry::findSlope(p1, p2);
}

const Point& LineSegment::getP1() const
{
    return this->p1;
}

const Point& LineSegment::getP2() const
{
    return this->p2;
}

double LineSegment::getSlope() const
{
    return this->slope;
}
