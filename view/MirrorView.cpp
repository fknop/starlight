#include "view/MirrorView.h"

MirrorView::MirrorView(const Mirror& mirror) : mirror{mirror}
{
    rotation = 0;
    setFlags(flags() | QGraphicsItem::ItemIsSelectable);



//    std::cout << "const " << initialPos.x() << " " << initialPos.y() << std::endl;

    double pivotX = mirror.getPivot().getX();
    double pivotY = mirror.getPivot().getY();
    double len    = mirror.getLength();
    double xpad   = mirror.getXPad();
    double angle  = mirror.getAngle();
    double gx = pivotX - (xpad * cos(angle));
    double gy = pivotY - (xpad * sin(angle));
    double dx = pivotX + ((len-xpad) * cos(angle));
    double dy = pivotY + ((len-xpad) * sin(angle));

    setTransformOriginPoint(QPointF(pivotX, pivotY));

    QPen myPen(Qt::red);
    myPen.setWidth(3);

    setPen(myPen);
    setLine(gx, gy, dx, dy);

}

void MirrorView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    initialPos = event->pos();
    QGraphicsItem::mousePressEvent(event);
}

void MirrorView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "event scenepos x : " << event->scenePos().x() << std::endl;
    std::cout << "event scenepos y : " << event->scenePos().y() << std::endl;


    setPos(this->mapToParent(event->pos() - initialPos));
    // set position pivot

}


int MirrorView::getRotation()
{
    return rotation;
}

void MirrorView::setRotation(qreal angle)
{
    rotation = angle;
    QGraphicsLineItem::setRotation(angle);

}

