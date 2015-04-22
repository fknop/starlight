#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QMouseEvent>

#include "model/level.h"

#include "view/crystalview.h"
#include "view/destinationview.h"
#include "view/elementview.h"
#include "view/lensview.h"
#include "view/mirrorview.h"
#include "view/nukeview.h"
#include "view/rayview.h"
#include "view/sourceview.h"
#include "view/wallview.h"


/**
 * Modélisation visuelle d’un plateau de jeu.
 */
class MapView : public QGraphicsView, public ObserverInterface, public Observable
{
public:
    MapView(Level * level_, bool selectable = false);
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
    void clear();

    ElementView * selected();


    void mousePressEvent(QMouseEvent * event);
    void keyPressEvent(QKeyEvent * event);
    /**
     * Notifie le jeu d'un évènement provenant d'un sujet d'observation (Observable).
     * @param o l'observé.
     * @param msg le message de notification.
     * @param args des arguments.
     */
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
    DestinationView * dest_view_ = nullptr;
    SourceView * source_view_ = nullptr;
    MirrorView * selected_mirror_;
    std::vector<RayView *> ray_views_;
    std::vector<MirrorView *> mirror_views_;
    std::vector<LensView *> lens_views_;
    std::vector<CrystalView *> crystal_views_;
    std::vector<NukeView *> nuke_views_;
    std::vector<WallView *> wall_views_;

    Level * level_;
    QGraphicsScene * scene_;
    QMediaPlayer * sound_;
    bool selectable_;

    void draw_wall(const Wall & wall);
    void draw_mirror(const Mirror & mirror);
    void draw_nuke(const Nuke & nuke);
    void draw_lens(const Lens & lens);
    void draw_crystal(const Crystal & crystal);
    void draw_ray(const Ray & ray);
};

#endif // MAP_HPP
