#include <QPen>

#include "view/lensview.h"


LensView::LensView(const Lens & lens, bool selectable) :
    ElementView(ElementView::TypeView::LENSVIEW), selectable_{selectable}
{
    lens_ = &(const_cast<Lens &>(lens));
    lens_->add_observer(this);

    QPen pen(Qt::green);
    pen.setWidth(3);
    setPen(pen);

    set_rect();
    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
}

void LensView::translate(const double x, const double y)
{
    lens_->translate(x, y);
}

void LensView::notify(Observable * o,
                      const std::string& msg,
                      const std::vector<std::string>& args)
{
    set_rect();
}

void LensView::set_rect()
{
    setRect(lens_->position().x(),
            lens_->position().y(),
            lens_->width(),
            lens_->height());
}
