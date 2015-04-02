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

    inline const Point& upper_left() const;
    inline double width() const;
    inline double height() const;

    int intersects(const Line& line, std::vector<Point> &);
    int intersects(const LineSegment& ls, std::vector<Point> &);
};

/* Fonctions inlines */

const Point& Rectangle::upper_left() const
{
    return this->upper_left_;
}

double Rectangle::width() const
{
    return this->width_;
}

double Rectangle::height() const
{
    return this->height_;
}

#endif // RECTANGLE_H
