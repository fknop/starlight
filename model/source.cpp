#include "ray.h"
#include "source.h"


Source::Source(const Point & p, double e, double a, int wl) : pos_ {p},
    alpha_ {a}, edge_ {e}, wavelength_ {wl}
{
    if (wl < 360 || wl > 830)
        wavelength_ = 600;
}

const Point & Source::position() const
{
    return pos_;
}

double Source::angle() const
{
    return alpha_;
}

int Source::edge() const
{
    return edge_;
}

int Source::wavelength() const
{
    return wavelength_;
}

bool Source::is_on() const
{
    return on_;
}

void Source::set_on(bool q)
{
    on_ = q;
}

std::ostream & operator<<(std::ostream & out, const Source & s)
{
    out << "Source --- Position : " << s.pos_ << " , Angle : " << s.alpha_
        << "Frequency : " << s.wavelength_ << " , Edge : " << s.edge_ <<
           " , on : " << s.on_;

    return out;
}
