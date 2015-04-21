#include <cmath>
#include <algorithm>

#include "model/line.h"
#include "model/linesegment.h"
#include "model/point.h"
#include "model/ellipse.h"
#include "model/rectangle.h"

#include "utils/umath.h"
#include "utils/constants.h"

double umath::dgcd(double a, double b)
{
    if (b == 0)
        return a;
    else
        return dgcd(b, std::fmod(a, b));
}

double umath::dlcm(double a, double b)
{
    return std::abs(a * b) / dgcd(a, b);
}

double umath::rho(double a, double b, double c)
{
    return (b*b) - (4*a*c);
}

bool umath::equals(double a, double b)
{
    return std::abs(a - b) < EPSILON;
}

bool umath::equals_inf(double a)
{
    return (a == INF || a == -INF);

}

bool umath::angle_equals(double a, double b)
{
    a = std::fmod(a, 2*PI);
    b = std::fmod(b, 2*PI);
    if (a < 0)
        a = (2*PI) + a;
    if (b < 0)
        b = (2*PI) + b;

    return umath::equals(a, b);
}

bool umath::angle_equals_pi(double a, double b)
{
    a = std::fmod(a, PI);
    b = std::fmod(b, PI);
    if (a < 0)
        a = a + PI;
    if (b < 0)
        b = b + PI;

    // Pour la précision...
    if (a > 3.14 && a < PI)
        a = 0;
    if (b > 3.14 && b < PI)
        b = 0;

    return umath::equals(a, b);
}


double umath::rad_to_deg(double rad)
{
    return (rad * 180.0) / PI;
}

double umath::deg_to_rad(double degrees)
{
    return (degrees * PI) / 180;
}

double umath::points_to_rad(const Point& p1, const Point& p2)
{
    double slope = points_to_slope(p1, p2);
    return slope_to_rad(slope);
}

double umath::slope_to_rad(double slope)
{
    return -std::atan(slope);
}

double umath::points_to_slope(const Point& p1, const Point& p2)
{
    return ((p1.y() - p2.y()) / (p1.x() - p2.x()));
}

double umath::rad_to_slope(double rad)
{
    return -tan(rad);
}

bool umath::is_on_good_side(const Line& l, const Point& ref, const Point& p)
{
    double angle = l.alpha();

    std::cout << "p : " << p << std::endl;
    std::cout << "ref : " << ref << std::endl;

    // Angle à 90°
       if (umath::angle_equals(angle, PI_2))
               return umath::equals(p.x(), ref.x())
                   && p.y() < ref.y();

       // Angle à 270°
       if (umath::angle_equals(angle, PI_2_3))
               return umath::equals(p.x(), ref.x()) && p.y() > ref.y();

       // Angle à 180°
       if (umath::angle_equals(angle, PI))
           return umath::equals(p.y(), ref.y())
                   && p.x() < ref.x();

       // Angle à 0°
       if (umath::angle_equals(angle, 0))
           return umath::equals(p.y(), ref.y())
                   && p.x() > ref.x();

       // Premier quadrant
       if ((angle > 0 && angle < PI_2) ||
               (angle < -PI_2_3 && angle > -(2*PI)))
           return p.x() > ref.x() + EPSILON && p.y() < ref.y() - EPSILON;

       // Deuxième quadrant
       else if ((angle > PI_2 && angle < PI) ||
                (angle < -PI && angle > -PI_2_3))
           return p.x() < ref.x() - EPSILON && p.y() < ref.y() - EPSILON;

       // Troisième quadrant
       else if ((angle > PI && angle < PI_2_3) ||
                (angle < -PI_2 && angle > -PI))
           return p.x() < ref.x() - EPSILON && p.y() > ref.y() + EPSILON;

       // Quatrième quadrant
       else
           return p.x() > ref.x() + EPSILON && p.y() > ref.y() + EPSILON;
}

bool umath::intersects(const Line& l1, const Line& l2, Point& point, bool& is_point)
{
    double x, y;

    if (l1 == l2)
    {
        is_point = false;
        return true;
    }

    if (l1.parallel(l2)) // deux droites V ou H
    {

        // x et y ci dessous ne représentent pas
        // les coordonnées x et y

        if (l1.vertical()) // droites verticales
        {
            x = l1.get_x(0);
            y = l2.get_x(0);
        }
        else if (l1.horizontal())// droites horizontales
        {
            x = l1.get_y(0);
            y = l2.get_y(0);
        }
        else // droites parallèles.
        {
            x = -l1.c() / l1.b();
            y = -l2.c() / l2.b();
        }

        if (std::abs(x - y) < 0.5) // On avance de 1 en 1
                                   // une précision d'epsilon
                                   // n'est pas possible.
        {
            is_point = false;
            return true;
        }
        else
        {
            is_point = false;
            return false;
        }
    }

    if (l1.vertical() || l2.vertical() || l1.horizontal() || l2.horizontal())
    {
        if (l1.horizontal() && l2.vertical())
        {
            x = l2.get_x(0);
            y = l1.get_y(0);
        }
        else if (l2.horizontal() && l1.vertical())
        {
            x = l1.get_x(0);
            y = l2.get_y(0);
        }
        else if (l1.vertical())
        {
            x = l1.get_x(0);
            y = l2.get_y(x);
        }
        else if (l2.vertical())
        {
            x = l2.get_x(0);
            y = l1.get_y(x);
        }
        else if (l1.horizontal())
        {
            y = l1.get_y(0);
            x = l2.get_x(y);
        }
        else if (l2.horizontal())
        {
            y = l2.get_y(0);
            x = l1.get_x(y);
        }
    }
    else
    {
        x = ((l1.c() * l2.b()) - (l2.c() * l1.b())) /
                ((l2.a() * l1.b()) - (l1.a() * l2.b()));
        y = l1.get_y(x);
    }

    point = Point(x, y);
    is_point = true;
    return true;
}

