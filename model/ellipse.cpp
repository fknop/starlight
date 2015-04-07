#include <cmath>

#include "ellipse.h"
#include "geometry.h"
#include "umath.h"
#include "constants.h"


Ellipse::Ellipse(const Point & p, double xRad, double yRad)
        : center_{p}, x_rad_(xRad), y_rad_(yRad)
{
    if (xRad <= 0 || yRad <= 0)
        throw std::string("Les rayons de l'ellipse doivent être strictement positifs.");
}

/*
 * cf. annexes du rapport du projet
 * pour les détails mathématiques
 * de cette méthode.
*/
int Ellipse::intersects(const Line& l, std::vector<Point>& points)
{
    double x = l.origin().x();
    double y = l.origin().y();
    double slope = Geometry::rad_to_slope(l.angle()); // pente -> a dans y = ax + b
    double d = y - (slope * x); // d -> b dans y = ax + b
    double x1 = this->center_.x();
    double y1 = this->center_.y();
    double xR = this->x_rad_;
    double yR = this->y_rad_;
    double a, b, c; // a, b, c dans rho = b² - ac
    double rho;     // rho
    double lcm = umath::dlcm(xR*xR, yR*yR); // ppcm de a² et b²
    double lcmx = lcm / (yR*yR);
    double lcmy = lcm / (xR*xR);

    bool verticalLine = umath::double_equals(std::abs(std::fmod(l.angle(), M_PI)), (M_PI_2));

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


    for (auto &i : points)
        std::cout << i << std::endl;


    return points.size();

}

int Ellipse::intersects(const LineSegment & ls, std::vector<Point>& points)
{
    Point start = ls.start();
    Point end = ls.end();
    double rad = Geometry::slope_to_rad(start, end);

    intersects(Line(start, rad), points);

    for (auto i = points.begin(); i != points.end(); )
    {
        if (ls.contains(*i))
            ++i;
        else
            i = points.erase(i);
    }

    return points.size();
}

