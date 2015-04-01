#include "view/WallView.h"

WallView::WallView(const Wall& wall)
{
    QPen myPen(Qt::black);
    myPen.setWidth(2);

    setPen(myPen);
    setLine(wall.getStart().x(), wall.getStart().y(),
            wall.getEnd().x(), wall.getEnd().y());
}


