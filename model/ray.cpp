#include "ray.h"


// réservation des attributs statiques
constexpr int Ray::WL_MIN;
constexpr int Ray::WL_MAX;
constexpr int Ray::WL_DFT;


Ray::Ray(const Point & p1, const Point & p2) : Ray {p1, p2, Ray::WL_DFT}
{ }

Ray::Ray(const Point & p1, const Point & p2, int wl) : start_ {p1},
end_ {p2}, wavelength_ {wl}
{
    if (wl < WL_MIN)
        wl = WL_MIN;
    else if (wl > WL_MAX)
        wl = WL_MAX;


}

std::ostream & operator<<(std::ostream & out, const Ray & p)
{
    out << p.start_ << " ---------- " << p.end_ << " (" << p.wavelength_ <<
        " nm)";

    return out;
}
