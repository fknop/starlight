#include "destinationview.h"


DestinationView::DestinationView(const Dest& dest)
{
    this->dest_ = &(const_cast<Dest&>(dest));
    this->dest_->add_observer(this);
    setRect(this->dest_->position().x(),
            this->dest_->position().y(),
            this->dest_->edge(),
            this->dest_->edge());
}

void DestinationView::notify(Observable *sdo, std::string msg)
{
    if (msg == "LIGHTED_UP")
    {
        this->setBrush(QBrush(Qt::green));
    }
}
