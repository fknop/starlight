#ifndef DEST_H
#define DEST_H

#include <ostream>

#include "element.h"
#include "point.h"
#include "rectangle.h"

/**
 * Cette classe modélise la destination utilisée dans le jeu.
 * </p>
 * Une destination est un objet carré qui, quand traversé par
 * un rayon lumineux, fait remporter la partie au joueur.
 */
class Dest : public Element
{
    Point pos_;
    double edge_;
    bool light_ {false};

  public:
    /**
     * Intancie une destination de position et rayon donné.
     * @param p le coin supérieur gauche du carré modélisant
     *        la destination.
     * @param e la longueur du côté du carré.
     */
    Dest(const Point & p, double e);

    Dest(const Dest &);

    /**
     * Retourne la position du coin supérieur gauche du carré.
     * modélisant la destination.
     * @return la position de la destination.
     */
    const Point & position() const;

    /**
     * Retourne la longueur du côté du carré.
     * @return la longueur du côté du carré.
     */
    double edge() const;

    /**
     * Retourne vrai si la destination est illuminée,
     * faux sinon.
     * @return vrai si la destination est illuminée,
     * faux sinon.
     */
    bool is_lighted_up() const;

    /**
     * Illumine la destination ou non.
     * @param vrai si la destination doit être illuminée,
     * faux sinon.
     */
    void set_lighted_up(const bool q);

    Rectangle to_rectangle();

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher.
     * un récapitulatif des caractéristiques de la destination
     * sous-jacente en console.
     * @return le flux dans lequel la destination a été imprimée.
     */
    friend std::ostream & operator<<(std::ostream & out,
                                     const Dest & s);
};

#endif // DEST_H
