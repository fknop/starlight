#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "crystal.h"
#include "dest.h"
#include "lens.h"
#include "line.h"
#include "mirror.h"
#include "nuke.h"
#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "point.h"
#include "ray.h"
#include "source.h"
#include "wall.h"


struct Intersection
{
    Point* point_;
    Element* element_;

    Intersection(Point* p, Element* e)
    {
        point_ = p;
        element_ = e;
    }

    ~Intersection()
    {
        /* Pas de delete sur l'élément sinon
         * on le supprime de level
         */

    }

    Point* point() const
    {
        return this->point_;
    }

    Element* element() const
    {
        return this->element_;
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

    enum class State
    {
        WIN,
        LOSE,
        STOP,
        CONTINUE
    };


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

    void notify(Observable* o,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:

    /**
     * Permet de calculer la trajectoire d'un rayon.
     * @param line la droite du rayon.
     * @param wl la longueur d'onde du rayon.
     * @return l'état du jeu après avoir créer le rayon.
     */
    State compute_ray(Line& line, int wl);

    /**
     * Retourne l'intersection la plus proche du rayon avec un objet.
     * @param line la droite du rayon.
     * @return l'intersection la plus proche.
     */
    void get_intersections(const Line& line);

    /**
     * Calcule l'angle de reflexion d'un rayon sur un miroir.
     * @param startAngle l'angle de départ.
     * @param mirrorAngle l'inclinaison du miroir.
     * @return l'angle réfléchi.
     */
    double get_reflection_angle(double startAngle, double mirrorAngle);


    void dest_intersections(const Line& line,
                            std::vector<Intersection>& intersections,
                            std::vector<Point>& points);

    void walls_intersections(const Line& line,
                             std::vector<Intersection>& intersections,
                             Point** p);

    void lenses_intersections(const Line& line,
                              std::vector<Intersection>& intersections,
                              std::vector<Point>& points);

    void mirrors_intersections(const Line& line,
                               std::vector<Intersection>& intersections,
                               Point** p);

    void nukes_intersections(const Line& line,
                             std::vector<Intersection>& intersections,
                             std::vector<Point>& points);

    void crystals_intersections(const Line& line,
                                std::vector<Intersection>& intersections,
                                std::vector<Point>& points);

    void erase_wrongs_intersections(const Line& line,
                                    std::vector<Intersection>& intersections);

    void sort_intersections(const Line& line,
                            std::vector<Intersection> &intersections);

    bool mirror_intersects_elements(Mirror *mirror);
};

/* Fonctions inlines */

const Source& Level::source() const
{
    return this->source_;
}

void Level::set_source(const Source& value)
{
    this->source_ = value;
    this->source_.add_observer(this);
}

const Dest& Level::dest() const
{
    return this->dest_;
}

void Level::set_dest(const Dest& value)
{
    this->dest_ = value;
}

const std::vector<Wall>& Level::walls() const
{
    return this->walls_;
}

const std::vector<Mirror>& Level::mirrors() const
{
    return this->mirrors_;
}

const std::vector<Crystal>& Level::crystals() const
{
    return this->crystals_;
}

const std::vector<Lens>& Level::lenses() const
{
    return this->lenses_;
}

const std::vector<Ray>& Level::rays() const
{
    return this->rays_;
}

void Level::set_rays(const std::vector<Ray>& value)
{
    this->rays_ = value;
}

void Level::set_walls(const std::vector<Wall>& value)
{
    this->walls_ = value;
}

void Level::set_crystals(const std::vector<Crystal>& value)
{
    this->crystals_ = value;
}

void Level::set_nukes(const std::vector<Nuke>& value)
{
    this->nukes_ = value;
}

void Level::set_lenses(const std::vector<Lens>& value)
{
    this->lenses_ = value;
}

void Level::set_mirrors(const std::vector<Mirror>& value)
{
    this->mirrors_ = value;
    for (auto &mirror : mirrors_)
        mirror.add_observer(this);
}

const std::vector<Nuke> & Level::nukes() const
{
    return this->nukes_;
}

int Level::height() const
{
    return this->height_;
}

int Level::width() const
{
    return this->width_;
}

void Level::add_mirror(const Mirror& m)
{
    this->mirrors_.push_back(m);
    this->mirrors_.back().add_observer(this);
}

void Level::add_nuke(const Nuke& n)
{
    this->nukes_.push_back(n);
}

void Level::add_wall(const Wall& w)
{
    this->walls_.push_back(w);
}

void Level::add_crystal(const Crystal& c)
{
    this->crystals_.push_back(c);
}

void Level::add_lens(const Lens& l)
{
    this->lenses_.push_back(l);
}

void Level::add_ray(const Ray& r)
{
    this->rays_.push_back(r);

}

#endif // LEVEL_H
