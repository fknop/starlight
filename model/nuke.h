#ifndef NUKE_H
#define NUKE_H

#include <ostream>

#include "element.h"
#include "ellipse.h"
#include "point.h"
#include "obs/observable.h"

/**
 * Cette classe modélise les bombes utilisées dans le jeu.
 * </p>
 * Une bombe est un objet circulaire qui, si illuminé par
 * un rayon, fait perdre la partie au joueur.
 */
class Nuke : public Element, public Observable
{
    Point pos_;
    double rad_;
    bool lighted_up_ {false};

  public:
    /**
     * Instancie une bombe en une position donnée avec un rayon
     * déterminé.
     * @param p la position de la bombe.
     * @param r le rayon de la bombe.
     */
    Nuke(const Point& p, double r);

    /**
     * Retourne la position de la bombe.
     * @return la position de la bombe.
     */
    inline const Point& position() const;

    /**
     * Retourne le rayon de la bombe.
     * @return le rayon de la bombe.
     */
    inline double radius() const;

    /**
     * Retourne vrai si la bombe est illuminée, faux sinon.
     * @return vrai si la bombe est illuminée, faux sinon.
     */
    inline bool lighted_up() const;

    /**
     * Illumine la bombe ou non.
     * @param q vrai pour illuminer la bombe, faux sinon.
     */
    inline void set_lighted_up(bool q);

    /**
     * Renvoie l'ellipse correspondante à la bombe.
     * @return l'ellipse correspondante à la bombe.
     */
    Ellipse to_ellipse();

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques de la bombe.
     * sous-jacente en console.
     * @return le flux dans lequel la bombe a été imprimée.
     */
    friend std::ostream & operator<<(std::ostream& out,
                                     const Nuke& s);
};

/* Fonctions inlines */

const Point& Nuke::position() const
{
    return this->pos_;
}

double Nuke::radius() const
{
    return this->rad_;
}

bool Nuke::lighted_up() const
{
    return this->lighted_up_;
}

void Nuke::set_lighted_up(bool q)
{
    this->lighted_up_ = q;
    notify_all("LIGHTED_UP");
}

#endif // NUKE_H
