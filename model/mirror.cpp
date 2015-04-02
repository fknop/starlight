#include <cmath>
#include <iostream>

#include "mirror.h"


Mirror::Mirror(const Point & p, double x, double len, double a)
    : Mirror {p, x, len, a, {.0, .0}, {.0, .0}, .0, .0}
{

}

Mirror::Mirror(const Point & p, double x, double len, double a, Point pm,
               Point pM, double am, double aM)
    : Element(Element::Type::MIRROR),
      pivot_ {p}, length_(len), xpad_(x), xMin_ {pm.x()}, xMax_ {pM.x()},
      yMin_ {pm.y()}, yMax_ {pM.y()}, alpha_ {a}, alphaMin_ {am},
      alphaMax_ {aM}
{
    if (length_ <= 0 || xpad_ < 0)
        throw std::string("La longueur et le décalage doivent etre positifs.");

   if (!check_pivot_range(p))
       throw std::string("Le pivot n'est pas dans les bornes autorisées.");

    if (!check_angle_range(alpha_))
        throw std::string("L'inclinaison du mirroir est invalide. "
        "Elle n'est pas comprise entre les bornes.");
}

const Point & Mirror::pivot() const
{
    return pivot_;
}

double Mirror::length() const
{
    return length_;
}

double Mirror::x_pad() const
{
    return xpad_;
}

double Mirror::angle() const
{
    return alpha_;
}

double Mirror::min_angle() const
{
    return alphaMin_;
}

double Mirror::max_angle() const
{
    return alphaMax_;
}

Point Mirror::min_pivot() const
{
    return Point {xMin_, yMin_};
}

Point Mirror::max_pivot() const
{
    return Point {xMax_, yMax_};
}

bool Mirror::set_pivot(const Point & p)
{
    bool r {check_pivot_range(p)};
    if (r)
        pivot_ = p;
    return r;
}

bool Mirror::set_angle(double a)
{
    bool r {check_angle_range(a)};
    if (r)
        alpha_ = a;
    return r;
}

bool Mirror::check_angle_range(double a) const
{
    return (alphaMin_ == 0 && alphaMax_ == 0) ||
            (a >= alphaMin_ && a <= alphaMax_);
}

bool Mirror::check_pivot_range(const Point & p) const
{
    if (xMin_ == 0 && xMax_ == 0 && yMin_ == 0 && yMax_ == 0)
        return true;

    else if (xMin_ == 0 && xMax_ == 0)
        return p.y() >= yMin_ && p.y() <= yMax_;

    else if (yMin_ == 0 && yMax_ == 0)
        return p.x() >= xMin_ && p.x() <= xMax_;

    else
        return p.x() >= xMin_ && p.x() <= xMax_
                && p.y() >= yMin_ && p.y() <= yMax_;

}

void Mirror::rotate(double angle)
{
    if (!set_angle(alpha_ + angle))
    {
        if (alpha_ + angle >= alphaMax_)
            set_angle(alphaMax_);
        else
            set_angle(alphaMin_);
    }
}

void Mirror::translate(double x, double y)
{
    double newX = pivot_.x() + x;
    double newY = pivot_.y() + y;
    if (!set_pivot(Point(newX, newY)))
    {
        if (newX < xMin_)
            newX = xMin_;
        else if (newX > xMax_)
            newY = xMax_;

        if (newY < yMin_)
            newY = yMin_;
        else if (newY > yMax_)
            newY = yMax_;

        set_pivot(Point(newX, newY));
    }
}

LineSegment Mirror::to_line_segment()
{
    double pivotX = this->pivot_.x();
    double pivotY = this->pivot_.y();
    double gx = pivotX - (this->xpad_ * std::cos(this->alpha_));
    double gy = pivotY - (xpad_ * sin(this->alpha_));
    double dx = pivotX + ((this->length_ - xpad_) * std::cos(this->alpha_));
    double dy = pivotY + ((this->length_ - xpad_) * std::sin(this->alpha_));
    Point start(gx, gy);
    Point end(dx, dy);

    return LineSegment(start, end);
}

std::ostream & operator<<(std::ostream & out, const Mirror & m)
{
    out << "Mirror --- Pivot : " << m.pivot_ << " , Length : " << m.length_
        << " , x-pad : " << m.xpad_ << ", Angle : " << m.alpha_ <<
           " , Angle range : [" << m.alphaMin_ << "," << m.alphaMax_ << "]" <<
           "Pivot range : [(" << m.xMin_ << "," << m.yMin_ << "),(" << m.xMax_ <<
           "," << m.yMax_ << ")]";
    return out;
}
