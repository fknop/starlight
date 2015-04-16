#ifndef PREFS_H
#define PREFS_H

#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QWidget>

#include "editor/propertiesinterface.h"

#include "obs/observable.h"

#include "view/crystalview.h"
#include "view/destinationview.h"
#include "view/elementview.h"
#include "view/lensview.h"
#include "view/mirrorview.h"
#include "view/nukeview.h"
#include "view/sourceview.h"
#include "view/wallview.h"


class Properties : public QWidget, public Observable
{
    Q_OBJECT

public:
    Properties(QWidget * parent = 0);
    void setupUi();
    void set_element_prop(ElementView * ev);
    void delete_prop();

private:
    QGridLayout * grid_layout_;
    QGroupBox * group_box_;

    QPushButton * apply_pb_;
    QPushButton * delete_pb_;

    PropertiesInterface * prop_interface_;

    void add_connections();


signals:

public slots:
    void apply_changes();
    void delete_element();

};

#endif // PREFS_H
