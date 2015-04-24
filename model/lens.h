#ifndef LENS_H
#define LENS_H

#include <ostream>

#include "model/element.h"
#include "model/ellipse.h"
#include "model/point.h"
#include "model/ray.h"

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
     * @param wl_min la longueur d'onde minimale des rayons
     *              autorisés à franchir la lentille.
     * @param wl_max la longueur d'onde maximale des rayons
     *              autorisés à franchir la lentille.
     * @throws std::string si wl_min est plus petit que RAY::WL_MIN
     * ou si wl_max est plus grand que Ray::WL_MAX ou si
     * wl_min est plus grand que wl_max ou si la longueur et la hauteur sont
     * inférieurs ou égaux à zéro.
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
    inline const Point& position() const;

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
     * Modifie la position de la lentille.
     * @param pos la nouvelle position de la lentille.
     */
    inline void set_pos(const Point& pos);

    /**
     * Modifie la largeur de la lentille si celle-ci est plus grande
     * que zéro.
     * @param w la nouvelle largeur de la lentille.
     * @return vrai si la longueur est correcte, faux sinon.
     */
    inline bool set_width(const double w);

    /**
     * Modifie la hauteur de la lentille si celle-ci est plus grande
     * que zéro.
     * @param h la nouvelle hauteur de la lentille.
     * @return vrai si la hauteur est correcte, faux sinon.
     */
    inline bool set_height(const double h);

    /**
     * Modifie la longueur d’onde minimale de la lentille si
     * celle-ci est correcte.
     * @param wl_min la nouvelle longueur d’onde minimale.
     * @return vrai si la longueur d'onde minimale est correcte,
     * faux sinon.
     */
    inline bool set_wl_min(const double wl_min);

    /**
     * Modifie la longueur d’onde maximale de la lentille si
     * celle-ci est correcte.
     * @param wl_max la nouvelle longueur d’onde maximale.
     * @return vrai si la longueur d'onde maximale est correcte,
     * faux sinon.
     */
    inline bool set_wl_max(const double wl_max);

    /**
     * Retourne une ellipse correspondante
     * à la lentille.
     * @return l'ellipse correspondante à la lentille.
     */
    Ellipse to_ellipse();

    /**
     * Déplace la lentille.
     * @param x le déplacement sur l'axe x.
     * @param y le déplacement sur l'axe y.
     */
    void translate(const double x, const double y);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques de la lentille
     * sous-jacente en console.
     * @return le flux dans lequel la lentille a été imprimée.
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Lens& m);

    /**
     * Redéfinition de l'opérateur d'égalité, retourne vrai
     * si les lentilles sont égales.
     * @param l une lentille.
     * @return vrai si les lentilles sont égales, faux sinon.
     */
    bool operator==(const Lens& l) const;
};

/* Fonctions inlines */


const Point& Lens::position() const
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

void Lens::set_pos(const Point& pos)
{
    pos_ = pos;
}

bool Lens::set_width(const double w)
{
    bool b {w > 0};
    if (b)
        width_ = w;
    return b;
}

bool Lens::set_height(const double h)
{
    bool b {h > 0};
    if (b)
        height_ = h;
    return b;
}

bool Lens::set_wl_min(const double wl_min)
{
    bool b {wl_min >= Ray::WL_MIN && wl_min < wl_max_};
    if (b)
        wl_min_ = wl_min;
    return b;
}

bool Lens::set_wl_max(const double wl_max)
{
    bool b {wl_max < Ray::WL_MAX && wl_max > wl_min_};
    if (b)
        wl_max_ = wl_max;
    return b;
}

#endif // LENS_H
