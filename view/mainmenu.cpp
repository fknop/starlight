#include <iostream>
#include <QFileDialog>
#include <QIcon>
#include <QPalette>
#include <QPixmap>

#include "mainmenu.h"
#include "mainwindow.h"
#include "button.h"




Game::Game(QWidget * parent)
{
    this->setWindowTitle("Starlight");
    QPixmap pixmapbg("./ressources/images/WindowIcon.png");
    QIcon icon(pixmapbg);
    this->setWindowIcon(icon);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,400); // a changer

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 400, 400);
    setScene(scene);
}

Game::~Game()
{
    delete scene;
}

void Game::start()
{
    //    QString fileName = QFileDialog::getOpenFileName(this, tr("Charger un niveau"),
    //    "levels/", tr("Fichiers .lvl (*.lvl)"));

    //    std::cout << fileName.toStdString() << std::endl;

    //    if (fileName != nullptr)
    //    {
    //        Level * level = MapReader::level("levels/level1.lvl");

    //        if (level)
    //        {
    hide();

    MainWindow * mw = new MainWindow();
    mw->show();
    std::cout << "mw showed" << std::endl;
    //        }
    //    }
    //start le jeu dans une nouvelle fenetre  (et ferme cette fenetre ou resize et crée dans la meme)?
    //    std::cout << "start" << std::endl;
}

void Game::displayMainMenu()
{
    QGraphicsTextItem * titleText = new QGraphicsTextItem(tr("Starlight"));
    //QFont titleFont("comic sans", 50);
    //titleText->setFont(titleFont);

    int titleX = this->width() / 2 - titleText->boundingRect().width() /2;
    int titleY = 50;
    titleText->setPos(titleX, titleY);
    scene->addItem(titleText);

    Button * playButton = new Button(tr("Jouer"));
    int playX = this->width() / 2 - playButton->boundingRect().width() /2;
    int playY = 150;
    playButton->setPos(playX, playY);
    connect(playButton, &Button::clicked, this, &Game::start);
    scene->addItem(playButton);
    //connect to start slot.

    Button * rulesButton = new Button(tr("Règles"));
    int ruleX = this->width() / 2 - rulesButton->boundingRect().width() / 2;
    int ruleY = 225;
    rulesButton->setPos(ruleX, ruleY);
    scene->addItem(rulesButton);

    Button * quitButton = new Button(tr("Quitter"));
    int quitX = this->width() / 2 - quitButton->boundingRect().width() /2;
    int quitY = 300;
    quitButton->setPos(quitX, quitY);
    connect(quitButton, &Button::clicked, this, &QGraphicsView::close);
    scene->addItem(quitButton);



}

