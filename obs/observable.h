
#ifndef __OBSERVABLE__H__
#define __OBSERVABLE__H__

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
     * Les observateurs enregistrés.
     */
    std::set<Observer *> observers_;

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
    virtual void add_observer(Observer * obs);

    /**
     * Méthode permettant à un observateur de se retirer de la
     * liste des écouteurs patentés du sujet d'observation.
     *
     * @param obs l'adresse de l'observateur à supprimer.
     */
    virtual void remove_observer(Observer * obs);
};

#endif
