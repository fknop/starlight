#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QPushButton>

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
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
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

    Level * level_;

private:
    void add_connections();


signals:

public slots:
    void add_mirror();

};

#endif // MAINEDITOR_H
