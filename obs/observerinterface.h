
#ifndef __OBSERVER__H__
#define __OBSERVER__H__

#include <vector>
#include <string>

class Observable;


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
