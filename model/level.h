#ifndef LEVEL_H
#define LEVEL_H

#include <algorithm>
#include <vector>

#include "model/crystal.h"
#include "model/dest.h"
#include "model/lens.h"
#include "model/line.h"
#include "model/mirror.h"
#include "model/nuke.h"
#include "model/point.h"
#include "model/ray.h"
#include "model/source.h"
#include "model/wall.h"

#include "obs/observable.h"
#include "obs/observerinterface.h"

/**
 * Structure intersection :
 * Possède un élément et un point d'intersection.
 */
struct Intersection
{
    /**
     * La position d'intersection.
     */
    Point * point_;

    /**
     * L'élément d'intersection.
     */
    Element * element_;

    /**
     * Crée une nouvelle intersection.
     * @param p le point d'intersection.
     * @param e l'élément de l'intersection.
     */
    Intersection(Point * p, Element * e)
    {
        point_ = p;
        element_ = e;
    }
};


/**
 * Modélise une carte telle qu'utilisée dans le jeu.
 * </p>
 * Une carte est un ensemble de composants tels que des murs,
 * des miroirs, etc.
 */
class Level : public ObserverInterface, public Observable
{
    const double width_;
    const double height_;

    Source source_ {{.0, .0}, -1, 5, 600};
    Dest dest_ {{.0, .0}, 5};

    std::vector<Intersection> intersections_;
    std::vector<Wall> walls_;
    std::vector<Mirror> mirrors_;
    std::vector<Crystal> crystals_;
    std::vector<Lens> lenses_;
    std::vector<Ray> rays_;
    std::vector<Nuke> nukes_;

    bool check_collisions_;
    bool handle_dest_;
    bool handle_nukes_;

public:

    /**
     * Instancie une carte de largeur et hauteur donnée.
     * </p>
     * Quand une carte est créée, quatre murs dénotant ses bords sont
     *  automatiquement ajoutés à la carte.
     * </p>
     * La source et la destination sont initialisées à des valeurs
     * par défaut inutilisables.
     * Vous devez manuellement initialiser la source et la destination
     * via les fonctions
     * appropriées.
     * @param w la largeur de la carte.
     * @param h la hauteur de la carte.
     * @throws std::string si les tailles sont inférieurs ou égales à zéro.
     */
    Level(double w, double h);

    /**
     * Retourne la source de la carte.
     * @return la source de la carte.
     */
    inline const Source& source() const;

    /**
     * Change la source de la carte.
     * @param value la nouvelle source.
     */
    inline void set_source(const Source& value);

    /**
     * Retourne la desination de la carte.
     * @return la destination de la carte.
     */
    inline const Dest& dest() const;

    /**
     * Change la destination de la carte.
     * @param value la destination de la carte.
     */
    inline void set_dest(const Dest& value);

    /**
     * Retourne l'ensemble des murs de la carte.
     * @return l'ensemble des murs de la carte.
     */
    inline const std::vector<Wall>& walls() const;

    /**
     * Retourne l'ensemble des miroirs de la carte.
     * @return l'ensemble des miroirs de la carte.
     */
    inline const std::vector<Mirror>& mirrors() const;

    /**
     * Retourne l'ensemble des cristaux de la carte.
     * @return l'ensemble des cristaux de la carte.
     */
    inline const std::vector<Crystal>& crystals() const;

    /**
     * Retourne l'ensemble des lentilles de la carte.
     * @return l'ensemble des lentilles de la carte.
     */
    inline const std::vector<Lens>& lenses() const;

    /**
     * Retourne l'ensemble des rayons de la carte.
     * @return l'ensemble des rayons de la carte.
     */
    inline const std::vector<Ray>& rays() const;

    /**
     * Retourne l'ensemble des bombes de la carte.
     * @return l'ensemble des bombes de la carte.
     */
    inline const std::vector<Nuke>& nukes() const;

