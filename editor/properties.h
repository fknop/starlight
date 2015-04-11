#ifndef PREFS_H
#define PREFS_H

#include <QWidget>

#include <QGridLayout>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QPushButton>

#include "obs/observable.h"

#include "view/elementview.h"

#include "view/mirrorview.h"

#include "propertiesinterface.h"

class Properties : public QWidget, public Observable
{
    Q_OBJECT

public:
    Properties(QWidget *parent = 0);
    void setupUi();
    void set_element_prop(ElementView *ev);



private:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
//    QDialogButtonBox *buttonBox;

    QPushButton *apply_pb;
    QPushButton *reset_pb;
    QPushButton *delete_pb;

    void add_connections();

    PropertiesInterface * prop_interface_;

signals:

public slots:
    void apply_changes();
    void reset_changes();
    void delete_element();

};

#endif // PREFS_H
