#include "view/nukeview.h"


NukeView::NukeView(const Nuke& nuke, bool selectable)  :
    ElementView(ElementView::TypeView::NUKEVIEW), selectable_{selectable}
{
    this->nuke_ = &(const_cast<Nuke&>(nuke));
    this->nuke_->add_observer(this);

    Point p       = this->nuke_->position();
    double radius = this->nuke_->radius();

    QBrush brush(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    this->setBrush(brush);

    setRect(p.x() - radius, p.y() - radius,
            radius + radius, radius + radius);

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void NukeView::notify(Observable* sdo, std::string msg, const std::vector<std::string> &args)
{
    if (msg == "LIGHTED_UP")
    {
        this->setBrush(QBrush(Qt::red));
    }

}


