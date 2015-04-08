#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include <QMediaPlayer>
#include <string>

#include "model/level.h"
#include "view/rayview.h"


class MapView : public QGraphicsView, public ObserverInterface
{
public:
    MapView(Level* level_);
    MapView();
    ~MapView();
    void draw_wall(const Wall & wall);
    void draw_mirror(const Mirror& mirror);
    void draw_nuke(const Nuke & nuke);
    void draw_lens(const Lens & lens);
    void draw_crystal(const Crystal & crystal);
    void draw_ray(const Ray& ray);

    void keyPressEvent(QKeyEvent * event);
    void notify(Observable *sdo, std::string msg);

private:
    std::vector<RayView*> rays_;
    Level * level_;
    QGraphicsScene * scene_;
    QMediaPlayer * sound_;
};

#endif // MAP_HPP
