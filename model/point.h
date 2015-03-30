#ifndef POINT_H
#define POINT_H

#include <iostream>



/**
 * Cette classe modélise un simple point de coordonnées réelles
 * utilisés pour modéliser les positions des objets dans le jeu.
 */
class Point
{
    double x {.0};
    double y {.0};

  public:
    /**
     * Instancie le point (0,0)
     */
    Point() = default;

    /**
     * Instancie le point de coordonnées spécifiées.
     * @param x l'abscisse du point.
     * @param y l'ordonnée du point.
     */
    Point(double x, double y);

    /**
     * Constructeur de recopie.
     * @param p le point à recopier.
     */
    Point(const Point& p);

    /**
     * Retourne l'abscisse du point.
     * @return l'abscisse du point.
     */
    double getX() const;

    /**
     * Retourne l'ordonnée du point.
     * @return l'ordonnée du point.
     */
    double getY() const;

    /**
     * Déplace le point en l'abscisse donnée.
     * @param x l'abscisse où déplacer le point.
     */
    void setX(double x);

    /**
     * Déplace le point en l'ordonnée donnée.
     * @param y l'ordonnée où déplacer le point.
     */
    void setY(double y);

    /**
     * Déplace le point en la coordonnée donnée.
     * @param x l'abscisse où déplacer le point.
     * @param y l'ordonnée où déplacer le point.
     */
    void setLocation(double x, double y);

    /**
     * Retourne la distance entre deux points.
     * @param p l'autre point avec lequel on calcule la distance.
     * @return la distance entre les deux points.
     */
    double distance(const Point &p);



    /**
     * Redéfinit l'opérateur <.
     * Renvoie vrai si une des coordonnées est plus petite que
     * l'une des coordonnées d'un autre point.
     * @param p1 un premier point.
     * @param p2 un deuxième point.
     * @return vrai si l'une des coordonnées de p1 est plus petite que
     * l'une des coordonnées de p2.
     */
    friend bool operator <(const Point& p1, const Point& p2);


    /**
     * Surcharge de l'opérateur d'assignation.
     * Assigne les coordonnées d'un point au point courant.
     * @param p1 le point que l'on copie.
     * @return l'objet courant.
     */
    const Point& operator =(const Point& p1);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques du point sous-jacent en
     * console.
     * @return le flux dans lequel le point a été imprimé.
     */
    friend std::ostream & operator<<(std::ostream & out,
                                     const Point & p);


    /**
     * Surcharge de l'opérateur d'égalité.
     * @return vrai si les coordonnées d'un point sont égales
     * aux coordonnées d'un autre point.
     */
    friend bool operator==(const Point&, const Point&);

};

#endif // POINT_H
