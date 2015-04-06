#include <iostream>
#include <QFileDialog>
#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QMessageBox>

#include "mainmenu.h"
#include "mainwindow.h"
#include "button.h"




MainMenu::MainMenu(QWidget * parent)
{
    this->setWindowTitle("Starlight");
    QPixmap pixmapbg("./ressources/images/WindowIcon.png");
    QIcon icon(pixmapbg);
    this->setWindowIcon(icon);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,400); // a changer

    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0,0, 400, 400);
    setScene(scene_);
}

MainMenu::~MainMenu()
{
    delete scene_;
}

void MainMenu::start()
{
    hide();

    MainWindow * mw = new MainWindow(this);
    mw->show();
}

void MainMenu::help()
{
    QMessageBox::information(this, "Help",
                             "<p>Starlight is a 2D puzzle where you have to make the light go from the source to the destination without touching a nuke or… BOOM!, you lose.</p>"
                             "<p>Mirrors can be moved and rotated with your keyboard."
                             "<p>Movements are achieved with the following keys:</p>"
                             "<ul>"
                                 "<li>Z: Move the mirror up.</li>"
                                 "<li>S: Move the mirror down.</li>"
                                 "<li>Q: Move the mirror left.</li>"
                                 "<li>D: Move the mirror right.</li>"
                             "</ul>"
                             "<p>while mirror rotation are done through:"
                             "<ul>"
                             "<li>left arrow key: +1 in sens horloger</li>"
                             "<li>right arrow key: -1 in sens horloger</li>"
                             "</ul>"
                             "<p style='font-weight: bold;'>Enjoy your game!</p>");
}

void MainMenu::displayMainMenu()
{
    QGraphicsTextItem * titleText = new QGraphicsTextItem(tr("Starlight"));
    QFont titleFont("calibri", 50);
    titleText->setFont(titleFont);

    int titleX = this->width() / 2 - titleText->boundingRect().width() /2;
    int titleY = 50;
    titleText->setPos(titleX, titleY);
    scene_->addItem(titleText);

    Button * playButton = new Button(tr("Play"));

    int playX = this->width() / 2 - playButton->boundingRect().width() /2;
    int playY = 150;
    playButton->setPos(playX, playY);
    connect(playButton, &Button::clicked, this, &MainMenu::start);

    scene_->addItem(playButton);


    Button * rulesButton = new Button(tr("Rules"));

    int ruleX = this->width() / 2 - rulesButton->boundingRect().width() / 2;
    int ruleY = 225;
    rulesButton->setPos(ruleX, ruleY);
    connect(rulesButton, &Button::clicked, this, &MainMenu::help);

    scene_->addItem(rulesButton);


    Button * quitButton = new Button(tr("Exit"));

    int quitX = this->width() / 2 - quitButton->boundingRect().width() /2;
    int quitY = 300;
    quitButton->setPos(quitX, quitY);
    connect(quitButton, &Button::clicked, this, &QGraphicsView::close);

    scene_->addItem(quitButton);
}

