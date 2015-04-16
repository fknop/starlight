#ifndef RAY_H
#define RAY_H

#include <iostream>

#include "model/element.h"
#include "model/point.h"


/**
 * Cette classe modélise les rayons lumineux, concept central du jeu.
 * </p>
 * Un rayon lumineux est un segment de droite muni d'une longueur
 * d'onde.
 */
class Ray
{
    Point start_;
    Point end_;
    int wavelength_;

  public:
    /**
     * Longueur d'onde minimale autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde minimum (en nm) du
     * spectre visible de la lumière.
     */
    static constexpr int WL_MIN {360};

    /**
     * Longueur d'onde maximale autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde maximum (en nm) du
     * spectre visible de la lumière.
     */
    static constexpr int WL_MAX {830};

    /**
     * Longueur d'onde par défaut pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde (en nm) de la couleur
     * orangé-rouge du spectre visible de la lumière.
     */
    static constexpr int WL_DFT {600};

    /**
     * Instancie un rayon lumineux de début et de fin donnés, et de
     * longueur d'onde 600 nm.
     * @param p1 le début du rayon lumineux.
     * @param p2 la fin du rayon lumineux.
     */
    Ray(const Point& p1, const Point& p2);

    /**
     * Instancie un rayon lumineux de début et de fin donnés, et de
     * longueur d'onde spécifiée.
     * </p>
     * Si la longueur d'onde spécifiée ne rentre pas dans les valeurs
     * autorisées, elle est automatiquement réglée sur WL_DFT nm.
     * @param p1 le début du rayon lumineux.
     * @param p2 la fin du rayon lumineux.
     * @param f la longueur d'onde du rayon lumineux.
     * @see Ray::WL_MIN
     * @see Ray::WL_MAX
     * @see Ray::WL_DFT
     */
    Ray(const Point& p1, const Point& p2, int wl);

    /**
     * Retourne le début du rayon.
     * @return le début du rayon.
     */
    inline const Point& start() const;

    /**
     * Retourne la fin du rayon.
     * @return la fin du rayon.
     */
    inline const Point& end() const;

    /**
     * Retourne la longueur d'onde du rayon.
     * @return la longueur d'onde du rayon.
     */
    inline int wavelength() const;

    /**
     * Change la coordonnée du début du rayon.
     * @param p la nouvelle coordonnée du début du rayon.
     */
    inline void set_start(const Point& p);

    /**
     * Change la coordonnée de la fin du rayon.
     * @param p la nouvelle coordonnée de la fin du rayon.
     */
    inline void set_end(const Point& p);

    /**
     * Change la longueur d'onde du rayon. Si la longueur d'onde
     * spécifiée est en dehors des limites autorisées, laisse la
     * longueur d'onde inchangée.
     * </p> La longueur d'onde doit être comprise entre 360 et 830 nm.
     * @param f la nouvelle longueur d'onde du rayon
     * @return vrai si la longueur d'onde a bel et bien été changée,
     * retourne faux sinon.
     */
    inline bool set_wavelength(int wl);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques du rayon sous-jacent en
     * console.
     * @return le flux dans lequel le rayon a été imprimé.
     */
    friend std::ostream& operator<<(std::ostream& out, const Ray& p);
};

/* Fonctions inlines */


const Point& Ray::start() const
{
    return start_;
}

const Point& Ray::end() const
{
    return end_;
}

int Ray::wavelength() const
{
    return wavelength_;
}

void Ray::set_start(const Point& p)
{
    start_ = p;
}

void Ray::set_end(const Point& p)
{
    end_ = p;
}

bool Ray::set_wavelength(int wl)
{
    bool r = ((wl >= WL_MIN) && (wl <= WL_MAX));
    if (r)
        wavelength_ = wl;

    return r;
}


#endif // RAY_H
