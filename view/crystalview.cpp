#include "crystalview.h"

CrystalView::CrystalView(const Crystal& crystal)
{
    this->crystal_ = &crystal;

    Point p        = this->crystal_->center();
    double radius  = this->crystal_->radius();

    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);
}
