#include "model/crystal.h"


Crystal::Crystal(const Point& p, double r, int m) :
    Element(Element::Type::CRYSTAL),
    center_ {p}, rad_ {r}, mod_ {m}
{
    if (r <= 0)
        throw std::string("Le rayon doit être strictement strictement positif");
}

Crystal::Crystal(const Crystal& crystal) : Element(Element::Type::CRYSTAL)
{
    this->center_ = crystal.center_;
    this->mod_ = crystal.mod_;
    this->rad_ = crystal.rad_;
}

Ellipse Crystal::to_ellipse() const
{
    return Ellipse(center_, rad_, rad_);
}

std::ostream& operator<<(std::ostream& out, const Crystal& c)
{
    out << "Crystal --- Center : " << c.center_ << " , Radius : " << c.rad_
        << " , Modifier : " << c.mod_;
    return out;
}

bool Crystal::operator ==(const Crystal& c) const
{
    return
     this->center_ == c.center_ &&
     umath::equals(this->rad_, c.rad_ )&&
     umath::equals(this->mod_, c.mod_);
}

void Crystal::translate(const double x, const double y)
{
    center_.set_position(center_.x() + x, center_.y() + y);
    notify_all(std::string("TRANSLATE_CRYSTAL"));
}
