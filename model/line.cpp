#include <cmath>

#include "model/line.h"

#include "utils/constants.h"
#include "utils/umath.h"


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
    if (umath::angle_equals_pi(alpha, PI_2))
    {
        a_ = 1; // On choisit que a = 1.
        b_ = 0;
        c_ = - a.x();
        // x = -c / a donc -c
    }
    else if (umath::angle_equals_pi(alpha, 0))
    {
        a_ = 0;
        b_ = 1; // On choisit que b = 1.
        c_ = - a.y();
        // y = -c / b donc -c.
    }
    else
    {
        a_ = std::tan(alpha);
        b_ = 1; // On choisit que b = 1, pente = -a/b donc -a
        c_ = (-a_ * a.x()) - (b_* a.y());
    }

    alpha_ = alpha;
}
