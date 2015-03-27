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


    QPoint bordGauche(gx, gy);
    QPoint bordDroit (dx, dy);

    QPoint bordGauche2(gx + 25, gy + 25);
    QPoint bordDroit2(dx - 25, dy - 25);

//    QRectF rect(bordGauche2, bordDroit2);
//    drawRect(rect);
//    fillRect(rect, QColor(128, 128, 255, 128));

    QPen myPen(Qt::red);
//    myPen.setWidth(5);
//    setPen(myPen);
//    //p->setBrush(Qt::NoBrush);

//    drawPoint(QPointF(pivotX, pivotY));

//    myPen.setWidth(1);
//    //myPen.setColor(Qt::black);
    setPen(myPen);

    setLine(gx, gy, dx, dy);

//    setPen(nullptr);
    //setLine(pivotX, pivotY, xpad, len);
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

