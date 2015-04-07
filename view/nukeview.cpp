#include "view/nukeview.h"


NukeView::NukeView(const Nuke& nuke)
{
    nuke_ = &nuke;
    nuke_->add_observer(this);

    Point p = nuke_->position();
    double radius = nuke_->radius();

    QBrush brush(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    this->setBrush(brush);

    setRect(p.x() - radius, p.y() + radius,
            radius + radius, radius + radius);
}

void NukeView::notify(Observable *sdo, std::string msg)
{
    if (msg == "LIGHTED_UP")
    {
        QBrush brush(Qt::red);
        brush.setStyle(Qt::SolidPattern);
        this->setBrush(brush);
    }

}
