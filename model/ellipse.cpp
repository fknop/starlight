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

/* MOYEN DE REFACTOR TOUT CA */
int Ellipse::intersects(const Line & l, std::vector<Point>& points)
{

    double x1 = this->pos.getX();
    double y1 = this->pos.getY();
    double xR = this->xRadius;
    double yR = this->yRadius;
    double d, slope;
    double a, b, c;
    double rho;
    double lcm = umath::dlcm(xR*xR, yR*yR);
    double lcmx = lcm / (yR*yR);
    double lcmy = lcm / (xR*xR);

    double x2, y2;
    double x = l.getPoint().getX();
    double y = l.getPoint().getY();

    if (std::abs(std::fmod(l.getAngle(), M_PI)) == (M_PI_2))
    {

        c = (lcmy * x*x);
        c += (lcmy * x1*x1);
        c += (lcmx * y1*y1);
        c -= (2 * lcmy * x*x1);
        c -= (lcm);

        a = (lcmx);
        b = (-2* lcmx * y1);
        rho = umath::rho(a, b ,c);

        if (rho == 0)
        {
            y = -b / (2*a);
            points.push_back(Point(x, y));
        }
        else if (rho > 0)
        {
            y = (-b + std::sqrt(rho)) / (2*a);
            points.push_back(Point(x, y));
            y = (-b - std::sqrt(rho)) / (2*a);
            points.push_back(Point(x, y));

        }

    }
    else
    {



        // E == ((x - x1)² / a²) + ((y- y1)² / b²) = 1
         // D == y = ax + b
        // x = (y-b) / a
       //  (((y-b)/a) - x1)² * lcmy +   lcmx * (y² + y1² - 2*y1*y) = lcm
        // (((y-b)² / a² + x1² - 2(y-b)/a ) * lcmy + lcmx ... = lcm
        // ((y² + b² - 2ay) / a + x1² - 2(y-b)/a )*lcmy + ...
        // lcmy *( y² + b² - 2ay + ax1² - 2y + 2b) + (a*lcmx *(y² + y1² - 2*y1*y = lcm * a

        // lcmy*y² + lcmy*b² - 2*lcmy*a*y + lcmy*a*x1² - lcmy*2*y + 2*lcmy*b
          //            + a*lcmx*y² + a* lcmx *y1² - 2*a*lcmx*y1*y - lcm * a = 0


        slope = Geometry::getSlope(l.getAngle()); // pente -> a dans y = ax + b
        d = y - (slope * x); // d -> b dans y = ax + b

        a = lcmy + (slope * lcmx);

        b = -(2 * lcmy * slope) - (2* lcmy) - (2 * slope * lcmx * y1);
        std::cout << b << std::endl;
        c = (lcmy * d * d);
        c += (lcmy * slope * x1 * x1);
        c += (2 * lcmy * d);
        c += (slope * lcmx * y1 * y1);
        c -= (lcm * slope);
        std::cout << c;
//        c = -lcm;
//        c += lcmx * std::pow((d - y1), 2);
//        c += lcmy * x1 * x1;
//        a = lcmy + (lcmx * slope * slope);
//        b = -(lcmy * 2 * x1) + (lcmx * 2 * slope * (d-y1));

        rho = umath::rho(a, b, c);
        std::cout << rho;
        if (rho == 0)
        {
            y = -b / (2*a);
            x =  (y - d) / slope;
            points.push_back(Point(x, y));
        }
        else if (rho > 0)
        {
            y = (-b + std::sqrt(rho)) / (2*a);
            x = (y - d) / slope;
            points.push_back(Point(x,y));

            y = (-b - std::sqrt(rho)) / (2*a);
            x = (y - d) / slope;
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

