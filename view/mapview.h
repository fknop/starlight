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

public:
    MapView(Level * level_, bool selectable = false);
    MapView();
    ~MapView();

    /**
     * Dessine les murs du niveau.
     */
    void draw_walls();
    /**
     * Dessine les miroirs du niveau.
     */
    void draw_mirrors();
    /**
     * Dessine les bombes du niveau.
     */
    void draw_nukes();
    /**
     * Dessine les lentilles du niveau.
     */
    void draw_lenses();
    /**
     * Dessine les cristaux du niveau.
     */
    void draw_crystals();
    /**
     * Dessine les rayons du niveau.
     */
    void draw_rays();
    /**
     * Dessine la source du niveau.
     */
    void draw_source();
    /**
     * Dessine la destination du niveau.
     */
    void draw_dest();
    /**
     * Efface tout et redessine le niveau.
     */
    void repaint();
    /**
     * Efface tous les éléments visuels du niveau.
     */
    void clear();

    /**
     * @return l’élément sélectionné dans le niveau ou nullptr si aucun objet n’est sélectionné.
     */
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
    void draw_wall(const Wall & wall);
    void draw_mirror(const Mirror & mirror);
    void draw_nuke(const Nuke & nuke);
    void draw_lens(const Lens & lens);
    void draw_crystal(const Crystal & crystal);
    void draw_ray(const Ray & ray);
};

#endif // MAP_HPP
