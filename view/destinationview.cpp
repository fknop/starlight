#include "destinationview.h"


DestinationView::DestinationView(const Dest& dest, bool selectable)  :
    ElementView(ElementView::TypeView::DESTVIEW), selectable_{selectable}
{
    this->dest_ = &(const_cast<Dest&>(dest));
    this->dest_->add_observer(this);

    set_rect();

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void DestinationView::notify(Observable *sdo, std::string msg, const std::vector<std::string> &args)
{
    if (msg == "LIGHTED_UP")
    {
        this->setBrush(QBrush(Qt::green));
    }
    else
    {
        set_rect();
    }
}

void DestinationView::translate(double x, double y)
{
    this->dest_->translate(x, y);
}

void DestinationView::set_rect()
{
    setRect(this->dest_->pos().x(),
            this->dest_->pos().y(),
            this->dest_->edge(),
            this->dest_->edge());
}
