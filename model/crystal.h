#ifndef CRYSTAL_H
#define CRYSTAL_H

#include <ostream>

#include "element.h"
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
    Crystal(const Point & p, double r, int m);

    Crystal(const Crystal &);

    /**
     * Retourne la coordonnée du centre du cristal.
     * @return  la coordonnée du centre du cristal.
     */
    const Point & center() const;

    /**
     * Retourne le modificateur de longueur d'onde du cristal.
     * @return  le modificateur de longueur d'onde du cristal.
     */
    int modifier() const;

    /**
     * Retourne le rayon du cristal.
     * @return le rayon du cristal.
     */
    double radius() const;

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher.
     * un récapitulatif des caractéristiques du cristal
     * sous-jacent en console.
     * @return le flux dans lequel le cristal a été imprimé.
     */
    friend std::ostream & operator<<(std::ostream &,
                                     const Crystal &);

};

#endif // CRYSTAL_H
