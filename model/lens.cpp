#include "lens.h"
#include "ray.h"


Lens::Lens(const Point & p, double w, double h, int wlmin, int wlmax) :
    Element(Element::Type::LENS), pos_ {p},
    width_ {w}, height_ {h}, wlmin_ {wlmin}, wlmax_ {wlmax}
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

    if (width_ <= 0 || height_ <= 0)
    {
        throw std::string("La taille et la longueur doivent etre strictement positives");
    }
}

Lens::Lens(const Lens& l) : Element(Element::Type::LENS)
{
    this->height_ = l.height_;
    this->pos_ = l.pos_;
    this->width_ = l.width_;
    this->wlmax_ = l.wlmax_;
    this->wlmin_ = l.wlmin_;
}

const Point & Lens::position() const
{
    return pos_;
}

double Lens::width() const
{
    return width_;
}

double Lens::height() const
{
    return height_;
}

int Lens::min_wavelength() const
{
    return wlmin_;
}

int Lens::max_wavelength() const
{
    return wlmax_;
}

Ellipse Lens::to_ellipse()
{
    Point center(this->pos_.x() + this->width_ / 2,
                 this->pos_.y() + this->height_ / 2);
    return Ellipse(center, this->width_ / 2, this->height_ / 2);
}

std::ostream & operator<<(std::ostream & out, const Lens & l)
{
    out << "Lens -- Position : " << l.pos_ << " , width : " << l.width_
        << " , height : " << l.height_ << " , Freq. Min. : " << l.wlmin_ <<
        " , Freq. Max. : " << l.wlmax_;
    return out;
}
