#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

#include "model/mirror.h"


Mirror::Mirror(const Point & p, double x, double len, double a)
    : Mirror {p, x, len, a, {.0, .0}, {.0, .0}, .0, .0} {}

Mirror::Mirror(const Point & p, double x, double len, double a, Point pm,
               Point pM, double am, double aM)
    : Element(Element::Type::MIRROR),
      pivot_ {p}, length_(len), xpad_(x), x_min_ {pm.x()}, x_max_ {pM.x()},
      y_min_ {pm.y()}, y_max_ {pM.y()}, alpha_ {a}, alpha_min_ {am},
      alpha_max_ {aM}, movable_{true}
{
    if (length_ <= 0 || xpad_ < 0)
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

bool Mirror::check_pivot_range(const Point & p) const
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
        notify_all("ASK_ROTATE", vec);
    }


    if (this->movable_)
    {
        set_angle(this->alpha_ + angle);
        notify_all(std::string("ROTATE_MIRROR"));
    }
}

void Mirror::translate(double x, double y)
{
    this->movable_ = true;
    double newX = this->pivot_.x() + x;
    double newY = this->pivot_.y() + y;

    if (observers_.size() > 0)
    {
        std::ostringstream ossx;
        std::ostringstream ossy;
        ossx << x;
        ossy << y;
        std::vector<std::string> vec {ossx.str(), ossy.str()};

        notify_all("ASK_TRANSLATE", vec);
    }

    if (this->movable_)
    {
        set_pivot(Point(newX, newY));
        notify_all(std::string("TRANSLATE_MIRROR"));
    }


}

LineSegment Mirror::to_line_segment() const
{
    double pivotX = this->pivot_.x();
    double pivotY = this->pivot_.y();
    double gx = pivotX - (this->xpad_ * std::cos(this->alpha_));
    double gy = pivotY + (xpad_ * sin(this->alpha_));
    double dx = pivotX + ((this->length_ - xpad_) * std::cos(this->alpha_));
    double dy = pivotY - ((this->length_ - xpad_) * std::sin(this->alpha_));  
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

