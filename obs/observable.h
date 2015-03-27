/*!
 * \file sujetdobservation.h
 * \brief Définition de la classe SujetDObservation.
 */

#ifndef __SUJETDOBSERVATION__H__
#define __SUJETDOBSERVATION__H__

#include <set>

class Observer;

/*!
 * Classe représentant un élément observable
 * pouvant notifié des observateurs.
 */
class Observable
{

protected:

    /**
     * Le vecteur d'observateurs enregistrés.
     */
    std::set<Observer *> observers;

    /**
     * Constructeur protégé pour éviter l'instanciation.
     */
    Observable() = default;

    /**
     * Notifie tous les observateurs enregistrés d'un changement
     * d'état.
     */
    virtual void notifyAll();

public:



    /**
     * Destructeur par défaut.
     */
    virtual ~Observable() = default;

    /**
     * Méthode permettant à un observateur de s'enregistrer
     * comme écouteur du sujet d'observation.
     *
     * @param obs un pointeur vers un observateur à ajouter.
     */
    virtual void addObserver(Observer * obs);

    /**
     * Méthode permettant à un observateur de se retirer de la
     * liste des écouteurs patentés du sujet d'observation.
     *
     * @param obs l'adresse de l'observateur à supprimer.
     */
    virtual void removeObserver(Observer * obs);




};

#endif
