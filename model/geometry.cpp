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

bool Geometry::is_on_good_side(const Line& l, const Point& ref, const Point& p)
{
    double angle = l.alpha();

    // Angle à 90°
    if (umath::equals(angle, M_PI_2)
            || umath::equals(angle, -M_PI_2_3))
            return umath::equals(p.x(), ref.x())
                && p.y() < ref.y();

    // Angle à 270°
    if (umath::equals(angle, M_PI_2_3)
            || umath::equals(angle, -M_PI_2))
            return umath::equals(p.x(), ref.x()) && p.y() > ref.y();

    // Angle à 180°
    if (umath::equals(angle, M_PI)
            || umath::equals(angle, -M_PI))
        return umath::equals(p.y(), ref.y())
                && p.x() < ref.x();

    // Angle à 0°
    if (umath::equals(angle, 0)
            || umath::equals(std::abs(angle), 2*M_PI))
        return umath::equals(p.y(), ref.y())
                && p.x() > ref.x();

    // Premier quadrant
    if ((angle > 0 && angle < M_PI_2) ||
            (angle < -M_PI_2_3 && angle > -(2*M_PI)))
        return p.x() > ref.x() + EPSILON && p.y() < ref.y() - EPSILON;

    // Deuxième quadrant
    else if ((angle > M_PI_2 && angle < M_PI) ||
             (angle < -M_PI && angle > -M_PI_2_3))
        return p.x() < ref.x() - EPSILON && p.y() < ref.y() - EPSILON;

    // Troisième quadrant
    else if ((angle > M_PI && angle < M_PI_2_3) ||
             (angle < -M_PI_2 && angle > -M_PI))
        return p.x() < ref.x() - EPSILON && p.y() > ref.y() + EPSILON;

    // Quatrième quadrant
    else
        return p.x() > ref.x() + EPSILON && p.y() > ref.y() + EPSILON;
}

bool Geometry::intersects(const Line& l1, const Line& l2, Point& point, bool& is_point)
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

        if (umath::equals(x , y))
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

bool Geometry::intersects(const Line& line, const LineSegment& ls, Point& point, bool& is_point)
{
    Point start = ls.start();
    Point end = ls.end();

    bool do_intersect = intersects(line, Line(start, end), point, is_point);


    if (do_intersect && !is_point)
        return true;
    else if (do_intersect && is_point && ls.contains(point))
        return true;
    else
        return false;

}

bool Geometry::intersects(const LineSegment& ls1, const LineSegment& ls2, Point& point, bool& is_point)
{
    if (ls1 == ls2)
    {
        is_point = false;
        return true;
    }

    Line l1(ls1.start(), ls1.end());
    Line l2(ls2.start(), ls2.end());

    bool do_intersect = intersects(l1, l2, point, is_point);

    if (do_intersect && !is_point)
        return true;

    if (do_intersect && is_point && ls1.contains(point) && ls2.contains(point))
        return true;
    else
        return false;
}


//bool Geometry::intersects(const Line& l1, const Line& l2, Point **intersection)
//{
//    double x, y,
//           b1, b2,
//           slope1, slope2;

//    double l1_angle = std::fmod(l1.angle(), M_PI);
//    double l2_angle = std::fmod(l2.angle(), M_PI);
//    bool l1_vertical   = umath::equals(std::abs(l1_angle), M_PI_2);
//    bool l1_horizontal = umath::equals(std::abs(l1_angle), 0);
//    bool l2_vertical   = umath::equals(std::abs(l2_angle), M_PI_2);
//    bool l2_horizontal = umath::equals(std::abs(l2_angle), 0);

//    std::cout << "l1 angle : " << l1_angle << std::endl;
//    std::cout << "l2 angle : " << l2_angle << std::endl;

