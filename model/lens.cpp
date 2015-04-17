#include "lens.h"
#include "ray.h"


Lens::Lens(const Point& p, double w, double h, int wl_min, int wl_max) :
    Element(Element::Type::LENS), pos_ {p},
    width_ {w}, height_ {h}, wl_min_ {wl_min}, wl_max_ {wl_max}
{
    if (wl_min < Ray::WL_MIN || wl_max > Ray::WL_MAX)
        throw std::string("Les bornes de longueurs d'ondes"
                          "ne peuvent pas être plus petites"
                          "que le minimum ou plus grande"
                          "que le maximum");

    if (wl_min > wl_max)
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
    this->wl_max_ = l.wl_max_;
    this->wl_min_ = l.wl_min_;
}

Ellipse Lens::to_ellipse()
{
    Point center(pos_.x() + width_ / 2,
                 pos_.y() + height_ / 2);
    return Ellipse(center, width_ / 2, height_ / 2);
}

bool Lens::operator ==(const Lens& l) const
{
    return
     umath::equals(this->width_, l.width_) &&
     umath::equals(this->height_, l.height_) &&
     umath::equals(this->wl_min_, l.wl_min_) &&
     umath::equals(this->wl_max_, l.wl_max_);
}

void Lens::translate(const double x, const double y)
{
    pos_.set_position(pos_.x() + x, pos_.y() + y);
    notify_all(std::string("TRANSLATE_LENS"));
}


std::ostream& operator<<(std::ostream& out, const Lens& l)
{
    out << "Lens -- Position : " << l.pos_ << " , width : " << l.width_
        << " , height : " << l.height_ << " , Freq. Min. : " << l.wl_min_ <<
        " , Freq. Max. : " << l.wl_max_;
    return out;
}
