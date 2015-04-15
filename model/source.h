#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>

#include "model/element.h"
#include "model/point.h"
#include "model/rectangle.h"

#include "obs/observable.h"

/**
 * Modélise la source lumineuse utilisée dans le jeu.
 * </p>
 * La source est un objet carré qui, si allumée, émet un rayon
 * lumineux de longueur d'onde donnée dont l'angle ne peut pas
 * être changé.
 * </p>
 * Le rayon lumineux est émis depuis la position, i.e., le coin
 * supérieur gauche, de la source.
 */
class Source : public Observable, public Element
{
    bool on_ {false};
    Point pos_;
    double alpha_;
    double edge_;
    int wavelength_;

  public:
    /**
     * Instancie une nouvelle source de position, de côté et de
     * longueur d'onde donnés.
     * </p>
     * La position dénote la coordonnée du coin supérieur gauche
     * du carré modélisant la source.
     * </p>
     * La source est initialement éteinte.
     * </p> Si la longueur d'onde du rayon lumineux émis n'est
     * pas comprise entre 360 nm et 830 nm, elle est réglée
     * sur 600 nm.
     * @param p la position de la source.
     * @param e la longueur du côté de la source.
     * @param a l’angle d’émission de la source.
     * @param wl la longueur d'onde du rayon lumineux émis.
     * @see Ray::WL_MIN
     * @see Ray::WL_MAX
     * @see Ray::WL_DFT
     */
    Source(const Point& p, double e, double a, int wl);

    /**
     * Retourne la coordonnée du coin supérieur gauche du carré
     * modélisant la source.
     * @return la coordonnée du coin supérieur gauche du carré
     * modélisant la source.
     */
    inline const Point& pos() const;

    /**
     * Retourne l'angle du rayon émis.
     * @return l'angle du rayon émis.
     */
    inline double angle() const;

    /**
     * Retourne la longueur du côté du carré.
     * @return la longueur du côté du carré.
     */
    inline int edge() const;

    /**
     * Retourne la longueur d'onde du rayon émis.
     * @return la longueur d'onde du rayon émis.
     */
    inline int wavelength() const;

    /**
     * Retourne vrai si la source émet un rayon lumineux,
     * faux sinon.
     * @return vrai si la source émet un rayon lumineux,
     * faux sinon.
     */
    inline bool on() const;

    /**
     * Allume ou éteint la source.
     * @param q vrai si la source doit être allumée,
     * faux sinon.
     */
    inline void set_on(bool q);

    /**
     * Modifie la coordonnée du coin supérieur gauche du carré
     * représenant la source.
     * @param p la nouvelle coordonnée du coin supérieur gauche du carré
     * représentant la source.
     */
    inline void set_pos(Point p);

    /**
     * Modifie la longueur du côté du carré représentant la source.
     * @param edge la nouvelle longueur du côté du carré représentant
     * la source.
     */
    inline void set_edge(double edge);

    /**
     * Modifie l’angle du rayon émis.
     * @param angle le nouvel angle du rayon émis.
     */
    inline void set_alpha(double angle);

    /**
     * Modifie la longueur d’onde du rayon émis.
     * @param wl la nouvelle longueur d’onde du rayon émis.
     */
    inline void set_wavelength(double wl);

    /**
     * Retourne le rectangle correspondant à la source.
     * @return le rectangle correspondant à la source.
     */
    Rectangle to_rectangle();

    /**
     * Déplace la source.
     * @param x le déplacement sur l'axe des x.
     * @param y le déplacement sur l'axe des y.
     */
    void translate(double x, double y);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques de la source
     * sous-jacente en console.
     * @return le flux dans lequel la source a été imprimée.
     */
    friend std::ostream & operator<<(std::ostream& out,
                                     const Source& s);
};

/* Fonctions inlines */


const Point& Source::pos() const
{
    return this->pos_;
}

double Source::angle() const
{
    return this->alpha_;
}

int Source::edge() const
{
    return this->edge_;
}

int Source::wavelength() const
{
    return this->wavelength_;
}

bool Source::on() const
{
    return this->on_;
}

void Source::set_on(bool q)
{
    this->on_ = q;
    notify_all(std::string("SOURCE_ON"));
}

void Source::set_pos(Point p)
{
    this->pos_ = p;
}

void Source::set_edge(double edge)
{
    this->edge_ = edge;
}

void Source::set_alpha(double a)
{
    this->alpha_ = a;
}

void Source::set_wavelength(double wl)
{
    this->wavelength_ = wl;
}

#endif // SOURCE_H
