#include "view/mirrorview.h"


MirrorView::MirrorView(const Mirror& mirror) : mirror_{mirror}, rotation_{0}
{
    setFlags(flags() | QGraphicsItem::ItemIsSelectable);

//    std::cout << "const " << initialPos.x() << " " << initialPos.y() << std::endl;

    double pivotX = mirror.pivot().x();
    double pivotY = mirror.pivot().y();
    double len    = mirror.length();
    double xpad   = mirror.x_pad();
    double angle  = mirror.angle();
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
    initialPos_ = event->pos();
    QGraphicsItem::mousePressEvent(event);
}

void MirrorView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "event scenepos x : " << event->scenePos().x() << std::endl;
    std::cout << "event scenepos y : " << event->scenePos().y() << std::endl;


    setPos(this->mapToParent(event->pos() - initialPos_));
    // set position pivot

}


int MirrorView::rotation()
{
    return rotation_;
}

void MirrorView::set_rotation(qreal angle)
{
    rotation_ = angle;
    QGraphicsLineItem::setRotation(angle);

}

