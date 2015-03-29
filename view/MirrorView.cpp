#include "view/MirrorView.h"

MirrorView::MirrorView(int pivotX, int pivotY, int xpad, int len, double angle)
{
    rotation = 0;
    setFlags(flags() | QGraphicsItem::ItemIsSelectable);

    initialPos.setX(pivotX);
    initialPos.setY(pivotY);

    std::cout << "const " << initialPos.x() << " " << initialPos.y() << std::endl;


    int gx = pivotX - (xpad * cos(angle));
    int gy = pivotY - (xpad * sin(angle));
    int dx = pivotX + ((len-xpad) * cos(angle));
    int dy = pivotY + ((len-xpad) * sin(angle));

//    setTransformOriginPoint(QPointF(pivotX, pivotY));
    setTransformOriginPoint(initialPos);


    QPen myPen(Qt::red);
    myPen.setWidth(3);

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
    std::cout << pos().x() << " " << pos().y() << std::endl;


    std::cout << "initial pos x : " << initialPos.x() << std::endl;
    std::cout << "initial pos y : " << initialPos.y() << std::endl;
    std::cout << "event pos x : " << event->scenePos().x() << std::endl;
    std::cout << "event pos y : " << event->scenePos().y() << std::endl;
//    std::cout << "pos x : " << event->scenePos().x() - initialPos.x() << std::endl;
//    std::cout << "pos y : " << event->scenePos().y() - initialPos.y() << std::endl;

    std::cout << std::endl << std::endl;


    setPos(event->scenePos().x() - initialPos.x(), event->scenePos().y() - initialPos.y());
    setTransformOriginPoint(pos());




}

void MirrorView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    initialPos.setX(pos().x());
    initialPos.setY(pos().y());

    pos().setX(event->scenePos().x() - initialPos.x());
    pos().setY(event->scenePos().y() - initialPos.y());
    std::cout << pos().x() << " " << pos().y() << std::endl;

    setTransformOriginPoint(pos());


    std::cout << "released event " << event->scenePos().x() << " " << event->scenePos().y() << std::endl;
//    std::cout << "released initP " << initialPos.x() << " " << initialPos.y() << std::endl;
//    initialPos.setX(event->scenePos().x());
//    initialPos.setY(event->scenePos().y());
//    initialPos.setX(pos().x());
//    initialPos.setY(pos().y());
//    std::cout << "released initP " << initialPos.x() << " " << initialPos.y() << std::endl;
//    setTransformOriginPoint(initialPos);
//    std::cout << std::endl << std::endl;
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

