#ifndef MIRROR_HPP
#define MIRROR_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include <QGraphicsSceneMouseEvent>

class GraphicsLineItem : public QGraphicsLineItem
{
public:
    GraphicsLineItem();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF initialPos;
    qreal rotation;

};


#endif // MIRROR_HPP
