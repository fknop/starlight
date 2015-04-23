#include <QPen>

#include "view/crystalview.h"

CrystalView::CrystalView(const Crystal & crystal, bool selectable) :
    ElementView(ElementView::TypeView::CRYSTALVIEW), selectable_{selectable}
{
    crystal_ = &(const_cast<Crystal &>(crystal));
    crystal_->add_observer(this);

    QPen pen(Qt::blue);
    pen.setWidth(3);
    setPen(pen);

    set_rect();
    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
}

void CrystalView::translate(const double x, const double y)
{
    crystal_->translate(x, y);
}

void CrystalView::notify(Observable * o, const std::string& msg,
                         const std::vector<std::string>& args)
{
    set_rect();
}

void CrystalView::set_rect()
{
    const Point& p = crystal_->center();
    double radius = crystal_->radius();
    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);
}
