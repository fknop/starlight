#ifndef MAINMENU_H
#define MAINMENU_H



#include <QMainWindow>

#include "QVBoxLayout"
#include "QPushButton"



class MainMenu : public QMainWindow
{
    Q_OBJECT


    QVBoxLayout * layout;
    QPushButton * play;
    QPushButton * quit;
    QPushButton * showRules;


public:
    explicit MainMenu(QWidget *parent = 0);

private:
    void initComponents();

signals:

public slots:

};

#endif // MAINMENU_H
