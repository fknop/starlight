#include "view/destinationview.h"


DestinationView::DestinationView(const Dest & dest, bool selectable)  :
    ElementView(ElementView::TypeView::DESTVIEW), selectable_{selectable}
{
    dest_ = &(const_cast<Dest &>(dest));
    dest_->add_observer(this);

    set_rect();

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void DestinationView::notify(Observable * o, const std::string& msg,
                             const std::vector<std::string> & args)
{
    if (msg.compare("LIGHTED_UP") == 0)
        setBrush(QBrush(Qt::green));
    else
        set_rect();
}

void DestinationView::translate(const double x, const double y)
{
    dest_->translate(x, y);
}

void DestinationView::set_rect()
{
    setRect(dest_->pos().x(),
            dest_->pos().y(),
            dest_->edge(),
            dest_->edge());
}
