/*!
 * \file observateur.h
 * \brief Définition de la classe Observateur.
 */

#ifndef __OBSERVATEUR__H__
#define __OBSERVATEUR__H__

class Observable;

/*!
 * Classe abstraite de base de tout observateur
 * Classe dont dérive tout observateur du modèle.
 */

class Observer
{
public:

    /*!
     * \brief Méthode virtuelle pure que chaque observateur concret 
     * doit implémenter : c'est cette méthode qu'appelle le sujet 
     * observé lors d'une notification.
     *
     * \param sdo le sujet d'observation qui notifie un changement.
     * \see SujetDObservation::notifierChangement().
     */
    virtual void notify(Observable * sdo) = 0;

    /*!
     * \brief Destructeur par défaut.
     */
    virtual ~Observer() = default;
};

#endif
