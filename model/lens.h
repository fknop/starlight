#ifndef LENS_H
#define LENS_H

#include <ostream>

#include "element.h"
#include "ellipse.h"
#include "point.h"


/**
 * Cette classe modélise les lentilles utilisées dans le jeu.
 * </p>
 * Une lentille est un objet rectangulaire qui ne laisse passer
 * les rayons lumineux que dans un certain intervalle de longueur
 * d'onde. Si un rayon lumineux se trouve dans l'intervalle de
 * longueur d'onde autorisé, il traverse la lentille sans subir
 * aucune modification. Sinon, la lentille se comporte comme un
 * mur.
 */
class Lens : public Element
{
    Point pos_;

    double width_;
    double height_;

    int wl_min_;
    int wl_max_;

  public:
    /**
     * Instancie une lentille à l'aide de toutes ses
     * caractéristiques.
     * @param p la position du coin supérieur gauche du
     *          rectangle modélisant la lentille.
     * @param w la largeur de la lentille.
     * @param h la hauteur de la lentille.
     * @param wlmin la longueur d'onde minimale des rayons
     *              autorisés à franchir la lentille.
     * @param wlmax la longueur d'onde maximale des rayons
     *              autorisés à franchir la lentille.
     */
    Lens(const Point& p, double w, double h, int wl_min, int wl_max);

    /**
     * Constructeur de copie.
     * @param lens la lentille à copier.
     */
    Lens(const Lens& lens);
    /**
     * Retourne la position du coin supérieur gauche du
     * rectangle modélisant la lentille.
     * @return la position du coin supérieur gauche du
     * rectangle modélisant la lentille
     */
    inline const Point & position() const;

    /**
     * Retourne la largeur de la lentille.
     * @return la largeur de la lentille.
     */
    inline double width() const;

    /**
     * Retourne la hauteur de la lentille.
     * @return la hauteur de la lentille.
     */
    inline double height() const;

    /**
     * Retourne la longueur d'onde minimale des rayons
     * autorisés à franchir la lentille.
     * @return la longueur d'onde minimale des rayons
     * autorisés à franchir la lentille.
     */
    inline int wl_max() const;

    /**
     * Retourne la longueur d'onde maximale des rayons
     * autorisés à franchir la lentille.
     * @return la longueur d'onde maximale des rayons
     * autorisés à franchir la lentille.
     */
    inline int wl_min() const;

    /**
     * Retourne une ellipse correspondante
     * à la lentille.
     * @return l'ellipse correspondante à la lentille.
     */
    Ellipse to_ellipse();

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques de la lentille
     * sous-jacente en console.
     * @return le flux dans lequel la lentille a été imprimée.
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Lens& m);

    bool operator==(const Lens& l) const;
};

/* Fonctions inlines */


const Point & Lens::position() const
{
    return pos_;
}

double Lens::width() const
{
    return width_;
}

double Lens::height() const
{
    return height_;
}

int Lens::wl_max() const
{
    return wl_max_;
}

int Lens::wl_min() const
{
    return wl_min_;
}

#endif // LENS_H
