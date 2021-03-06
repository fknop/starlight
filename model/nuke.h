#ifndef NUKE_H
#define NUKE_H

#include <ostream>

#include "model/element.h"
#include "model/ellipse.h"
#include "model/point.h"

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
    bool lighted_up_ {false};

  public:
    /**
     * Instancie une bombe en une position donnée avec un rayon
     * déterminé.
     * @param p la position de la bombe.
     * @param r le rayon de la bombe.
     * @throws std::string si le rayon est plus petit ou égal à zéro.
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
     * Modifie la position de la bombe.
     * @param p la nouvelle position de la bombe.
     */
    inline void set_pos(Point p);

    /**
     * Modifie le rayon de la bombe si celui-ci est correct.
     * @param r le nouveau rayon de la bombe.
     * @return vrai si le rayon est correct, faux sinon.
     */
    inline bool set_radius(double r);

    /**
     * Renvoie l'ellipse correspondante à la bombe.
     * @return l'ellipse correspondante à la bombe.
     */
    Ellipse to_ellipse();

    /**
     * Déplace la bombe.
     * @param x le déplacement sur l'axe des x.
     * @param y le déplacement sur l'axe des y.
     */
    void translate(double x, double y);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques de la bombe.
     * sous-jacente en console.
     * @return le flux dans lequel la bombe a été imprimée.
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Nuke& s);

    /**
     * Redéfinition de l'opérateur d'égalité.
     * Retourne vrai si les bombes sont égales, faux sinon.
     * @param n une autre bombe.
     * @return vrai si les bombes sont égales, faux sinon.
     */
    bool operator==(const Nuke& n) const;

};

/* Fonctions inlines */

const Point& Nuke::position() const
{
    return pos_;
}

double Nuke::radius() const
{
    return rad_;
}

bool Nuke::lighted_up() const
{
    return lighted_up_;
}

void Nuke::set_lighted_up(bool q)
{
    lighted_up_ = q;
    notify_all(std::string("LIGHTED_UP"));
}

void Nuke::set_pos(Point p)
{
    pos_ = p;
}

bool Nuke::set_radius(double r)
{
    bool b {r > 0};
    if (b)
        rad_ = r;
    return b;
}

#endif // NUKE_H
