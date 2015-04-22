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

const std::string MainMenu::STARLIGHT_RULES =
    "<p>Starlight is a 2D puzzle where you have "
    "to make the light go from the source to the destination without touching "
    "a nuke or… BOOM!, you lose.</p>"
    "<p>Walls are represented by black lines. Rays change of color when they cross a crystal,"
    "crystals are blue circles, nukes are red circles, lenses are green ellipses and "
    "mirrors are red lines. The source is the light bulb and the destination is shown as "
    "a square.</p>"
    "<p>Mirrors can be moved and rotated with your keyboard."
    "<p>Movements are achieved with the following keys:</p>"
    "<ul>"
        "<li>Z: Move the mirror up.</li>"
        "<li>S: Move the mirror down.</li>"
        "<li>Q: Move the mirror left.</li>"
        "<li>D: Move the mirror right.</li>"
    "</ul>"
    "<p>while mirror rotations are done through:"
    "<ul>"
        "<li>left arrow key: +1 in counterclockwise direction</li>"
        "<li>right arrow key: -1 in counterclockwise direction</li>"
    "</ul>"
    "<p>You can boost your move by pressing the 'Shift' key.</p>"
    "<p style='font-weight: bold;'>Enjoy your game!</p>";

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
    QMessageBox::information(this, "Help", MainMenu::STARLIGHT_RULES.c_str());
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

