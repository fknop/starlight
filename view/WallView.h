#ifndef WALLVIEW_HPP
#define WALLVIEW_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include <QGraphicsSceneMouseEvent>

class WallView : public QGraphicsLineItem
{
public:
    WallView(int x1, int y1, int x2, int y2);

private:
    QPointF initialPos;
};


#endif // WALLVIEW_HPP

