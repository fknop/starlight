#include "crystalview.h"

CrystalView::CrystalView(const Crystal& crystal) :
    ElementView(ElementView::TypeView::CRYSTALVIEW)
{
    this->crystal_ = &(const_cast<Crystal&>(crystal));

    Point p        = this->crystal_->center();
    double radius  = this->crystal_->radius();

    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);
}

Crystal * CrystalView::crystal()
{
    return crystal_;
}