    /**
     * Change l'ensemble des rayons de la carte.
     * @param rays le nouvel ensemble de rayons de la carte.
     */
    inline void set_rays(const std::vector<Ray>& rays);

    /**
     * Change l'ensemble des murs de la carte.
     * @param walls le nouvel ensemble de murs de la carte.
     */
    inline void set_walls(const std::vector<Wall>& walls);

    /**
     * Change l'ensemble des cristaux de la carte.
     * @param crystals le nouvel ensemble des cristaux de la carte.
     */
    inline void set_crystals(const std::vector<Crystal>& crystals);

    /**
     * Change l'ensemble des bombes de la carte.
     * @param nukes le nouvel ensemble des bombes de la carte.
     */
    inline void set_nukes(const std::vector<Nuke>& nukes);

    /**
     * Change l'ensemble des lentilles de la carte.
     * @param lenses le nouvel ensemble des lentilles de la carte.
     */
    inline void set_lenses(const std::vector<Lens>& lenses);

    /**
     * Change l'ensemble des mirroirs de la carte.
     * @param mirrors le nouvel ensemble des mirroirs de la carte.
     */
    inline void set_mirrors(const std::vector<Mirror>& mirrors);

    /**
     * Retourne la taille de la carte.
     * @return la taille de la carte.
     */
    inline int height() const;

    /**
     * Retourne la longueur de la carte.
     * @return la longueur de la carte.
     */
    inline int width() const;

    /**
     * Calcule les rayons lumineux de la carte.
     * </p>
     * Cette fonction doit être surchargée obligatoirement.
     */
    void compute_rays();

    /**
     * Ajoute un nouveau miroir à la carte.
     * @param m le nouveau miroir.
     */
    inline void add_mirror(const Mirror& m);

    /**
     * Ajoute une nouvelle bombe à la carte.
     * @param n la nouvelle bombe.
     */
    inline void add_nuke(const Nuke& n);

    /**
     * Ajoute un nouveau mur à la carte.
     * @param w le nouveau mur.
     */
    inline void add_wall(const Wall& w);

    /**
     * Ajoute un nouveau cristal à la carte.
     * @param c le nouveau cristal.
     */
    inline void add_crystal(const Crystal& c);

    /**
     * Ajoute une nouvelle lentille à la carte.
     * @param l la nouvelle lentille.
     */
    inline void add_lens(const Lens& l);

    /**
     * Ajoute un nouveau rayon à la carte.
     * @param r le nouveau rayon.
     */
    inline void add_ray(const Ray& r);

    /**
     * Retourne vrai si la partie est gagnée.
     * @return vrai si la partie est gagnée, faux sinon.
     */
    inline bool won() const;

    /**
     * Retourne vrai si la partie est perdue.
     * @return vrai si la partie est perdue, faux sinon.
     */
    inline bool lost() const;

    /**
     * Retourne vrai si les nukes sont activées.
     * @return vrai si les nukes sont activées, faux sinon.
     */
    inline bool handle_nukes() const;

    /**
     * Retourne vrai si la destination est activée.
     * @return vrai si la destination est activée, faux sinon.
     */
    inline bool handle_dest() const;

    /**
     * Retourne vrai si les collisions entre les miroirs et les
     * élements de la carte sont gérées.
     * @return vrai si les collisions sont gérées, faux sinon.
     */
    inline bool check_collisions() const;

    /**
     * Modifie la vérification des collisions entre miroirs
     * et élements de la carte.
     * @param value vrai si les collisions sont gérées, faux sinon.
     */
    inline void set_check_collisions(bool value);

    /**
     * Modifie le comportement des nukes de la carte.
     * @param value vrai si les nukes sont activées, faux sinon.
     */
    inline void set_handle_nukes(bool value);

    /**
     * Modifie le comportement de la destination sur la carte.
     * @param value vrai si la destination est activée, faux sinon.
     */
    inline void set_handle_dest(bool value);

