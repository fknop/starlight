#include <algorithm>

#include "constants.h"
#include "geometry.h"
#include "umath.h"
#include "linesegment.h"


double Geometry::rad_to_deg(double rad)
{
    return (rad * 180.0) / M_PI;
}

double Geometry::deg_to_rad(double degrees)
{
    return (degrees * M_PI) / 180;
}

double Geometry::slope_to_rad(const Point& p1, const Point& p2)
{
    double slope = rad_to_slope(p1, p2);
    return std::atan(slope);
}

double Geometry::slope_to_rad(double slope)
{
    return std::atan(slope);
}

double Geometry::rad_to_slope(const Point& p1, const Point& p2)
{
    return -((p1.y() - p2.y()) / (p1.x() - p2.x()));
}

double Geometry::rad_to_slope(double rad)
{
    return -tan(rad);
}

bool Geometry::is_on_good_side(const Line& l, const Point& p)
{
    double angle = l.angle();

    // Angle à 90°
    if (umath::equals(angle, M_PI_2)
            || umath::equals(angle, -M_PI_2_3))
            return umath::equals(p.x(), l.origin().x())
                && p.y() < l.origin().y();

    // Angle à 270°
    if (umath::equals(angle, M_PI_2_3)
            || umath::equals(angle, -M_PI_2))
            return p.y() > l.origin().y();

    // Angle à 180°
    if (umath::equals(angle, M_PI)
            || umath::equals(angle, -M_PI))
        return umath::equals(p.y(), l.origin().y())
                && p.x() < l.origin().x();

    // Angle à 0°
    if (umath::equals(angle, 0)
            || umath::equals(std::abs(angle), 2*M_PI))
        return umath::equals(p.y(), l.origin().y())
                && p.x() > l.origin().x();

    // Premier quadrant
    if ((angle > 0 && angle < M_PI_2) ||
            (angle < -M_PI_2_3 && angle > -(2*M_PI)))
        return p.x() > l.origin().x() + EPSILON && p.y() < l.origin().y() - EPSILON;

    // Deuxième quadrant
    else if ((angle > M_PI_2 && angle < M_PI) ||
             (angle < -M_PI && angle > -M_PI_2_3))
        return p.x() < l.origin().x() - EPSILON && p.y() < l.origin().y() - EPSILON;

    // Troisième quadrant
    else if ((angle > M_PI && angle < M_PI_2_3) ||
             (angle < -M_PI_2 && angle > -M_PI))
        return p.x() < l.origin().x() - EPSILON && p.y() > l.origin().y() + EPSILON;

    // Quatrième quadrant
    else
        return p.x() > l.origin().x() + EPSILON && p.y() > l.origin().y() + EPSILON;
}

bool Geometry::intersects(const Line& l1, const Line& l2, Point **intersection)
{
    double x, y,
           b1, b2,
           slope1, slope2;

    // Même droite ou parallèles
    if ((l1 == l2) ||
            (umath::equals(std::fmod(l1.angle(), M_PI),
                                  std::fmod(l2.angle(), M_PI))))
    {
        *intersection = nullptr;
        return false;
    }

    // Même origine donc intersection == origin
    if (l1.origin() == l2.origin())
    {
        *intersection = new Point(l1.origin());
        return true;
    }

   // Droites verticales
   if (umath::equals(std::abs(std::fmod(l1.angle(), M_PI)), (M_PI_2)))
   {
       vertical_line_intersection(l1, l2, intersection);
   }
   else if (umath::equals(std::abs(std::fmod(l2.angle(), M_PI)), (M_PI_2)))
   {
       vertical_line_intersection(l2, l1, intersection);
   }
   // droites non verticales
   else
   {
       slope1 = Geometry::rad_to_slope(l1.angle());
       slope2 = Geometry::rad_to_slope(l2.angle());
       b1     = l1.origin().y() - (slope1 * l1.origin().x());
       b2     = l2.origin().y() - (slope2 * l2.origin().x());
       x      = (b2 - b1) / (slope1 - slope2);
       y      = (slope2 * x) + b2;

       *intersection = new Point(x, y);
   }

   return true;
}

bool Geometry::intersects(const Line& line, const LineSegment& ls, Point **intersection)
{
    Point start = ls.start();
    Point end = ls.end();
    double rad = Geometry::slope_to_rad(start, end);

    if ((intersects(line, Line(start, rad), intersection)) &&
         (ls.contains(**intersection)))
            return true;


    delete *intersection;
    *intersection = nullptr;
    return false;
}

bool Geometry::intersects(const LineSegment& ls1, const LineSegment& ls2, Point **p)
{
    if (ls1 == ls2)
        return false;

    Point start1 = ls1.start();
    Point end1 = ls1.end();
    Point start2 = ls2.start();
    Point end2 = ls2.end();
    double rad1 = Geometry::slope_to_rad(start1, end1);
    double rad2 = Geometry::slope_to_rad(start2, end2);

    if (std::abs(rad1 - rad2) < 0.001)
        return false;

    Line l1(start1, rad1);
    Line l2(start2, rad2);

    return (intersects(l1, l2, p) &&
            ls1.contains(**p) && ls2.contains(**p));



}

