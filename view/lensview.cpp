#include "lensview.h"


LensView::LensView(const Lens& lens, bool selectable) :
    ElementView(ElementView::TypeView::LENSVIEW), selectable_{selectable}
{
    this->lens_ = &(const_cast<Lens&>(lens));

    setRect(this->lens_->position().x(),
            this->lens_->position().y(),
            this->lens_->width(),
            this->lens_->height());

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

Lens * LensView::lens()
{
    return lens_;
}
