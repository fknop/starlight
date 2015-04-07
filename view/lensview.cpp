#include "lensview.h"


LensView::LensView(const Lens& lens)
{
    this->lens_ = &lens;
    setRect(this->lens_->position().x(),
            this->lens_->position().y(),
            this->lens_->width(),
            this->lens_->height());
}
