#include "view/WallView.h"

WallView::WallView(const Wall& wall)
{
    QPen myPen(Qt::black);
    myPen.setWidth(2);

    setPen(myPen);
    setLine(wall.getStart().getX(), wall.getStart().getY(),
            wall.getEnd().getX(), wall.getEnd().getY());
}


