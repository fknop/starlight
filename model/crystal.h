#ifndef CRYSTAL_H
#define CRYSTAL_H

#include <ostream>

#include "element.h"
#include "ellipse.h"
#include "point.h"

/**
 * Cette classe modélise les cristaux utilisés dans le jeu.
 * </p>
 * Un cristal est un objet circulaire centré en un point, et
 * d'un certain rayon.
 * </p>
 * Un rayon lumineux passant à travers un cristal modifie sa
 * longueur d'onde (en l'augmentant ou en la diminuant d'une
 * certaine valeur) mais pas sa trajectoire.
 */
class Crystal : public Element
{
    Point center_;
    double rad_;
    int mod_;

  public:
    /**
     * Instancie un cristal centré au point donné, d'un certain.
     * rayon et modifiant la longueur d'onde des rayons qui le
     * traversent d'une valeur donnée.
     * @param p le centre du cristal.
     * @param r le rayon du cristal.
     * @param m le modificateur de longueur d'onde du cristal.
     */
    Crystal(const Point& p, double r, int m);

    /**
     * Constructeur de copie.
     * @param crystal le cristal à copier.
     */
    Crystal(const Crystal& crystal);

    /**
     * Retourne la coordonnée du centre du cristal.
     * @return  la coordonnée du centre du cristal.
     */
    inline const Point& center() const;

    /**
     * Retourne le modificateur de longueur d'onde du cristal.
     * @return  le modificateur de longueur d'onde du cristal.
     */
    inline int modifier() const;

    /**
     * Retourne le rayon du cristal.
     * @return le rayon du cristal.
     */
    inline double radius() const;

    /**
     * Modifie la coordonée du centre du cristal.
     * @param c le nouveau centre du cristal.
     */
    inline void set_center(const Point &c);

    /**
     * Modifie le rayon du cristal.
     * @param rad le nouveau rayon du cristal.
     */
    inline void set_radius(double rad);

    /**
     * Modifie le modificateur de longueur d’onde du cristal.
     * @param mod le modificateur de longueur d’onde du cristal.
     */
    inline void set_modifier(double mod);

    Ellipse to_ellipse() const;

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher.
     * un récapitulatif des caractéristiques du cristal
     * sous-jacent en console.
     * @return le flux dans lequel le cristal a été imprimé.
     */
    friend std::ostream& operator<<(std::ostream&,
                                     const Crystal &);

    bool operator==(const Crystal& c) const;

};

/* Fonctions inlines */


const Point& Crystal::center() const
{
    return this->center_;
}

int Crystal::modifier() const
{
    return this->mod_;
}

double Crystal::radius() const
{
    return this->rad_;
}

void Crystal::set_center(const Point& c)
{
    center_ = c;
}

void Crystal::set_radius(double rad)
{
    rad_ = rad;
}

void Crystal::set_modifier(double mod)
{
    mod_ = mod;
}

#endif // CRYSTAL_H
