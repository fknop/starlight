#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

#include "model/mirror.h"


Mirror::Mirror(const Point& p, double xpad, double len, double alpha)
    : Mirror {p, xpad, len, alpha, {.0, .0}, {.0, .0}, .0, .0} {}

Mirror::Mirror(const Point& p, double xpad, double len, double alpha, const Point& min,
               const Point& max, double alpha_min, double alpha_max)
    : Element(Element::Type::MIRROR),
      pivot_ {p}, length_(len),
      x_min_ {min.x()}, x_max_ {max.x()}, y_min_ {min.y()}, y_max_ {max.y()},
      alpha_ {alpha}, alpha_min_ {alpha_min}, alpha_max_ {alpha_max},
      movable_{true}
{

    if (length_ <= 0)
        throw std::string("La longueur doit être positive.");

    set_xpad(xpad);

    if (!check_pivot_range(p))
        throw std::string("Le pivot n'est pas dans les bornes autorisées.");

    if (!check_angle_range(alpha_))
        throw std::string("L'inclinaison du mirroir est invalide. "
                          "Elle n'est pas comprise entre les bornes.");


}


bool Mirror::check_angle_range(double a) const
{
    return (alpha_min_ == 0 && alpha_max_ == 0) ||
            (a >= alpha_min_ && a <= alpha_max_);
}

bool Mirror::check_pivot_range(const Point& p) const
{
    if (x_min_ == 0 && x_max_ == 0 && y_min_ == 0 && y_max_ == 0)
        return true;
    else
        return p.x() >= x_min_ && p.x() <= x_max_
                && p.y() >= y_min_ && p.y() <= y_max_;
}

void Mirror::rotate(double angle)
{

    movable_ = true;
    if (observers_.size() > 0)
    {
        std::ostringstream oss;
        oss << angle;
        std::vector<std::string> vec {oss.str()};
        notify_all(std::string("ASK_ROTATE"), vec);
    }


    if (movable_)
    {
        set_angle(alpha_ + angle);
        notify_all(std::string("ROTATE_MIRROR"));
    }
}

void Mirror::translate(const double x, const double y)
{
    movable_ = true;
    double new_x = pivot_.x() + x;
    double new_y = pivot_.y() + y;

    if (observers_.size() > 0)
    {
        std::ostringstream oss_x;
        std::ostringstream oss_y;
        oss_x << x;
        oss_y << y;
        std::vector<std::string> vec {oss_x.str(), oss_y.str()};

        notify_all(std::string("ASK_TRANSLATE"), vec);
    }

    if (movable_)
    {
        set_pivot(Point(new_x, new_y));
        notify_all(std::string("TRANSLATE_MIRROR"));
    }


}

LineSegment Mirror::to_line_segment() const
{
//    double x1 = ((start_.x() * std::cos(rotation)) -
//                 (start_.y() *std::sin(rotation)));

//    double y1 = (start_.x() * std::sin(rotation)) +
//                (start_.y() * std::cos(rotation));

//    double x2 = ((end_.x() * std::cos(rotation)) -
//                (end_.y() *std::sin(rotation)));

//    double y2 = (end_.x() * std::sin(rotation)) +
//                (end_.y() * std::cos(rotation));
    double pivot_x = pivot_.x();
    double pivot_y = pivot_.y();
    double gx = pivot_x - (xpad_ * std::cos(alpha_));
    double gy = pivot_y + (xpad_ * sin(alpha_));
    double dx = pivot_x + ((length_ - xpad_) * std::cos(alpha_));
    double dy = pivot_y - ((length_ - xpad_) * std::sin(alpha_));
    return LineSegment(Point(gx, gy), Point(dx, dy));
}

std::ostream& operator<<(std::ostream& out, const Mirror& m)
{
    out << "Mirror --- Pivot : " << m.pivot_ << " , Length : " << m.length_
        << " , x-pad : " << m.xpad_ << ", Angle : " << m.alpha_ <<
           " , Angle range : [" << m.alpha_min_ << "," << m.alpha_max_ << "]" <<
           "Pivot range : [(" << m.x_min_ << "," << m.y_min_ << "),(" << m.x_max_ <<
           "," << m.y_max_ << ")]";
    return out;
}

bool Mirror::operator ==(const Mirror& m) const
{
    return
     pivot_ == m.pivot_ &&
     umath::equals(this->length_   , m.length_) &&
     umath::equals(this->xpad_     , m.xpad_) &&
     umath::equals(this->x_min_    , m.x_min_) &&
     umath::equals(this->x_max_    , m.x_max_) &&
     umath::equals(this->y_min_    , m.y_min_) &&
     umath::equals(this->y_max_    , m.y_max_) &&
     umath::equals(this->alpha_    , m.alpha_) &&
     umath::equals(this->alpha_min_, m.alpha_min_) &&
     umath::equals(this->alpha_max_, m.alpha_max_);
}

