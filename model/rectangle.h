#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>

#include "line.h"
#include "linesegment.h"
#include "point.h"


class Rectangle
{

private:
    Point upper_left_;
    double width_;
    double height_;

public:
    Rectangle(const Point&, double, double);
    ~Rectangle();

    int intersects(const Line& line, std::vector<Point> &);
    int intersects(const LineSegment& ls, std::vector<Point> &);
};

#endif // RECTANGLE_H
