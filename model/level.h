#ifndef LEVEL_H
#define LEVEL_H

#include "crystal.h"
#include "dest.h"
#include "lens.h"
#include "mirror.h"
#include "ray.h"
#include "source.h"
#include "wall.h"
#include "point.h"
#include "nuke.h"
#include "Line.h"

#include <vector>
#include <unordered_map>
#include "obs/observable.h"
#include "obs/observer.h"


struct Intersection
{
    Point point_;
    Element element_;
    Intersection(Point p, Element e)
        : point_{p}, element_{e} {}

    const Point& point() const
    {
        return point_;
    }

    const Element& element() const
    {
        return element_;
    }

};


/**
 * Modélise une carte telle qu'utilisée dans le jeu.
 * </p>
 * Une carte est un ensemble de composants tels que des murs,
 * des miroirs, etc.
 */
class Level : public Observable
{
    const double width_;
    const double height_;

    Source source_ {{.0, .0}, -1, 5, 600};
    Dest dest_ {{.0, .0}, 5};

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
    const Source& source() const;

    /**
     * Change la source de la carte.
     * @param value la nouvelle source.
     */
    void set_source(const Source& value);

    /**
     * Retourne la desination de la carte.
     * @return la destination de la carte.
     */
    const Dest& dest() const;

    /**
     * Change la destination de la carte.
     * @param value la destination de la carte.
     */
    void set_dest(const Dest& value);

    /**
     * Retourne l'ensemble des murs de la carte.
     * @return l'ensemble des murs de la carte.
     */
    const std::vector<Wall>& walls() const;

    /**
     * Retourne l'ensemble des miroirs de la carte.
     * @return l'ensemble des miroirs de la carte.
     */
    const std::vector<Mirror>& mirrors() const;

    /**
     * Retourne l'ensemble des cristaux de la carte.
     * @return l'ensemble des cristaux de la carte.
     */
    const std::vector<Crystal>& crystals() const;

    /**
     * Retourne l'ensemble des lentilles de la carte.
     * @return l'ensemble des lentilles de la carte.
     */
    const std::vector<Lens>& lenses() const;

    /**
     * Retourne l'ensemble des rayons de la carte.
     * @return l'ensemble des rayons de la carte.
     */
    const std::vector<Ray>& rays() const;

    const std::vector<Nuke>& nukes() const;

    /**
     * Change l'ensemble des rayons de la carte.
     * @param le nouvel ensemble de rayons de la carte.
     */
    void set_rays(const std::vector<Ray>& rays);

    void set_walls(const std::vector<Wall>& walls);

    void set_crystals(const std::vector<Crystal>& crystals);

    void set_nukes(const std::vector<Nuke>& nukes);

    void set_lenses(const std::vector<Lens>& lenses);

    void set_mirrors(const std::vector<Mirror>& mirrors);

    /**
     * Retourne la taille de la carte.
     * @return la taille de la carte.
     */
    int height();

    /**
     * Retourne la longueur de la carte.
     * @return la longueur de la carte.
     */
    int width();

    /**
     * Calcule les rayons lumineux de la carte.
     * </p>
     * Cette fonction doit être surchargée obligatoirement.
     */
    void compute_rays();

    void add_mirror(const Mirror& m);

    void add_nuke(const Nuke& n);

    void add_wall(const Wall& w);

    void add_crystal(const Crystal& c);

    void add_lens(const Lens& l);

    void add_ray(const Ray& r);

    void notify(Observable* o);


private:

    bool compute_ray(Line&, int wl);
    const Intersection& get_closest_intersection(Line& line);
};



#endif // LEVEL_H
