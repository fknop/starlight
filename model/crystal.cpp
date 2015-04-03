#include "crystal.h"

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
    return Ellipse(this->center_, this->rad_, this->rad_);
}

std::ostream& operator<<(std::ostream& out, const Crystal& c)
{
    out << "Crystal --- Center : " << c.center_ << " , Radius : " << c.rad_
        << " , Modifier : " << c.mod_;
    return out;
}
