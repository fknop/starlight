#ifndef PROPERTIESINTERFACE_H
#define PROPERTIESINTERFACE_H

#include <QWidget>

class PropertiesInterface : public QWidget
{
    Q_OBJECT
public:
    //PropertiesInterface(QWidget *& parent);
    virtual ~PropertiesInterface() {}

    virtual void apply() = 0;
    virtual void reset() = 0;
};

#endif // PROPERTIESINTERFACE_H

