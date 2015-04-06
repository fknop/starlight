#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include <string>

#include "model/level.h"
#include "view/rayview.h"


class MapView : public QGraphicsView, public ObserverInterface
{
public:
    MapView(Level* level_);
    void draw_wall(QGraphicsScene * s, const Wall & wall);
    void draw_mirror(QGraphicsScene * s, const Mirror& mirror);
    void draw_nuke(QGraphicsScene * s, const Nuke & nuke);
    void draw_lens(QGraphicsScene * s, const Lens & lens);
    void draw_crystal(QGraphicsScene * s, const Crystal & crystal);
    void draw_ray(QGraphicsScene* s, const Ray& ray);

    void keyPressEvent(QKeyEvent * event);

    void notify(Observable *sdo);
    void notify(Observable *sdo, std::string msg);

private:
    std::vector<RayView*> rays_;
    Level * level_;
    QGraphicsScene * scene_;
};

#endif // MAP_HPP
