#include "ray.h"
#include "source.h"


Source::Source(const Point & p, double e, double a, int wl) : pos_ {p},
    alpha_ {a}, edge_ {e}, wavelength_ {wl}
{
    if (wl < 360 || wl > 830)
        wavelength_ = 600;
}

std::ostream& operator<<(std::ostream& out, const Source& s)
{
    out << "Source --- Position : " << s.pos_ << " , Angle : " << s.alpha_
        << "Frequency : " << s.wavelength_ << " , Edge : " << s.edge_ <<
           " , on : " << s.on_;

    return out;
}

void Source::notify_all()
{
    for (ObserverInterface* o : this->observers_)
        o->notify(this);
}
