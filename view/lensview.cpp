#include "lensview.h"


LensView::LensView(const Lens& lens, bool selectable) :
    ElementView(ElementView::TypeView::LENSVIEW), selectable_{selectable}
{
    this->lens_ = &(const_cast<Lens&>(lens));

    set_rect();
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}



void LensView::translate(double x, double y)
{

}

void LensView::notify(Observable *sdo,
                      std::string msg,
                      const std::vector<std::string>& args)
{
    set_rect();
}

void LensView::set_rect()
{
    setRect(this->lens_->position().x(),
            this->lens_->position().y(),
            this->lens_->width(),
            this->lens_->height());
}
