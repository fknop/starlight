#include "view/MirrorView.h"

MirrorView::MirrorView(int pivotX, int pivotY, int xpad, int len, double angle)
{
    rotation = 0;
    setFlags(flags() | QGraphicsItem::ItemIsSelectable);

    //std::cout << "new mirror on " << pivotX << " " << pivotY << std::endl;
    //std::cout << (len) << " " << (xpad) << " " << cos(angle) << " " << sin(angle) << std::endl;


    int gx = pivotX - (xpad * cos(angle));
    int gy = pivotY - (xpad * sin(angle));
    int dx = pivotX + ((len-xpad) * cos(angle));
    int dy = pivotY + ((len-xpad) * sin(angle));

    setTransformOriginPoint(QPointF(pivotX, pivotY));
    QPen myPen(Qt::red);

    setPen(myPen);
    setLine(gx, gy, dx, dy);

}

void MirrorView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    initialPos = mapToScene(event->pos());
    QGraphicsItem::mousePressEvent(event);
}

void MirrorView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = mapToScene(event->pos());

    if (pos.y() > initialPos.y())
    {
        ++rotation;
    }
    else
    {
        --rotation;
    }

    setRotation(rotation);

}

