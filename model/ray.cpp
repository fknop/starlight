#include "ray.h"

// réservation des attributs statiques
const int Ray::WL_MIN;
const int Ray::WL_MAX;
const int Ray::WL_DFT;

Ray::Ray(const Point & p1, const Point & p2) : Ray {p1, p2, Ray::WL_DFT}
{ }

Ray::Ray(const Point & p1, const Point & p2, int wl) : start {p1},
end {p2}, wavelength {wl}
{
    if (wl < WL_MIN || wl > WL_MAX)
        throw "Longueur d'onde invalide";

    if (p1 < Point(0, 0) || p2 < Point(0, 0))
        throw "Un rayon ne peut pas sortir de la zone de jeu";

}

const Point & Ray::getStart() const
{
    return start;
}

const Point & Ray::getEnd() const
{
    return end;
}

int Ray::getWavelength() const
{
    return wavelength;
}

void Ray::setStart(const Point & p)
{
    start = p;
}

void Ray::setEnd(const Point & p)
{
    end = p;
}

bool Ray::setWavelength(int wl)
{
    bool r = wl >= WL_MIN && wl <= WL_MAX;
    if (r)
        wavelength = wl;

    return r;
}

std::ostream & operator<<(std::ostream & out, const Ray & p)
{
    out << p.start << " ---------- " << p.end << " (" << p.wavelength <<
        " nm)";
    return out;
}
