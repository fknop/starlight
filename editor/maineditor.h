#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QMainWindow>

#include <QHBoxLayout>

class MainEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainEditor(QWidget *parent = 0);
    void setupUi();

    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;



signals:

public slots:

};

#endif // MAINEDITOR_H