int Geometry::intersects(const Ellipse& e, const Line& l,
               std::vector<Point> &points)
{
    double x = l.origin().x();
    double y = l.origin().y();
    double slope = Geometry::rad_to_slope(l.angle()); // pente -> a dans y = ax + b
    double d = y - (slope * x); // d -> b dans y = ax + b
    double x1 = e.center().x();
    double y1 = e.center().y();
    double xR = e.x_rad();
    double yR = e.y_rad();
    double a, b, c; // a, b, c dans rho = b² - ac
    double rho;     // rho
    double lcm = umath::dlcm(xR*xR, yR*yR); // ppcm de a² et b²
    double lcmx = lcm / (yR*yR);
    double lcmy = lcm / (xR*xR);

    bool horizontalLine = umath::equals(0, slope);
    bool verticalLine = umath::equals(std::abs(std::fmod(l.angle(), M_PI)), (M_PI_2));

    if (verticalLine)
    {
        a = (lcmx);
        b = (-2* lcmx * y1);
        c = (lcmy * x * x) + (lcmy * x1 * x1) +(lcmx * y1 * y1)
                - (2 * lcmy * x * x1) - (lcm);
    }
    else if (horizontalLine)
    {
        // y = k
        // lcmy(x - x1)² + lcmx(k - y1)² = lcm
        // lcmy(x² + x1² - 2*x*x1) + lcmx (k - y1)² = lcm
        // lcmy*x² + lcmy * x1² - lcmy * 2 * x * x1 + lcmx(k-y1)² - lcm = 0
        // a = lcmy
        // b = -2lcmy*x1
        // c = lcmy*x1² + lcmx(k-y1)² - lcm
        a = lcmy;
        b = -2 * lcmy * x1;
        c = (lcmy * x1 * x1) + (lcmx * (std::pow((y - y1), 2))) - lcm;
    }
    else
    {
        a = lcmy + (slope * slope * lcmx);
        b = -(2 * lcmy * d)
                - (2 * slope * lcmy * x1)
                - (2 * slope * slope * lcmx * y1);

        c = (lcmy * d * d)
                + (lcmy * slope * slope * x1 * x1)
                + (lcmy * 2 * slope * x1 * d)
                + (lcmx * slope * slope * y1 * y1)
                - (lcm * slope * slope);
    }

    rho = umath::rho(a, b, c);

    if (rho >= 0)
    {
        if (horizontalLine)
        {
            x = (-b + std::sqrt(rho)) / (2*a);

        }
        else
        {
            y = (-b + std::sqrt(rho)) / (2*a);
            x = verticalLine ? x : (y - d) / slope;
        }

        points.push_back(Point(x, y));

        if (rho > 0)
        {
            if (horizontalLine)
            {
                x = (-b - std::sqrt(rho)) / (2*a);
            }
            else
            {
                y = (-b - std::sqrt(rho)) / (2*a);
                x = verticalLine ? x : (y - d) / slope;
            }

            points.push_back(Point(x,y));
        }
    }

    return points.size();
}

int Geometry::intersects(const Ellipse& e, const LineSegment& ls,
               std::vector<Point>& points)
{
    Point start = ls.start();
    Point end = ls.end();
    double rad = Geometry::slope_to_rad(start, end);

    intersects(e, Line(start, rad), points);

    for (auto i = points.begin(); i != points.end(); )
    {
        if (ls.contains(*i))
            ++i;
        else
            i = points.erase(i);
    }

    return points.size();
}

int Geometry::intersects(const Rectangle& r, const Line& line,
               std::vector<Point>& points)
{
    /* On crée les 3 coins manquants du rectangle */
    Point bottomLeft(r.upper_left().x(),
                     r.upper_left().y() + r.height());

    Point upperRight(r.upper_left().x() + r.width(),
                     r.upper_left().y());

    Point bottomRight(r.upper_left().x() + r.width(),
                      r.upper_left().y() + r.height());

    /* On push les 4 côtés du rectangle dans un vecteur */
    std::vector<LineSegment> segments
    {
            LineSegment(r.upper_left(), upperRight),
            LineSegment(bottomLeft, bottomRight),
            LineSegment(r.upper_left(), bottomLeft),
            LineSegment(upperRight, bottomRight)
    };

    /* Pour chaque côté, s’il existe une intersection
     * on la push dans le vecteur de points, à moins que
     * l’intersection soit déjà présente */
    Point* p = nullptr;

    for (auto &i : segments) {
        if (intersects(line, i, &p) &&
                 std::find(points.begin(), points.end(), *p) == points.end())
            points.push_back(Point(*p));

        delete p;
    }

    return points.size();
}

int Geometry::intersects(const Rectangle& r, const LineSegment& ls,
               std::vector<Point>& points)
{
    Point start = ls.start();
    Point end = ls.end();
    double rad = Geometry::slope_to_rad(start, end);

    intersects(r, Line(start, rad), points);

    /* Enlève chaque point du vecteur qui n’est pas
     * sur le segment. */

    for (auto i = points.begin(); i != points.end(); )
    {
        if (ls.contains(*i))
            ++i;
        else
            i = points.erase(i);
    }

    return points.size();
}


bool Geometry::vertical_line_intersection(const Line& verticalL, const Line& line,
                                      Point** intersection)
{
    double x     = verticalL.origin().x();
    double slope = Geometry::rad_to_slope(line.angle());
    double b     = line.origin().y() - (slope * line.origin().x());
    double y     = (x * slope) + b;
    *intersection = new Point(x,y);
    return true;
}
