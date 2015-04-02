#include "view/wallview.h"


WallView::WallView(const Wall& wall)
{
    QPen myPen(Qt::black);
    myPen.setWidth(2);

    setPen(myPen);
    setLine(wall.start().x(), wall.start().y(),
            wall.end().x(), wall.end().y());
}


