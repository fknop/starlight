#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMenuBar *menu_bar_;
    QToolBar *main_tool_bar_;
    QWidget *central_widget_;
    QStatusBar *status_bar_;

    void setupUi();


private:
    MainWindow *ui;

private slots:
    void loadLevel();
};

#endif // MAINWINDOW_H