bool umath::intersects(const Line& line, const LineSegment& ls, Point& point, LineSegment& segment, bool& is_point)
{
    bool do_intersect = intersects(line, ls.to_line(), point, is_point);

    if (do_intersect && !is_point)
    {
        segment = ls;
        return true;
    }

    else if (do_intersect && is_point && ls.contains(point))
    {
        return true;
    }
    else
    {
        is_point = false; // Si ls ne contient pas le point, il faut passer is_point à false.
        return false;
    }

}

bool umath::intersects(const LineSegment& ls1, const LineSegment& ls2, Point& point, LineSegment& segment, bool& is_point)
{
    if (ls1 == ls2)
    {
        is_point = false;
        segment = ls1;
        return true;
    }

    bool do_intersect = intersects(ls1.to_line(), ls2.to_line(), point, is_point);

    if (do_intersect && !is_point)
    {
        if (ls1.start() == ls2.end())
        {
            is_point = true;
            point = ls1.start();
        }
        else if (ls2.start() == ls1.end())
        {
            is_point = true;
            point = ls2.start();
        }
        else if (ls1.contains(ls2.end()) && ls1.contains(ls2.start()))
        {
            segment = ls2;
        }
        else if (ls2.contains(ls1.start()) && ls2.contains(ls1.end()))
        {
            segment = ls1;
        }
        else if (ls1.contains(ls2.start()))
        {
            segment = LineSegment(ls2.start(), ls1.end());
        }
        else if (ls1.contains(ls2.end()))
        {
            segment = LineSegment(ls1.start(), ls2.end());
        }
        else
        {
            return false;
        }

        return true;
    }

    if (do_intersect && is_point && ls1.contains(point) && ls2.contains(point))
    {
        return true;
    }
    else
    {
        is_point = false;
        return false;
    }
}

// Voir annexe projet pour plus de détails
int umath::intersects(const Ellipse& e, const Line& l,
               std::vector<Point>& points)
{
    double x;
    double y;
    double slope = l.slope();
    double d = -l.c() / l.b();
    double x1 = e.center().x();
    double y1 = e.center().y();
    double xR = e.x_rad();
    double yR = e.y_rad();
    double a, b, c; // a, b, c dans rho = b² - ac
    double rho;     // rho
    double lcm = umath::dlcm(xR*xR, yR*yR); // ppcm de a² et b²
    double lcmx = lcm / (yR*yR);
    double lcmy = lcm / (xR*xR);


    // ax + by + c = 0
    // lcmy(x - x1)² + lcmx(y - y1)² = lcm
    // ax + c = 0
    // x = -c / a
    // x²*lcmy + x1²*lcmy - 2*lcmy*x*x1 + lcmx*y² + lcmx*y1² - 2*lcmx*y*y1 - lcm = 0
    if (l.vertical())
    {
        x = l.get_x(0); // = -c/a
        a = (lcmx);
        b = (-2 * lcmx * y1);
        c = (lcmy * std::pow((x - x1), 2)) + (lcmx * y1 *y1) - (lcm);
    }
    else if (l.horizontal())
    {
        // by + c = 0
        // y = -c / b
        // lcmy*x² + lcmy*x1² - 2*lcmy*x*x1
        //  + lcmx*y² + lcmx*y1² - 2*lcmx*y*y1 - lcm = 0
        y = l.get_y(0);
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
        if (l.horizontal())
        {
            x = (-b + std::sqrt(rho)) / (2*a);
        }
        else
        {
            y = (-b + std::sqrt(rho)) / (2*a);
            x = l.get_x(y);
        }

        points.push_back(Point(x, y));

        if (rho > 0)
        {
            if (l.horizontal())
            {
                x = (-b - std::sqrt(rho)) / (2*a);
            }
            else
            {
                y = (-b - std::sqrt(rho)) / (2*a);
                x = l.get_x(y);
            }

            points.push_back(Point(x,y));
        }
    }

    return points.size();
}

int umath::intersects(const Ellipse& e, const LineSegment& ls,
               std::vector<Point>& points)
{
    intersects(e, ls.to_line(), points);

    for (auto i = points.begin(); i != points.end(); )
    {
        if (ls.contains(*i))
            ++i;
        else
            i = points.erase(i);
    }

    return points.size();
}

int umath::intersects(const Rectangle& r, const Line& line,
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
    Point p;
    LineSegment ls;
    bool is_point;
    for (auto &i : segments) {
        if (intersects(line, i, p, ls, is_point) && is_point &&
                 std::find(points.begin(), points.end(), p) == points.end())
            points.push_back(Point(p));


    }

    return points.size();
}

int umath::intersects(const Rectangle& r, const LineSegment& ls,
               std::vector<Point>& points)
{
    intersects(r, ls.to_line(), points);

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
