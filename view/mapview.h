#ifndef MAP_HPP
#define MAP_HPP

#include <QGraphicsView>
#include <QMediaPlayer>
#include <string>
#include <QMouseEvent>

#include "model/level.h"
#include "view/rayview.h"
#include "view/wallview.h"
#include "view/lensview.h"
#include "view/mirrorview.h"
#include "view/crystalview.h"
#include "view/nukeview.h"
#include "view/sourceview.h"
#include "view/destinationview.h"

#include "view/elementview.h"

class MapView : public QGraphicsView, public ObserverInterface
{
public:
    MapView(Level* level_);
    MapView();
    ~MapView();
    void draw_walls();
    void draw_mirrors();
    void draw_nukes();
    void draw_lenses();
    void draw_crystals();
    void draw_rays();
    void draw_source();
    void draw_dest();
    void repaint();

    void mousePressEvent(QMouseEvent * event);
    ElementView *selected();


    void keyPressEvent(QKeyEvent * event);
    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
    std::vector<RayView*> ray_views_;
    std::vector<MirrorView*> mirror_views_;
    std::vector<LensView*> lens_views_;
    std::vector<CrystalView*> crystal_views_;
    std::vector<NukeView*> nuke_views_;
    std::vector<WallView*> wall_views_;
    DestinationView* dest_view_ = nullptr;
    SourceView* source_view_ = nullptr;

    Level * level_;
    QGraphicsScene * scene_;
    QMediaPlayer * sound_;

    void draw_wall(const Wall & wall);
    void draw_mirror(const Mirror& mirror);
    void draw_nuke(const Nuke & nuke);
    void draw_lens(const Lens & lens);
    void draw_crystal(const Crystal & crystal);
    void draw_ray(const Ray& ray);
};

#endif // MAP_HPP
