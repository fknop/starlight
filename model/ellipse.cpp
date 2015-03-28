#include "ellipse.h"
#include <cmath>

Ellipse::Ellipse(const Point & p, double xRad, double yRad)
        : pos{p}, xRadius(xRad), yRadius(yRad)
{
    if (xRad <= 0 || yRad <= 0)
        throw "Les rayons de l'ellipse doivent être strictement positif";
}

Ellipse::~Ellipse()
{

}

bool Ellipse::intersects(const Line & l, std::vector<Point>& points)
{

    double x1 = this->pos.getX();
    double y1 = this->pos.getY();
    double a = this->xRadius * 2;
    double b = this->yRadius * 2;
    double x, y, x2, y2;


    // ((x - x1)² / a²) + ((y- y1)² / b²) = 1
    if (std::abs(std::fmod(l.getAngle(), M_PI)) == (M_PI / 2))
    {

    }
    else
    {
//        slope1 = Geometry::getSlope(this->angle);
//        slope2 = Geometry::getSlope(l.angle);
//        b1     = this->origin.getY() - (slope1 * l.origin.getX());
//        b2     = l.origin.getY() - (slope2 * l.origin.getX());
//        x1     = (b2 - b1) / (slope1 - slope2);
//        y1     = (slope2 * x1) + b2;

//        *intersection = new Point(x1, y1);
    }

}

bool Ellipse::intersects(const LineSegment & ls, std::vector<Point>& points)
{



}

