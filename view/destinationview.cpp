#include "destinationview.h"


DestinationView::DestinationView(const Dest& dest)
{
    this->dest_ = &(const_cast<Dest&>(dest));
    this->dest_->add_observer(this);
    setRect(this->dest_->pos().x(),
            this->dest_->pos().y(),
            this->dest_->edge(),
            this->dest_->edge());
}

void DestinationView::notify(Observable *sdo, std::string msg, const std::vector<std::string> &args)
{
    if (msg == "LIGHTED_UP")
    {
        this->setBrush(QBrush(Qt::green));
    }
}
