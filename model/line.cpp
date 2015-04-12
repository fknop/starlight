#include <cmath>

#include "constants.h"
#include "geometry.h"
#include "line.h"



//Line::Line(const Point& origin, double angle)
//{
//   this->origin_ = origin;
//   this->angle_ = angle;
//}

//Line::Line(const Point& p1, const Point& p2)
//{
//   this->origin_ = p1;
//   this->angle_ = Geometry::slope_to_rad(p1, p2);
//}

//bool operator==(const Line& l1, const Line& l2)
//{
//    return l1.angle_ == l2.angle_ && l1.origin_ == l2.origin_;
//}

//double Line::get_x(double y) const
//{
//    if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (M_PI_2)))
//    {
//        return origin_.x();
//    }
//    else if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (0)))
//    {
//        return 1; // on décide de renvoyer 1 car x peut prendre n'importe quelle valeur
//    }
//    else
//    {
//        double slope = Geometry::rad_to_slope(angle_);
//        double b     = origin_.y() - (slope * origin_.x());
//        return ((y - b) / slope);
//    }
//}
//double Line::get_y(double x) const
//{
//    if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (0)))
//    {
//        return origin_.y();
//    }
//    else if (umath::equals(std::abs(std::fmod(this->angle_, M_PI)), (M_PI_2)))
//    {
//        return 1; // on décide de renvoyer 1 car y peut prendre n'importe quelle valeur.
//    }
//    else
//    {
//        double slope = Geometry::rad_to_slope(angle_);
//        double b     = origin_.y() - (slope * origin_.x());
//        return (slope * x) + b;
//    }
//}


Line::Line(double a, double b, double c)
{
    if (umath::equals(a, 0) && umath::equals(b, 0))
        throw std::string("a et b doivent tous les deux"
                "être différents de 0");

    a_ = a;
    b_ = b;
    c_ = c;
    alpha_ = -std::atan(slope());
}

Line::Line(const Point& a, const Point& b)
{
    a_ = a.y() - b.y();
    b_ = b.x() - a.x();

    if (umath::equals(a_, 0) && umath::equals(b_, 0))
        throw std::string("a et b doivent tous les deux"
                "être différents de 0");

    c_ = (a.x() * b.y()) - (a.y() * b.x());
    alpha_ = -std::atan(slope());
}

Line::Line(const Point& a, double alpha)
{
    if (umath::equals(std::fmod(std::abs(alpha), M_PI), M_PI_2))
    {
        a_ = 1; // On choisit que a = 1.
        b_ = 0;
        c_ = - a.x();
        // x = -c / a
    }
    else if (umath::equals(std::fmod(std::abs(alpha), M_PI), 0))
    {
        a_ = 0;
        b_ = 1; // On choisit que b = 1.
        c_ = - a.y();
        // y = -c / b donc -c.
    }
    else
    {
        a_ = std::tan(alpha);
        b_ = 1;
        c_ = (-a_ * a.x()) - (b_* a.y());
    }

    alpha_ = alpha;
}


