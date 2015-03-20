#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "model/point.h"



class LineSegment
{

    Point p1;
    Point p2;
    double slope;

public:
    LineSegment(const Point& p1, const Point& p2);
    const Point& getP1() const;
    const Point& getP2() const;
    double getSlope() const;

};

#endif // LINESEGMENT_H
