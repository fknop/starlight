#include "model/dest.h"


Dest::Dest(const Point& p, double e) : Element(Element::Type::DEST),
                                       pos_ {p}, edge_ {e}
{
    if (e <= 0)
        throw std::string("La longueur doit être strictement supérieure à 0");
}

Dest::Dest(const Dest& dest) : Element(Element::Type::DEST)
{
    this->edge_ = dest.edge_;
    this->lighted_up_ = dest.lighted_up_;
    this->pos_ = dest.pos_;
}

Rectangle Dest::to_rectangle()
{
    return Rectangle(pos_, edge_, edge_);
}

std::ostream& operator<<(std::ostream& out, const Dest& d)
{
    out << "Dest --- Position : " << d.pos_ <<  " , Edge : " << d.edge_ <<
        " , lighted up : " << d.lighted_up_;
    return out;
}

void Dest::translate(const double x, const double y)
{
    pos_.set_position(pos_.x() + x, pos_.y() + y);
    notify_all(std::string("TRANSLATE_DEST"));
}
