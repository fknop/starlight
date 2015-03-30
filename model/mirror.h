#ifndef MIRROR_H
#define MIRROR_H

#include "point.h"

#include <ostream>
#include "polarpoint.h"
#include "element.h"

/**
 * Cette classe modélise les miroirs utilisés dans le jeu.
 * </p>
 * Un miroir est un segment de droite dont la propriété est
 * de réfléchir la lumière d'un seul côté uniquement. Si un
 * rayon lumineux touche un miroir du côté non réfléchissant,
 * le miroir se comporte comme un mur.
 * </p>
 * Les miroirs sont capables d'être déplacés et pivotés dans
 *  une certaine limite.
 */
class Mirror : public Element
{
    Point pivot;
    double length;
    double xpad;
    double xMin {.0};
    double xMax {.0};
    double yMin {.0};
    double yMax {.0};
    double alpha;
    double alphaMin {.0};
    double alphaMax {.0};

  public:
    /**
     * Instancie un miroir en une position donnée, d'une certaine
     * longueur et orienté d'un certain angle.
     * </p>
     * Comme dans ce constructeur les limites de déplacement et
     * de rotation du miroir ne sont pas définies, ce miroir
     * peut se déplacer et pivoter librement.
     * @param p la position (et le point de pivot) du miroir.
     * @param len la longueur du miroir.
     * @param x le décalage du pivot par rapport au bord gauche
     *          du miroir.
     * @param a l'angle d'inclinaison du miroir.
     */
    Mirror(const Point & p, double len, double x, double a);

    /**
     * Instancie un miroir en une position donnée, d'une certaine
     * longueur et orienté d'un certain angle.
     * </p>
     * Ce constructeur permet également aux miroirs de pivoter
     * dans une certaine limite.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que
     * a < b, le miroir pivote dans le sens horloger, si a = b le
     * miroir ne peut pas pivoter, si a > b, le miroir
     * pivote dans le sens anti-horloger.
     * @param p la position (et le point de pivot) du miroir.
     * @param len la longueur du miroir.
     * @param x le décalage du pivot par rapport au bord gauche
     *          du miroir.
     * @param a l'angle d'inclinaison du miroir.
     * @param min l'abscisse et l'ordonnée minimum du miroir.
     * @param max l'abscisse et l'ordonnée maximum du miroir.
     * @param amin l'angle d'inclinaison minimum du miroir.
     * @param amax l'angle d'inclinaison maximum du miroir.
     */
    Mirror(const Point & p, double x, double len, double a, Point min,
           Point max, double amin, double amax);

    /**
     * Retourne la position (et le pivot) du miroir.
     * @return la position (et le pivot) du miroir.
     */
    const Point & getPivot() const;

    /**
     * Retourne la longueur du miroir.
     * @return la longueur du miroir
     */
    double getLength() const;

    /**
     * Retourne le décalage du pivot par rapport au bord gauche
     * du miroir.
     * @return le décalage du pivot par rapport au bord gauche
     * du miroir.
     */
    double getXPad() const;

    /**
     * Retourne l'inclinaison du miroir.
     * @return l'inclinaison du miroir.
     */
    double getAngle() const;

    /**
     * Retourne l'inclinaison minimum du miroir.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que
     * a < b, le miroir pivote dans le sens horloger, si a = b
     * le miroir ne peut pas pivoter, si a > b, le miroir pivote
     * dans le sens anti-horloger. Si a = b = 0, le miroir peut
     * être pivoté librement.
     * @return l'inclinaison minimum du miroir.
     */
    double getMinAngle() const;

    /**
     * Retourne l'inclinaison maximum du miroir.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel
     * que a < b, le miroir pivote dans le sens horloger, si
     * a = b le miroir ne peut pas pivoter, si a > b, le miroir
     * pivote dans le sens anti-horloger. Si a = b = 0, le miroir
     * peut être pivoté librement.
     * @return l'inclinaison minimum du miroir.
     */
    double getMaxAngle() const;

    /**
     * Retourne la position minimum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
     * @return la position minimum du miroir.
     */
    Point getMinPivot() const;

    /**
     * Retourne la position maximum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
     * @return la position maximum du miroir.
     */
    Point getMaxPivot() const;

    /**
     * Déplace le miroir en la position donnée, si c'est
     * autorisé. Retourne vrai si le déplacement a été
     * effectué correctement, retourne faux sinon.
     * @return vrai si le déplacement a été effectué
     * correctement, retourne faux sinon.
     * @see Mirror::getPivot()
     */
    bool setPivot(const Point &);

    /**
     * Pivote le miroir sur un angle donné, si c'est
     * autorisé. Retourne vrai si la rotation a été effectuée
     * correctement, retourne faux sinon.
     * @return vrai si la rotation a été effectuée
     * correctement, retourne faux sinon.
     * @see Mirror::getAngle()
     */
    bool setAngle(double);

    /**
     * Retoune vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     * @return vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     * @see Mirror::getAngle()
     */
    bool checkAngleRange(double) const;

    /**
     * Retoune vrai si le miroir peut être déplacé en la
     * position donnée, retourne faux sinon.
     * @return vrai si le miroir peut être déplacé en
     * la position donnée, retourne faux sinon.
     * @see Mirror::getPivot()
     */
    bool checkPivotRange(const Point &) const;

    /**
     * Modifie l'inclinaison de l'angle
     * @param l'inclinaison à ajouter.
     */
    void rotate(double angle);


    /**
     * Déplace le pivot par rapport à une ordonnée et une abscisse.
     * @param x l'abscisse.
     * @param y l'ordonnée.
     */
    void translate(double x, double y);

    /**
     * Surcharge l'opérateur de flux de sortie pour
     * afficher un récapitulatif des caractéristiques du
     * miroir sous-jacent en console.
     * @return le flux dans lequel le miroir a été imprimé
     */
    friend std::ostream & operator<<(std::ostream & out,
                                     const Mirror & m);
};

#endif // MIRROR_H
