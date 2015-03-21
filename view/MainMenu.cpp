#include "MainMenu.h"

#include <QWidget>
#include <QAction>
#include <QCoreApplication>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent)
{

    initComponents();

}


void MainMenu::initComponents()
{

    QWidget * centralWidget = new QWidget();
    layout = new QVBoxLayout();
    play = new QPushButton(tr("Jouer"));
    quit = new QPushButton(tr("Quitter"));
    showRules = new QPushButton(tr("Afficher règles"));

    layout->addWidget(play);
    layout->addWidget(showRules);
    layout->addWidget(quit);

    centralWidget->setLayout(layout);

    this->setCentralWidget(centralWidget);
    connect(quit, &QPushButton::clicked, this, &QCoreApplication::quit);

}
