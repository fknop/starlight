
#ifndef __OBSERVER__H__
#define __OBSERVER__H__

#include <vector>
#include <string>

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
    virtual void notify(Observable * sdo, std::string msg="UPDATE_RAYS",
                        const std::vector<std::string>& args
                            = std::vector<std::string>()) = 0;
    virtual ~ObserverInterface() = default;
};

#endif
