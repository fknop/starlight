#ifndef LEVEL_H
#define LEVEL_H

#include "crystal.h"
#include "dest.h"
#include "lens.h"
#include "mirror.h"
#include "ray.h"
#include "source.h"
#include "wall.h"
#include "point.h"
#include "nuke.h"

#include <vector>


/**
 * Modélise une carte telle qu'utilisée dans le jeu.
 * </p>
 * Une carte est un ensemble de composants tels que des murs,
 * des miroirs, etc.
 */
class Level
{
    const int width;
    const int height;

    Source s {{0, 0}, -1, 5, 600};
    Dest d {{0, 0}, 5};

    std::vector<Wall> walls;
    std::vector<Mirror> mirrors;
    std::vector<Crystal> crystals;
    std::vector<Lens> lenses;
    std::vector<Ray> rays;
    std::vector<Nuke> nukes;

  public:

    /**
     * Instancie une carte de largeur et hauteur donnée.
     * </p>
     * Quand une carte est créée, quatre murs dénotant ses bords sont
     *  automatiquement ajoutés à la carte.
     * </p>
     * La source et la destination sont initialisées à des valeurs
     * par défaut inutilisables.
     * Vous devez manuellement initialiser la source et la destination
     * via les fonctions
     * appropriées.
     * @param w la largeur de la carte.
     * @param h la hauteur de la carte.
     */
    Level(int w, int h);

    /**
     * Retourne la source de la carte.
     * @return la source de la carte.
     */
    const Source & getSource() const;

    /**
     * Change la source de la carte.
     * @param value la nouvelle source.
     */
    void setSource(const Source & value);

    /**
     * Retourne la desination de la carte.
     * @return la destination de la carte.
     */
    const Dest & getDestination() const;

    /**
     * Change la destination de la carte.
     * @param value la destination de la carte.
     */
    void setDestination(const Dest & value);

    /**
     * Retourne l'ensemble des murs de la carte.
     * @return l'ensemble des murs de la carte.
     */
    const std::vector<Wall> & getWalls() const;

    /**
     * Retourne l'ensemble des miroirs de la carte.
     * @return l'ensemble des miroirs de la carte.
     */
    const std::vector<Mirror> & getMirrors() const;

    /**
     * Retourne l'ensemble des cristaux de la carte.
     * @return l'ensemble des cristaux de la carte.
     */
    const std::vector<Crystal> & getCrystals() const;

    /**
     * Retourne l'ensemble des lentilles de la carte.
     * @return l'ensemble des lentilles de la carte.
     */
    const std::vector<Lens> & getLenses() const;

    /**
     * Retourne l'ensemble des rayons de la carte.
     * @return l'ensemble des rayons de la carte.
     */
    const std::vector<Ray> & getRays() const;

    const std::vector<Nuke> & getNukes() const;

    /**
     * Change l'ensemble des rayons de la carte.
     * @param le nouvel ensemble de rayons de la carte.
     */
    void setRays(const std::vector<Ray>&);

    void setWalls(const std::vector<Wall> &);

    void setCrystals(const std::vector<Crystal>&);

    void setNukes(const std::vector<Nuke>&);

    void setLenses(const std::vector<Lens>&);

    void setMirrors(const std::vector<Mirror>&);

    /**
     * Retourne la taille de la carte.
     * @return la taille de la carte.
     */
    int getHeight();

    /**
     * Retourne la longueur de la carte.
     * @return la longueur de la carte.
     */
    int getWidth();

    /**
     * Calcule les rayons lumineux de la carte.
     * </p>
     * Cette fonction doit être surchargée obligatoirement.
     */
    void computeRays();
};

#endif // LEVEL_H
