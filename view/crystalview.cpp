#include "crystalview.h"

CrystalView::CrystalView(const Crystal& crystal, bool selectable) :
    ElementView(ElementView::TypeView::CRYSTALVIEW), selectable_{selectable}
{
    this->crystal_ = &(const_cast<Crystal&>(crystal));

    Point p        = this->crystal_->center();
    double radius  = this->crystal_->radius();

    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}
