#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QDoubleSpinBox>

#include "editor/elements.h"
#include "editor/properties.h"

#include "model/level.h"

#include "obs/observerinterface.h"

#include "view/mapview.h"


class MainEditor : public QMainWindow, public ObserverInterface
{
    Q_OBJECT
public:
    explicit MainEditor(QWidget *parent = 0);
    void setupUi();

private:
    QWidget * parent_;
    QMenuBar * menu_bar_;
    QMenu * file_menu_;
    QAction * load_level_action_;
    QAction * save_level_action_;
    QAction * back_menu_action_;
    QAction * quit_action_;
    QAction * help_action_;

    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    Elements *elements;
    QVBoxLayout *verticalLayout_1;

    MapView *mapview_;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    Properties *properties;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;


    Level * level_;

    ElementView * selected();

    void closeEvent(QCloseEvent * event);
    void notify(Observable* o,
                std::string msg,
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
