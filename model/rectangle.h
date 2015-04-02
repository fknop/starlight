#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>

#include "point.h"
#include "Line.h"
#include "linesegment.h"

class Rectangle
{

private:
    Point upperLeft;
    double width;
    double height;

public:
    Rectangle(const Point&, double, double);
    ~Rectangle();

    int intersects(const Line& line, std::vector<Point> &);
    int intersects(const LineSegment& ls, std::vector<Point> &);
};

#endif // RECTANGLE_H
