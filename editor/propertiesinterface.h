#ifndef PROPERTIESINTERFACE_H
#define PROPERTIESINTERFACE_H

#include <QWidget>

#include "obs/observerinterface.h"

/**
 * Interface représentant les propriétés d'un objet au travers d'un panel.
 */
class PropertiesInterface : public QWidget, public ObserverInterface
{
    Q_OBJECT
public:
    virtual ~PropertiesInterface() {}

    /**
     * Applique les changements à l’élément modifié.
     */
    virtual void apply() = 0;
    /**
     * Applique les données de l’objet aux spinbox du widget qui le modifie.
     */
    virtual void reset() = 0;

    virtual void notify(Observable * o, const std::string& msg,
                        const std::vector<std::string>& args) override
    {
        reset();
    }
};

#endif // PROPERTIESINTERFACE_H

