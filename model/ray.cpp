#include "ray.h"


// réservation des attributs statiques
const int Ray::WL_MIN;
const int Ray::WL_MAX;
const int Ray::WL_DFT;


Ray::Ray(const Point & p1, const Point & p2) : Ray {p1, p2, Ray::WL_DFT}
{ }

Ray::Ray(const Point & p1, const Point & p2, int wl) : start_ {p1},
end_ {p2}, wavelength_ {wl}
{
    if (wl < WL_MIN || wl > WL_MAX)
        throw std::string("Longueur d'onde invalide");


}

std::ostream & operator<<(std::ostream & out, const Ray & p)
{
    out << p.start_ << " ---------- " << p.end_ << " (" << p.wavelength_ <<
        " nm)";

    return out;
}
