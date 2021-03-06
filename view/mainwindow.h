#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "view/mapview.h"

/**
 * Représente la fenêtre principale.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    MainWindow * ui_;
    QWidget * parent_;
    QMenuBar * menu_bar_;
    QToolBar * main_tool_bar_;
    QStatusBar * status_bar_;

    MapView * map_view_;
    Level * level_;

    QMenu * file_menu_;
    QAction * open_level_action_;
    QAction * close_level_action_;
    QAction * back_menu_action_;
    QAction * quit_action_;
    QAction * help_action_;

public:
    /**
     * Constructeur de la fenetre de jeu.
     * @param parent le widget parent.
     */
    explicit MainWindow(QWidget * parent = 0);
    ~MainWindow();

private:
    void setup_ui();

private slots:
    void load_level();
    void close_level();
    void back_menu();
    void help();
};

#endif // MAINWINDOW_H
