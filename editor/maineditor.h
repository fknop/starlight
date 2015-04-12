#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QDoubleSpinBox>

#include "model/level.h"
#include "view/mapview.h"

#include "obs/observerinterface.h"
#include "elements.h"
#include "properties.h"

class MainEditor : public QMainWindow, public ObserverInterface
{
    Q_OBJECT
public:
    explicit MainEditor(QWidget *parent = 0);
    void setupUi();

    QMenuBar * menu_bar_;
    QMenu * file_menu_;
    QAction * load_level_action_;
    QAction * save_level_action_;
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

    void notify(Observable* o,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());
private:




signals:

public slots:
    void add_crystal();
    void add_lens();
    void add_mirror();
    void add_nuke();
    void add_wall();

    void create_level();


};

#endif // MAINEDITOR_H
