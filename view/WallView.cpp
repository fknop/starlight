#include "view/WallView.h"

WallView::WallView(int x1, int y1, int x2, int y2)
{
    QPen myPen(Qt::black);
    myPen.setWidth(2);

    setPen(myPen);
    setLine(x1, y1, x2, y2);
}


