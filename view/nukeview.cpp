#include "view/nukeview.h"


NukeView::NukeView(const Nuke & nuke, bool selectable)  :
    ElementView(ElementView::TypeView::NUKEVIEW), selectable_{selectable}
{
    this->nuke_ = &(const_cast<Nuke &>(nuke));
    this->nuke_->add_observer(this);

    QBrush brush(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    set_rect();

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void NukeView::notify(Observable * sdo, std::string msg, const std::vector<std::string> & args)
{
    if (msg.compare("LIGHTED_UP") == 0)
        setBrush(QBrush(Qt::red));
    else
        set_rect();


}

void NukeView::translate(double x, double y)
{
    this->nuke_->translate(x, y);
}

void NukeView::set_rect()
{
    const Point& p = this->nuke_->position();
    double radius = this->nuke_->radius();
    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);
}
