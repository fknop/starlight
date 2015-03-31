#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include "model/level.h"

class MapView : public QGraphicsView
{
public:
    MapView(Level *level);
    void drawWall(QGraphicsScene *s, const Wall& wall);
    void drawMirror(QGraphicsScene *s, const Mirror& mirror);
    void drawNuke(QGraphicsScene *s, const Nuke& nuke);
    void drawLens(QGraphicsScene *s, const Lens& lens);
    void drawCrystal(QGraphicsScene *s, const Crystal& crystal);

    void keyPressEvent(QKeyEvent *event);

private:
    Level *level;
    QGraphicsScene *scene;
};

#endif // MAP_HPP
