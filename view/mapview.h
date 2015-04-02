#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>

#include "model/level.h"

class MapView : public QGraphicsView
{
public:
    MapView(Level * level_);
    void draw_wall(QGraphicsScene * s, const Wall & wall);
    void draw_mirror(QGraphicsScene * s, const Mirror & mirror);
    void draw_nuke(QGraphicsScene * s, const Nuke & nuke);
    void draw_lens(QGraphicsScene * s, const Lens & lens);
    void draw_crystal(QGraphicsScene * s, const Crystal & crystal);

    void keyPressEvent(QKeyEvent * event);

private:
    Level * level_;
    QGraphicsScene * scene_;
};

#endif // MAP_HPP
