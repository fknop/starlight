#include "view/Mirror.hpp"

GraphicsLineItem::GraphicsLineItem()
{
    rotation = 0;
    setFlags(flags() | QGraphicsItem::ItemIsSelectable);
}

void GraphicsLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    initialPos = mapToScene(event->pos());
    QGraphicsItem::mousePressEvent(event);
}

void GraphicsLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

