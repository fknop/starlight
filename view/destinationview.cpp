#include "destinationview.h"


DestinationView::DestinationView(const Dest& dest)
{
    this->dest_ = &dest;
    setRect(this->dest_->position().x(),
            this->dest_->position().y(),
            this->dest_->edge(),
            this->dest_->edge());
}
