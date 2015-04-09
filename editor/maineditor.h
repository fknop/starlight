#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QPushButton>
#include <QgroupBox>
#include <QLabel>
#include <QDoubleSpinBox>

#include "model/level.h"
#include "view/mapview.h"

class MainEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainEditor(QWidget *parent = 0);
    void setupUi();

    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *elements;
//    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_1;
//    QPushButton *pushButton;
//    QPushButton *pushButton_2;
//    QPushButton *pushButton_3;
    MapView *mapview_;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *properties;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
//    QDoubleSpinBox *level_height_dsb;
//    QDoubleSpinBox *level_width_dsb;

//    QGroupBox * groupBox;
//    QLabel * level_height_label;
//    QLabel * level_width_label;
//    QPushButton *level_apply_pb;

    Level * level_;

private:




signals:

public slots:
    void add_mirror();
    void create_level();


};

#endif // MAINEDITOR_H
