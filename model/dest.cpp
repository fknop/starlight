#include "model/dest.h"


Dest::Dest(const Point & p, double e) : Element(Element::Type::DEST), pos_ {p}, edge_ {e}
{
    if (e <= 0)
        throw std::string("La longueur doit être strictement supérieure à 0");
}

Dest::Dest(const Dest & dest) : Element(Element::Type::DEST)
{
    this->edge_ = dest.edge_;
    this->light_up_ = dest.light_up_;
    this->pos_ = dest.pos_;
}

Rectangle Dest::to_rectangle()
{
    return Rectangle(this->pos_, this->edge_, this->edge_);
}

std::ostream & operator<<(std::ostream & out, const Dest & d)
{
    out << "Dest --- Position : " << d.pos_ <<  " , Edge : " << d.edge_ <<
        " , lighted up : " << d.light_up_;
    return out;
}

void Dest::translate(double x, double y)
{
    this->pos_.set_position(pos_.x() + x, pos_.y() + y);
    notify_all(std::string("TRANSLATE_DEST"));
}
