#ifndef MirrorView_HPP
#define MirrorView_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include <QGraphicsSceneMouseEvent>

class MirrorView : public QGraphicsLineItem
{
public:
    MirrorView(int pivotX, int pivotY, int xpad, int len, double angle);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF initialPos;
    qreal rotation;


};


#endif // MirrorView_HPP
