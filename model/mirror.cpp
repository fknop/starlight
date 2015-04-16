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
      pivot_ {p}, length_(len), xpad_(xpad),
      x_min_ {min.x()}, x_max_ {max.x()}, y_min_ {min.y()}, y_max_ {max.y()},
      alpha_ {alpha}, alpha_min_ {alpha_min}, alpha_max_ {alpha_max},
      movable_{true}
{
    if (length_ <= 0 || (xpad_ < 0 && xpad_ > length_))
        throw std::string("La longueur et le décalage doivent etre positifs.");

    if (!check_pivot_range(p))
        throw std::string("Le pivot n'est pas dans les bornes autorisées.");

    if (!check_angle_range(alpha_))
        throw std::string("L'inclinaison du mirroir est invalide. "
                          "Elle n'est pas comprise entre les bornes.");
}


bool Mirror::check_angle_range(double a) const
{
    return (this->alpha_min_ == 0 && this->alpha_max_ == 0) ||
            (a >= this->alpha_min_ && a <= this->alpha_max_);
}

bool Mirror::check_pivot_range(const Point& p) const
{
    if (this->x_min_ == 0 && this->x_max_ == 0 && this->y_min_ == 0 && this->y_max_ == 0)
        return true;
    else
        return p.x() >= this->x_min_ && p.x() <= this->x_max_
                && p.y() >= this->y_min_ && p.y() <= this->y_max_;
}

void Mirror::rotate(double angle)
{

    this->movable_ = true;
    if (observers_.size() > 0)
    {
        std::ostringstream oss;
        oss << angle;
        std::vector<std::string> vec {oss.str()};
        notify_all(std::string("ASK_ROTATE"), vec);
    }


    if (this->movable_)
    {
        set_angle(this->alpha_ + angle);
        notify_all(std::string("ROTATE_MIRROR"));
    }
}

void Mirror::translate(const double x, const double y)
{
    this->movable_ = true;
    double new_x = this->pivot_.x() + x;
    double new_y = this->pivot_.y() + y;

    if (observers_.size() > 0)
    {
        std::ostringstream oss_x;
        std::ostringstream oss_y;
        oss_x << x;
        oss_y << y;
        std::vector<std::string> vec {oss_x.str(), oss_y.str()};

        notify_all(std::string("ASK_TRANSLATE"), vec);
    }

    if (this->movable_)
    {
        set_pivot(Point(new_x, new_y));
        notify_all(std::string("TRANSLATE_MIRROR"));
    }


}

LineSegment Mirror::to_line_segment() const
{
    double pivot_x = this->pivot_.x();
    double pivot_y = this->pivot_.y();
    double gx = pivot_x - (this->xpad_ * std::cos(this->alpha_));
    double gy = pivot_y + (xpad_ * sin(this->alpha_));
    double dx = pivot_x + ((this->length_ - xpad_) * std::cos(this->alpha_));
    double dy = pivot_y - ((this->length_ - xpad_) * std::sin(this->alpha_));
    return LineSegment(Point(gx, gy), Point(dx, dy));
}

std::ostream & operator<<(std::ostream & out, const Mirror & m)
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
     pivot_     == m.pivot_ &&
     length_    == m.length_ &&
     xpad_      == m.xpad_  &&
     x_min_     == m.x_min_ &&
     x_max_     == m.x_max_ &&
     y_min_     == m.y_min_ &&
     y_max_     == m.y_max_ &&
     alpha_     == m.alpha_ &&
     alpha_min_ == m.alpha_min_ &&
     alpha_max_ == m.alpha_max_;
}

