#include "ellipse.h"
#include <cmath>
#include "umath.h"
#include "Geometry.h"

Ellipse::Ellipse(const Point & p, double xRad, double yRad)
        : pos{p}, xRadius(xRad), yRadius(yRad)
{
    if (xRad <= 0 || yRad <= 0)
        throw std::string("Les rayons de l'ellipse doivent être strictement positifs.");
}

Ellipse::~Ellipse()
{

}

/*
 * cf. annexes du rapport du projet
 * pour les détails mathématiques
 * de cette méthode.
*/
int Ellipse::intersects(const Line & l, std::vector<Point>& points)
{

    double x = l.getPoint().getX();
    double y = l.getPoint().getY();
    double slope = Geometry::getSlope(l.getAngle()); // pente -> a dans y = ax + b
    double d = y - (slope * x); // d -> b dans y = ax + b
    double x1 = this->pos.getX();
    double y1 = this->pos.getY();
    double xR = this->xRadius;
    double yR = this->yRadius;
    double a, b, c; // a, b, c dans rho = b² - ac
    double rho;     // rho
    double lcm = umath::dlcm(xR*xR, yR*yR); // ppcm de a² et b²
    double lcmx = lcm / (yR*yR);
    double lcmy = lcm / (xR*xR);


    bool verticalLine = (std::abs(std::fmod(l.getAngle(), M_PI)) == (M_PI_2));

    if (verticalLine)
    {
        a = (lcmx);
        b = (-2* lcmx * y1);
        c = (lcmy * x * x) + (lcmy * x1 * x1) +(lcmx * y1 * y1)
                - (2 * lcmy * x * x1) - (lcm);
    }
    else
    {
        a = lcmy + (slope * slope * lcmx);
        b = -(2 * lcmy * d) - (2 * slope * lcmy * x1)
                - (2 * slope * slope * lcmx * y1);
        c = (lcmy * d * d) + (lcmy * slope * slope * x1 * x1)
                + (2 * slope * x1 * d)
                + (lcmx * slope * slope * y1 * y1)
                - (lcm * slope * slope);
    }

    rho = umath::rho(a, b, c);

    if (rho >= 0)
    {
        y = (-b + std::sqrt(rho)) / (2*a);
        x = verticalLine ? x : (y -d) / slope;
        points.push_back(Point(x, y));

        if (rho > 0)
        {
            y = (-b - std::sqrt(rho)) / (2*a);
            x = verticalLine ? x : (y -d) / slope;
            points.push_back(Point(x,y));
        }
    }

    return points.size();

}

int Ellipse::intersects(const LineSegment & ls, std::vector<Point>& points)
{
    Point start = ls.getStart();
    Point end = ls.getEnd();
    double rad = Geometry::getAngle(start, end);
    int intersections = intersects(Line(start, rad), points);

    if (intersections > 1 && !Geometry::isInBoundingBox(points.at(1), ls))
        points.erase(points.end());

    if (intersections > 0 && !Geometry::isInBoundingBox(points.at(0), ls))
        points.erase(points.begin());

    return points.size();
}

