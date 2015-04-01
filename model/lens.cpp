#include "lens.h"
#include "ray.h"

Lens::Lens(const Point & p, double w, double h, int wlmin, int wlmax) :
    Element(Element::Type::LENS), pos {p},
    width {w}, height {h}, wlmin {wlmin}, wlmax {wlmax}
{


    if (wlmin <= Ray::WL_MIN || wlmax >= Ray::WL_MAX)
        throw std::string("Les bornes de longueurs d'ondes"
                          "ne peuvent pas être plus petites"
                          "que le minimum ou plus grande"
                          "que le maximum");

    if (wlmin > wlmax)
    {
        throw std::string("La longueur d'onde minimale "
                          "ne peut pas être plus grande que "
                          "la longueur d'onde maximale");
    }

    if (width <= 0 || height <= 0)
    {
        throw std::string("La taille et la longueur doivent etre strictement positives");
    }
}

Lens::Lens(const Lens& l) : Element(Element::Type::LENS)
{
    this->height = l.height;
    this->pos = l.pos;
    this->width = l.width;
    this->wlmax = l.wlmax;
    this->wlmin = l.wlmin;
}

const Point & Lens::getPosition() const
{
    return pos;
}

double Lens::getWidth() const
{
    return width;
}

double Lens::getHeight() const
{
    return height;
}

int Lens::getMinWavelength() const
{
    return wlmin;
}

int Lens::getMaxWavelength() const
{
    return wlmax;
}

Ellipse Lens::toEllipse()
{
    Point center(this->pos.getX() + this->width / 2,
                 this->pos.getY() + this->height / 2);
    return Ellipse(center, this->width / 2, this->height / 2);
}

std::ostream & operator<<(std::ostream & out, const Lens & l)
{
    out << "Lens -- Position : " << l.pos << " , width : " << l.width
        << " , height : " << l.height << " , Freq. Min. : " << l.wlmin <<
        " , Freq. Max. : " << l.wlmax;
    return out;
}