    /**
     * Supprime un crystal.
     * @param c le crystal à supprimer.
     */
    inline void remove_crystal(const Crystal& c);

    /**
     * Supprime une lentille.
     * @param l la lentille à supprimer.
     */
    inline void remove_lens(const Lens& l);

    /**
     * Supprime un mirroir.
     * @param m le mirroir à supprimer.
     */
    inline void remove_mirror(const Mirror &m);

    /**
     * Supprime une bombe.
     * @param n la bombe à supprimer.
     */
    inline void remove_nuke(const Nuke& n);

    /**
     * Supprime un mur.
     * @param w le mur à supprimer.
     */
    inline void remove_wall(const Wall& w);

    /**
     * Notification d'un évènement provenant d'un sujet d'observation (Observable).
     * @param o l'observé.
     * @param msg le message de notification.
     * @param args des arguments.
     */
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

private:

    /**
     * Permet de calculer la trajectoire d'un rayon.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     * @param wl la longueur d'onde du rayon.
     */
    void compute_ray(const Line& line, const Point& start, int wl);

    /**
     * Retourne l'intersection la plus proche du rayon avec un objet.
     * @param line la droite du rayon.
     * @return l'intersection la plus proche.
     */
    void get_intersections(const Line& line, const Point& start);

    /**
     * Calcule l'angle de reflexion d'un rayon sur un miroir.
     * @param startAngle l'angle de départ.
     * @param mirrorAngle l'inclinaison du miroir.
     * @return l'angle réfléchi.
     */
    double get_reflection_angle(double startAngle, double mirrorAngle);

    /**
     * Place les intersections avec la destination et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void dest_intersections(const Line& line, const Point& start);

    /**
     * Place les intersections avec la source et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void source_intersections(const Line& line,
                              const Point& start);

    /**
     * Place les intersections avec les murs et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void walls_intersections(const Line& line,
                             const Point& start);

    /**
     * Place les intersections avec les lentilles et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void lenses_intersections(const Line& line,
                              const Point& start);

    /**
     * Place les intersections avec les mirroirs et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void mirrors_intersections(const Line& line,
                               const Point& start);

    /**
     * Place les intersections avec les bombes et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void nukes_intersections(const Line& line,
                             const Point& start);

    /**
     * Place les intersections avec les cristaux et le rayon dans
     * le vecteur d'intersections.
     * @param line la droite du rayon.
     * @param start le point de départ du rayon.
     */
    void crystals_intersections(const Line& line,
                                const Point& start);

    /**
     * Trie les intersections dans l'ordre croissant selon leur distance.
     * @param start le point de départ du rayon.
     */
    void sort_intersections(const Point& start);

    /**
     * Vérifie l'existence de collisions entre un mirroir et
     * les éléments du jeu.
     * @param segment le segment du mirroir.
     * @param m le mirroir.
     * @return vrai si il y a une collision, faux sinon.
     */
    bool check_collisions(const LineSegment& segment, Mirror* m);
};


/* Fonctions inlines */

void Level::remove_crystal(const Crystal& c)
{
    std::vector<Crystal>::iterator position = std::find(crystals_.begin(), crystals_.end(), c);

    if (position != crystals_.end())
    {
        (*position).remove_observer(this);
        crystals_.erase(position);
    }

    compute_rays(); // On recompute après avoir supprimer un élément.
}

void Level::remove_lens(const Lens& l)
{
    std::vector<Lens>::iterator position = std::find(lenses_.begin(), lenses_.end(), l);

    if (position != lenses_.end())
    {
        (*position).remove_observer(this);
        lenses_.erase(position);
    }

    compute_rays();
}

void Level::remove_mirror(const Mirror& m)
{
    std::vector<Mirror>::iterator position = std::find(mirrors_.begin(), mirrors_.end(), m);

    if (position != mirrors_.end())
    {
        (*position).remove_observer(this);
        mirrors_.erase(position);
    }

    compute_rays();
}

