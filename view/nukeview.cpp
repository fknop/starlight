#include <QPen>

#include "utils/uview.h"

#include "view/nukeview.h"


NukeView::NukeView(const Nuke & nuke, bool selectable)  :
    ElementView(ElementView::TypeView::NUKEVIEW), selectable_{selectable}
{
    nuke_ = &(const_cast<Nuke &>(nuke));
    nuke_->add_observer(this);

    QPen pen(Qt::red);
    pen.setWidth(3);
    setPen(pen);

    uview::display_ellipse(this, nuke_->to_ellipse());

    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
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
    {
        uview::display_ellipse(this, nuke_->to_ellipse());
    }
}

void NukeView::translate(const double x, const double y)
{
    nuke_->translate(x, y);
}


