#include <QPen>

#include "view/nukeview.h"


NukeView::NukeView(const Nuke & nuke, bool selectable)  :
    ElementView(ElementView::TypeView::NUKEVIEW), selectable_{selectable}
{
    this->nuke_ = &(const_cast<Nuke &>(nuke));
    this->nuke_->add_observer(this);

    QPen pen(Qt::red);
    pen.setWidth(3);
    setPen(pen);

    set_rect();

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void NukeView::notify(Observable * o, const std::string& msg,
                      const std::vector<std::string>& args)
{
    if (msg.compare("LIGHTED_UP") == 0)
    {
        QBrush brush(Qt::red);
        brush.setStyle(Qt::SolidPattern);
        setBrush(brush);
    }
    else
        set_rect();


}

void NukeView::translate(const double x, const double y)
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
