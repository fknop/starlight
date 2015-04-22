#ifndef __OBSERVER__H__
#define __OBSERVER__H__

#include <string>
#include <vector>

class Observable;

/**
 * Interface représentant un observateur.
 * Toutes classes héritant de cette interface
 * doit redéfinir la méthode notify.
 * Un observateur reçoit des notifications d'une classe
 * héritant d'Observable.
 */
class ObserverInterface
{
public:

    /**
     * Notifie le jeu d'un évènement provenant d'un sujet d'observation (Observable).
     * @param o l'observé.
     * @param msg le message de notification.
     * @param args des arguments.
     */
    virtual void notify(Observable * o, const std::string& msg,
                        const std::vector<std::string>& args
                            = std::vector<std::string>()) = 0;
    virtual ~ObserverInterface() = default;
};

#endif
