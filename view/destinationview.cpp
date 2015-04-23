#include "utils/uview.h"

#include "view/destinationview.h"


DestinationView::DestinationView(const Dest & dest, bool selectable)  :
    ElementView(ElementView::TypeView::DESTVIEW), selectable_{selectable}
{
    dest_ = &(const_cast<Dest &>(dest));
    dest_->add_observer(this);

    uview::display_rectangle(this, dest_->to_rectangle());
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void DestinationView::notify(Observable * o, const std::string& msg,
                             const std::vector<std::string> & args)
{
    if (msg.compare("LIGHTED_UP") == 0)
        setBrush(QBrush(Qt::green));
    else
        uview::display_rectangle(this, dest_->to_rectangle());
}

void DestinationView::translate(const double x, const double y)
{
    dest_->translate(x, y);
}

