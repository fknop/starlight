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


/**
 * Contient le widget permettant d’éditer l’élément sélectionné
 * sur la carte et d’appliquer les changements ou de le supprimer.
 */
class Properties : public QWidget, public Observable
{
    Q_OBJECT

public:
    Properties(QWidget * parent = 0);

    /**
     * Crée un widget permettant de modifier l’élément passé en paramètre.
     * @param ev l’élément sélectionné du niveau.
     */
    void set_element_prop(ElementView * ev);
    /**
     * Supprime le widget qu’il contient.
     */
    void delete_prop();

private:
    QGridLayout * grid_layout_;
    QGroupBox * group_box_;

    QPushButton * apply_pb_;
    QPushButton * delete_pb_;

    PropertiesInterface * prop_interface_;

    void setup_ui();
    void add_connections();

signals:

public slots:
    /**
     * Applique les changements à l’objet sélectionné.
     */
    void apply_changes();
    /**
     * Prévient tous les observateurs qu’un élément a été supprimé.
     */
    void delete_element();

};

#endif // PREFS_H
