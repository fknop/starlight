#include "nuke.h"


Nuke::Nuke(const Point& p, double r) : Element(Element::Type::NUKE),
    pos_ {p}, rad_ {r}
{
    if (r <= 0)
        throw std::string("Le rayon doit être strictement supérieur à 0");

}

Ellipse Nuke::to_ellipse()
{
    return Ellipse(this->pos_, this->rad_, this->rad_);
}

std::ostream& operator<<(std::ostream& out, const Nuke& s)
{
    out << "Nuke --- Position : " << s.pos_ << " , Radius : " << s.rad_ <<
        " On : " << s.lighted_up_;
    return out;
}
