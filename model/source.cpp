#include "model/source.h"
#include "model/ray.h"



Source::Source(const Point& p, double e, double a, int wl) : Element(Element::Type::SOURCE),
    pos_ {p}, alpha_ {a}, edge_ {e}, wavelength_{wl}
{
    if (e <= 0)
        std::string("Le côté de la source ne peut pas être plus petit ou égal à zéro");

    if (wl < Ray::WL_MIN || wl > Ray::WL_MAX)
        wavelength_ = Ray::WL_DFT;
}

std::ostream& operator<<(std::ostream& out, const Source& s)
{
    out << "Source --- Position : " << s.pos_ << " , Angle : " << s.alpha_
        << "Frequency : " << s.wavelength_ << " , Edge : " << s.edge_ <<
           " , on : " << s.on_;

    return out;
}


Rectangle Source::to_rectangle()
{
    return Rectangle(pos_, edge_, edge_);
}

void Source::translate(double x, double y)
{
    pos_.set_position(pos_.x() + x, pos_.y() + y);
    notify_all(std::string("TRANSLATE_SOURCE"));
}
