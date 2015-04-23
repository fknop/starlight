#include <QFileDialog>
#include <QIcon>
#include <QMessageBox>
#include <QPalette>
#include <QPixmap>

#include "editor/maineditor.h"

#include "utils/constants.h"

#include "view/button.h"
#include "view/mainmenu.h"
#include "view/mainwindow.h"

MainMenu::MainMenu(QWidget * parent)
{
    this->setWindowTitle("Starlight");
    QPixmap pixmapbg("./ressources/images/WindowIcon.png");
    QIcon icon(pixmapbg);
    this->setWindowIcon(icon);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,500); // a changer

    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0,0, 400, 500);
    setScene(scene_);
}

MainMenu::~MainMenu()
{
    delete scene_;
}

void MainMenu::start()
{
    hide();

    main_window_ = new MainWindow(this);
    main_window_->show();
}

void MainMenu::help()
{
    QFile file("ressources/rules.html");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        QMessageBox::information(this, "Rules", in.readAll());
        file.close();
    }
}

void MainMenu::editor()
{
    hide();

    MainEditor * editor = new MainEditor(this);
    editor->show();
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


    Button * editorButton = new Button(tr("Editor"));

    int editX = this->width() / 2 - editorButton->boundingRect().width() /2;
    int editY = 300;
    editorButton->setPos(editX, editY);
    connect(editorButton, &Button::clicked, this, &MainMenu::editor);

    scene_->addItem(editorButton);


    Button * quitButton = new Button(tr("Exit"));

    int quitX = this->width() / 2 - quitButton->boundingRect().width() /2;
    int quitY = 375;
    quitButton->setPos(quitX, quitY);
    connect(quitButton, &Button::clicked, this, &QGraphicsView::close);

    scene_->addItem(quitButton);
}

