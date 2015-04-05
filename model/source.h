#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>

#include "element.h"
#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "point.h"


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
class Source : public Observable
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
    inline const Point& position() const;

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

    void notify_all();

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


const Point& Source::position() const
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
    notify_all();
}

#endif // SOURCE_H
