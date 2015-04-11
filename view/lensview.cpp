#include "lensview.h"


LensView::LensView(const Lens& lens) :
    ElementView(ElementView::TypeView::LENSVIEW)
{
    this->lens_ = &lens;
    setRect(this->lens_->position().x(),
            this->lens_->position().y(),
            this->lens_->width(),
            this->lens_->height());

    this->lens_ = &(const_cast<Lens&>(lens));
}

Lens * LensView::lens()
{
    return lens_;
}
