#ifndef PROPERTIESINTERFACE_H
#define PROPERTIESINTERFACE_H

#include <QWidget>

#include "obs/observerinterface.h"

class PropertiesInterface : public QWidget, public ObserverInterface
{
    Q_OBJECT
public:
    virtual ~PropertiesInterface() {}

    virtual void apply() = 0;
    virtual void reset() = 0;

    virtual void notify(Observable * sdo, std::string msg,
                        const std::vector<std::string>& args)
    {
        reset();
    }
};

#endif // PROPERTIESINTERFACE_H