//    // Même droite
//    if ((l1_vertical && l2_vertical && !umath::equals(l1.get_x(0), l2.get_x(0)))
//            || (l1_horizontal && l2_horizontal && !umath::equals(l1.get_y(0), l2.get_y(0))))
//    {
//        std::cout << "PAS OK?";
//        *intersection = nullptr;
//        return false;
//    }
//    else if (l1_vertical && l2_vertical && umath::equals(l1.get_x(0), l2.get_x(0)))
//    {
//        *intersection = new Point(l2.origin());
//        return true;
//    }
//    else if (l1_horizontal && l2_horizontal && umath::equals(l1.get_y(0), l2.get_y(0)))
//    {
//        *intersection = new Point(l2.origin());
//        return true;
//    }
//    else if (umath::equals(l1_angle, l2_angle) && umath::equals(l1.get_x(0), l2.get_x(0)))
//    {
//        std::cout << "OK";
//        *intersection = new Point(l2.origin());
//        return true;
//    }

//    // Même origine donc intersection == origin
//    if (l1.origin() == l2.origin())
//    {
//        *intersection = new Point(l1.origin());
//        return true;
//    }

//   // Droites verticales
//   if (umath::equals(std::abs(std::fmod(l1.angle(), M_PI)), (M_PI_2)))
//   {
//       vertical_line_intersection(l1, l2, intersection);
//   }
//   else if (umath::equals(std::abs(std::fmod(l2.angle(), M_PI)), (M_PI_2)))
//   {
//       vertical_line_intersection(l2, l1, intersection);
//   }
//   // droites non verticales
//   else
//   {
//       slope1 = Geometry::rad_to_slope(l1.angle());
//       slope2 = Geometry::rad_to_slope(l2.angle());
//       b1     = l1.origin().y() - (slope1 * l1.origin().x());
//       b2     = l2.origin().y() - (slope2 * l2.origin().x());
//       x      = (b2 - b1) / (slope1 - slope2);
//       y      = (slope2 * x) + b2;

//       *intersection = new Point(x, y);
//   }

//   return true;
//}

//bool Geometry::intersects(const Line& line, const LineSegment& ls, Point **intersection)
//{
//    Point start = ls.start();
//    Point end = ls.end();
//    double rad = Geometry::slope_to_rad(start, end);

//    if ((intersects(line, Line(start, rad), intersection)) &&
//         (ls.contains(**intersection)))
//            return true;


//    delete *intersection;
//    *intersection = nullptr;
//    return false;
//}

//bool Geometry::intersects(const LineSegment& ls1, const LineSegment& ls2, Point **p)
//{
//    if (ls1 == ls2)
//    {
//        *p = new Point(ls1.start());
//        return true;
//    }

//    Point start1 = ls1.start();
//    Point end1 = ls1.end();
//    Point start2 = ls2.start();
//    Point end2 = ls2.end();
//    double rad1 = Geometry::slope_to_rad(start1, end1);
//    double rad2 = Geometry::slope_to_rad(start2, end2);

//    Line l1(start1, rad1);
//    Line l2(start2, rad2);

//    return (intersects(l1, l2, p) &&
//            ls1.contains(**p) && ls2.contains(**p));



//}

int Geometry::intersects(const Ellipse& e, const Line& l,
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
        // ax + by + c = 0
        // y = -ax/b - c/b
        // lcmy*x² + lcmy*x1² - 2*lcmy*x*x1
        //  + (slope*x - d + y1)²

        // lcmy*x² + lcmy*x1² - 2*lcmy*x*x1
        // (lcmx*slope²*x² + lcmx*(d+y1)² - 2*lcmx*slope*x*(d+y1) -lcm = 0
        // a = lcmy + lcmx*slope*slope
        // b = -2*lcmy*x1 - 2*lcmx*slope*(d+y1)

//        a = lcmy + (slope*slope*lcmx);
//        b = -2*lcmy*x1 -2*lcmx*slope*(d+y1);
//        c = (lcmy*x1*x1) + (lcmx*std::pow((d+y1),2)) - lcm;
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

int Geometry::intersects(const Ellipse& e, const LineSegment& ls,
               std::vector<Point>& points)
{
    intersects(e, Line(ls.start(), ls.end()), points);

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
    Point p;
    bool is_point;
    for (auto &i : segments) {
        if (intersects(line, i, p, is_point) && is_point &&
                 std::find(points.begin(), points.end(), p) == points.end())
            points.push_back(Point(p));


    }

    return points.size();
}

int Geometry::intersects(const Rectangle& r, const LineSegment& ls,
               std::vector<Point>& points)
{
    intersects(r, Line(ls.start(), ls.end()), points);

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

