#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mapview.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMenuBar * menu_bar_;
    QToolBar * main_tool_bar_;
    QStatusBar * status_bar_;

    MapView * map_view_;
    Level * level_;

    QMenu * file_menu_;
    QAction * open_level_action_;
    QAction * close_level_action_;
    QAction * quit_action_;
    QAction * help_action_;

    void setupUi();


private:
    MainWindow * ui;

private slots:
    void loadLevel();
    void closeLevel();
    void help();
};

#endif // MAINWINDOW_H