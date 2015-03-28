#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include "model/level.h"

class MapView : public QGraphicsView
{
public:
    MapView(Level *level);
    void drawWall(QGraphicsScene *s, int x1, int y1, int x2, int y2);
    void drawMirror(QGraphicsScene *s, int pivotX, int pivotY, int xpad, int len, double angle);

    void keyPressEvent(QKeyEvent *event);

private:
    Level *level;
    QGraphicsScene *scene;
};

#endif // MAP_HPP
