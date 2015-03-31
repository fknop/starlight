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

std::vector<Point> Ellipse::methodeA(std::vector<Point> points, double x, double x1, double y1, double lcm, double lcmx, double lcmy)
{
    double a, b, c, d, rho, y, x2, y2;
    c = (lcmy * x * x);
    c -= (2 * lcmy * x * x1);
    c += (lcmy * x1 * x1);
    c -= (lcm);
    c += (lcmx * y1 * y1);
    a = (lcmx);
    b = (-2 * lcmx * y1);
    rho = umath::rho(a, b ,c);

    if (rho == 0)
    {
        y = -b / (2 * a);
        points.push_back(Point(x, y));
    }
    else if (rho > 0)
    {
        y = (-b + std::sqrt(rho)) / (2 * a);
        y2 = (-b - std::sqrt(rho)) / (2 * a);
        points.push_back(Point(x, y));
        points.push_back(Point(x, y2)); // x2 ?
    }
}


std::vector<Point> Ellipse::methodeB(std::vector<Point> points, double x, double y, double x1, double y1, double slope, double lcm, double lcmx, double lcmy)
{
    double a, b, c, d, rho, x2, y2;
    // d est b dans y = ax + b
    d = y - (slope * x);
    c = -lcm;
    c += lcmx * std::pow((d - y1), 2);
    c += lcmy * x1 * x1;
    a = lcmy + (lcmx * slope * slope);
    b = -(lcmy * 2 * x1) + (lcmx * 2 * slope * (d-y1));
    rho = umath::rho(a, b, c);

    if (rho == 0)
    {
        x = -b / (2 * a);
        y = (slope * x) + d;
        points.push_back(Point(x, y));
    }
    else if (rho > 0)
    {
        x = (-b + std::sqrt(rho)) / (2 * a);
        x2 = (-b - std::sqrt(rho)) / (2 * a);
        y = (slope * x) + d;
        y2 = (slope * x2) + d;
        points.push_back(Point(x, y));
        points.push_back(Point(x2, y2));
    }
}


/* MOYEN DE REFACTOR TOUT CA */
int Ellipse::intersects(const Line & l, std::vector<Point>& points)
{

//    double x1 = this->pos.getX();
//    double y1 = this->pos.getY();
//    double xR = this->xRadius;
//    double yR = this->yRadius;
//    double x, y, d, x2, y2, slope;
//    double a, b, c;
//    double rho;
//    double lcm = umath::dlcm(xR*xR, yR*yR);
//    double lcmx = lcm / (yR*yR);
//    double lcmy = lcm / (xR*xR);

    double x1 = this->pos.getX();
    double y1 = this->pos.getY();
    double xR = this->xRadius;
    double yR = this->yRadius;
    double slope;
    double lcm = umath::dlcm(xR*xR, yR*yR);
    double lcmx = lcm / (yR*yR);
    double lcmy = lcm / (xR*xR);

    if (std::abs(std::fmod(l.getAngle(), M_PI)) == (M_PI_2))
    {
//        x = l.getPoint().getX();
//        c = (lcmy * x*x);
//        c -= (2 * lcmy * x*x1);
//        c += (lcmy * x1*x1);
//        c -= (lcm);
//        c += (lcmx * y1*y1);
//        a = (lcmx);
//        b = (-2* lcmx * y1);
//        rho = umath::rho(a, b ,c);

//        if (rho == 0)
//        {
//            y = -b / (2*a);
//            points.push_back(Point(x, y));
//        }
//        else if (rho > 0)
//        {
//            y = (-b + std::sqrt(rho)) / (2*a);
//            y2 = (-b - std::sqrt(rho)) / (2*a);
//            points.push_back(Point(x, y));
//            points.push_back(Point(x, y2)); // x2 ?
//        }
        methodeA(points, l.getPoint().getX(), x1, y1, lcm, lcmx, lcmy);
    }
    else
    {

//        x = l.getPoint().getX();
//        y = l.getPoint().getY();
        // la pente de la droite
        slope = Geometry::getSlope(l.getAngle());

        methodeB(points, l.getPoint().getX(), l.getPoint().getY(), x1, y1, slope, lcm, lcmx, lcmy);

//        // d est b dans y = ax + b
//        d = y - (slope * x);
//        c = -lcm;
//        c += lcmx * std::pow((d - y1), 2);
//        c += lcmy * x1 * x1;
//        a = lcmy + (lcmx * slope * slope);
//        b = -(lcmy * 2 * x1) + (lcmx * 2 * slope * (d-y1));
//        rho = umath::rho(a, b, c);

//        if (rho == 0)
//        {
//            x = -b / (2*a);
//            y = (slope * x) + d;
//            points.push_back(Point(x, y));
//        }
//        else if (rho > 0)
//        {
//            x = (-b + std::sqrt(rho)) / (2*a);
//            x2 = (-b - std::sqrt(rho)) / (2*a);
//            y = (slope * x) + d;
//            y2 = (slope * x2) + d;
//            points.push_back(Point(x, y));
//            points.push_back(Point(x2, y2));
//        }
    }

    return points.size();

}

int Ellipse::intersects(const LineSegment & ls, std::vector<Point>& points)
{
    Point start = ls.getStart();
    Point end = ls.getEnd();
    double rad = Geometry::getAngle(start, end);
    int intersections = intersects(Line(start, rad), points);

    if (intersections == 2 && !Geometry::isInBoundingBox(points.at(1), ls))
        points.erase(points.end());

    if (intersections == 1 && !Geometry::isInBoundingBox(points.at(0), ls))
        points.erase(points.begin());

    return points.size();
}