void Level::remove_nuke(const Nuke& n)
{
    std::vector<Nuke>::iterator position = std::find(nukes_.begin(), nukes_.end(), n);

    if (position != nukes_.end())
    {
        (*position).remove_observer(this);
        nukes_.erase(position);
    }

    compute_rays();
}

void Level::remove_wall(const Wall& w)
{
    std::vector<Wall>::iterator position = std::find(walls_.begin(), walls_.end(), w);

    if (position != walls_.end())
    {
        (*position).remove_observer(this);
        walls_.erase(position);
    }

    compute_rays();
}

const Source& Level::source() const
{
    return source_;
}

void Level::set_source(const Source& value)
{
    source_ = value;
    source_.add_observer(this);
}

const Dest& Level::dest() const
{
    return dest_;
}

void Level::set_dest(const Dest& value)
{
    dest_ = value;
    dest_.add_observer(this);
}

const std::vector<Wall>& Level::walls() const
{
    return walls_;
}

const std::vector<Mirror>& Level::mirrors() const
{
    return mirrors_;
}

const std::vector<Crystal>& Level::crystals() const
{
    return crystals_;
}

const std::vector<Lens>& Level::lenses() const
{
    return lenses_;
}

const std::vector<Ray>& Level::rays() const
{
    return rays_;
}

void Level::set_rays(const std::vector<Ray>& value)
{
    rays_ = value;
}

void Level::set_walls(const std::vector<Wall>& value)
{
    walls_ = value;
    for (auto &i : walls_)
        i.add_observer(this);
}

void Level::set_crystals(const std::vector<Crystal>& value)
{
    crystals_ = value;
    for (auto &i : crystals_)
        i.add_observer(this);
}

void Level::set_nukes(const std::vector<Nuke>& value)
{
    nukes_ = value;
    for (auto &i : nukes_)
        i.add_observer(this);
}

void Level::set_lenses(const std::vector<Lens>& value)
{
    lenses_ = value;
    for (auto &i : lenses_)
        i.add_observer(this);
}

void Level::set_mirrors(const std::vector<Mirror>& value)
{
    mirrors_ = value;
    for (auto &i : mirrors_)
        i.add_observer(this);
}

const std::vector<Nuke> & Level::nukes() const
{
    return nukes_;
}

int Level::height() const
{
    return height_;
}

int Level::width() const
{
    return width_;
}

void Level::add_mirror(const Mirror& m)
{
    mirrors_.push_back(m);
    mirrors_.back().add_observer(this);
}

void Level::add_nuke(const Nuke& n)
{
    nukes_.push_back(n);
    nukes_.back().add_observer(this);
}

void Level::add_wall(const Wall& w)
{
    walls_.push_back(w);
    walls_.back().add_observer(this);
}

void Level::add_crystal(const Crystal& c)
{
    crystals_.push_back(c);
    crystals_.back().add_observer(this);
}

void Level::add_lens(const Lens& l)
{
    lenses_.push_back(l);
    lenses_.back().add_observer(this);
}

void Level::add_ray(const Ray& r)
{
    rays_.push_back(r);
}

bool Level::check_collisions() const
{
    return check_collisions_;
}

void Level::set_check_collisions(bool value)
{
    check_collisions_ = value;
}

bool Level::handle_dest() const
{
    return handle_dest_;
}

bool Level::handle_nukes() const
{
    return handle_nukes_;
}

void Level::set_handle_dest(bool value)
{
    handle_dest_ = value;
}

void Level::set_handle_nukes(bool value)
{
    handle_nukes_ = value;
}

bool Level::won() const
{
    return dest_.lighted_up();
}

bool Level::lost() const
{
    for (auto &i : nukes_)
    {
        if (i.lighted_up())
            return true;
    }

    return false;
}

#endif // LEVEL_H
