#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>

#include "editor/elements.h"
#include "editor/properties.h"

#include "model/level.h"

#include "obs/observerinterface.h"

#include "view/mapview.h"


/**
 * Fenêtre principale de l’éditeur.
 */
class MainEditor : public QMainWindow, public ObserverInterface
{
    Q_OBJECT

    QWidget * parent_;
    QMenuBar * menu_bar_;
    QMenu * file_menu_;
    QAction * load_level_action_;
    QAction * save_level_action_;
    QAction * back_menu_action_;
    QAction * quit_action_;
    QAction * help_action_;

    QWidget * central_widget_;
    QHBoxLayout * horizontal_layout_;
    Elements * elements_;
    QVBoxLayout * vertical_layout_1_;

    MapView * mapview_;
    QVBoxLayout * vertical_layout_2_;
    Properties * properties_;

    Level * level_;

public:
    explicit MainEditor(QWidget * parent = 0);

private:
    ElementView * selected();

    void setup_ui();

    void closeEvent(QCloseEvent * event);
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>());

signals:

public slots:
    void add_crystal();
    void add_lens();
    void add_mirror();
    void add_nuke();
    void add_wall();

    void create_level();
    void load_level();
    void save_level();
    void back_menu();
    void quit();

    void delete_selected();
};

#endif // MAINEDITOR_H
