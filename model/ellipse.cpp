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

int Ellipse::intersects(const Line & l, std::vector<Point>& points)
{

    double x1 = this->pos.getX();
    double y1 = this->pos.getY();
    double xR = this->xRadius;
    double yR = this->yRadius;
    double x, y, x2, y2;
    double a, b, c;
    double rho;
    double yPoint1;
    double yPoint2;

    // xR correspond au a, yR correspond au b :
    // ((x - x1)² / a²) + ((y- y1)² / b²) = 1
    // (y² - 2*y*y1 + y1²) * a² + b² * (x-x1)² = a² * b²
    // a² * y² - 2*a²*y*y1 + a²*y1² + x²*b² - 2*b²*x*x1 + x1² - a² * b² = 0
    if (std::abs(std::fmod(l.getAngle(), M_PI)) == (M_PI / 2))
    {
        x = l.getPoint().getX();
        c = (yR*yR * x*x);
        c -= (2 * yR*yR * x*x1);
        c += (yR*yR * x1*x1);
        c -= (xR*xR * yR*yR);
        c += (xR*xR * y1*y1);
        a = (xR*xR);
        b = (-2* xR*xR * y1);
        rho = (b*b) - (4 * a * c);

        if (rho == 0)
        {
            yPoint1 = -b / (2*a);
            points.push_back(Point(x, yPoint1));
            return 1;
        }
        else if (rho > 0)
        {
            yPoint1 = (-b + std::sqrt(rho)) / (2*a);
            yPoint2 = (-b - std::sqrt(rho)) / (2*a);
            points.push_back(Point(x, yPoint1));
            points.push_back(Point(x, yPoint2));
            return 2;
        }
        else
        {
            return 0;
        }
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

int Ellipse::intersects(const LineSegment & ls, std::vector<Point>& points)
{



}

