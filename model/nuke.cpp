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

bool Nuke::operator ==(const Nuke& n) const
{
    return
     pos_ == n.pos_ &&
     rad_ == n.rad_ &&
     lighted_up_ == n.lighted_up_;
}

void Nuke::translate(double x, double y)
{
    this->pos_.set_position(pos_.x() + x, pos_.y() + y);
    notify_all(std::string("TRANSLATE_NUKE"));
}
