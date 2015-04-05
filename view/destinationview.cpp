#include "destinationview.h"


DestinationView::DestinationView(const Dest& dest) : dest_(dest)
{
    setRect(dest_.position().x(), dest_.position().y(),
            dest_.edge(), dest_.edge());
}
