#ifndef DEST_H
#define DEST_H

#include <ostream>

#include "model/element.h"
#include "model/point.h"
#include "model/rectangle.h"


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
    bool lighted_up_ {false};

  public:
    /**
     * Intancie une destination de position et rayon donné.
     * @param p le coin supérieur gauche du carré modélisant
     *        la destination.
     * @param e la longueur du côté du carré.
     */
    Dest(const Point& p, double e);

    /**
     * Constructeur de copie.
     * @param dest la destination à copier.
     */
    Dest(const Dest& dest);

    /**
     * Retourne la position du coin supérieur gauche du carré.
     * modélisant la destination.
     * @return la position de la destination.
     */
    inline const Point& pos() const;

    /**
     * Retourne la longueur du côté du carré représentant la destination.
     * @return la longueur du côté du carré représentant la destination.
     */
    inline double edge() const;

    /**
     * Retourne vrai si la destination est illuminée,
     * faux sinon.
     * @return vrai si la destination est illuminée,
     * faux sinon.
     */
    inline bool lighted_up() const;

    /**
     * Illumine la destination ou non.
     * @param value vrai si la destination doit être illuminée,
     * faux sinon.
     */
    inline void set_lighted_up(const bool value);

    /**
     * Modifie la position du coin supérieur gauche du carré.
     * @param pos la nouvelle position du coin supérieur gauche
     * de la destination.
     */
    inline void set_pos(const Point& pos);

    /**
     * Modifie la longueur du côté du carré représentant la destination.
     * @param edge la nouvelle longueur du côté de la destination.
     */
    inline void set_edge(const double edge);

    /**
     * Retourne le rectangle correspondant à la destination.
     * @return le rectangle correspondant à la destination.
     */
    Rectangle to_rectangle();

    /**
     * Déplace la destination.
     * @param x le déplacement sur l'axe x.
     * @param y le déplacement sur l'axe y.
     */
    void translate(const double x, const double y);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher.
     * un récapitulatif des caractéristiques de la destination
     * sous-jacente en console.
     * @return le flux dans lequel la destination a été imprimée.
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Dest& s);
};

/* Fonction inlines */

const Point& Dest::pos() const
{
    return pos_;
}

double Dest::edge() const
{
    return edge_;
}

bool Dest::lighted_up() const
{
    return lighted_up_;
}

void Dest::set_lighted_up(const bool value)
{
    lighted_up_ = value;
    notify_all(std::string("LIGHTED_UP"));
}

void Dest::set_pos(const Point& pos)
{
    pos_ = pos;
}

void Dest::set_edge(const double edge)
{
    edge_ = edge;
}

#endif // DEST_H
