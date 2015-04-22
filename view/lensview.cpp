#include <QPen>

#include "view/lensview.h"


LensView::LensView(const Lens & lens, bool selectable) :
    ElementView(ElementView::TypeView::LENSVIEW), selectable_{selectable}
{
    this->lens_ = &(const_cast<Lens &>(lens));
    this->lens_->add_observer(this);

    QPen pen(Qt::green);
    pen.setWidth(3);
    setPen(pen);

    set_rect();
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void LensView::translate(const double x, const double y)
{
    this->lens_->translate(x, y);
}

void LensView::notify(Observable * o,
                      const std::string& msg,
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
