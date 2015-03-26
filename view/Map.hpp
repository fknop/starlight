#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include "model/level.h"

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(Level *level);
    void drawSegment(QGraphicsScene *s, int x1, int y1, int x2, int y2);

private:
    Level *level;
};

#endif // MAP_HPP
