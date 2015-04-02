#include "nuke.h"


Nuke::Nuke(const Point & p, double r) : Element(Element::Type::NUKE),
    pos_ {p}, rad_ {r}
{
    if (r <= 0)
        throw std::string("Le rayon doit être strictement supérieur à 0");

}

const Point& Nuke::position() const
{
    return pos_;
}

double Nuke::radius() const
{
    return rad_;
}

bool Nuke::is_lighted_up() const
{
    return light_;
}

void Nuke::set_lighted_up(bool q)
{
    light_ = q;
}

Ellipse Nuke::to_ellipse()
{
    return Ellipse(this->pos_, this->rad_, this->rad_);
}

std::ostream & operator<<(std::ostream & out, const Nuke & s)
{
    out << "Nuke --- Position : " << s.pos_ << " , Radius : " << s.rad_ <<
        " On : " << s.light_;
    return out;
}
