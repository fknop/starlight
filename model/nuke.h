#ifndef NUKE_H
#define NUKE_H

#include <ostream>

#include "element.h"
#include "ellipse.h"
#include "point.h"


/**
 * Cette classe modélise les bombes utilisées dans le jeu.
 * </p>
 * Une bombe est un objet circulaire qui, si illuminé par
 * un rayon, fait perdre la partie au joueur.
 */
class Nuke : public Element
{
    Point pos_;
    double rad_;
    bool light_ {false};

  public:
    /**
     * Instancie une bombe en une position donnée avec un rayon
     * déterminé.
     * @param p la position de la bombe.
     * @param r le rayon de la bombe.
     */
    Nuke(const Point & p, double r);

    /**
     * Retourne la position de la bombe.
     * @return la position de la bombe.
     */
    const Point & position() const;

    /**
     * Retourne le rayon de la bombe.
     * @return le rayon de la bombe.
     */
    double radius() const;

    /**
     * Retourne vrai si la bombe est illuminée, faux sinon.
     * @return vrai si la bombe est illuminée, faux sinon.
     */
    bool is_lighted_up() const;

    /**
     * Illumine la bombe ou non.
     * @param q vrai pour illuminer la bombe, faux sinon.
     */
    void set_lighted_up(bool q);

    Ellipse to_ellipse();

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques de la bombe.
     * sous-jacente en console.
     * @return le flux dans lequel la bombe a été imprimée.
     */
    friend std::ostream & operator<<(std::ostream & out,
                                     const Nuke & s);
};

#endif // NUKE_H
