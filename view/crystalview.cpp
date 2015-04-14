#include "crystalview.h"

CrystalView::CrystalView(const Crystal& crystal, bool selectable) :
    ElementView(ElementView::TypeView::CRYSTALVIEW), selectable_{selectable}
{
    this->crystal_ = &(const_cast<Crystal&>(crystal));
    set_rect();
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void CrystalView::translate(double x, double y)
{
    //this->crystal_->translate(x, y);
}

void CrystalView::notify(Observable* obs, std::string msg, const std::vector<std::string> &args)
{
    set_rect();
}

void CrystalView::set_rect()
{
    const Point& p        = this->crystal_->center();
    double radius  = this->crystal_->radius();
    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);
}
