#include "maineditor.h"

#include <QHBoxLayout>

#include <QPushButton>

#include <QMenuBar>

#include "view/mapview.h"
#include "properties.h"

MainEditor::MainEditor(QWidget *parent) : QMainWindow(parent), level_{new Level(this->size().height(), this->size().width())},
    mapview{new MapView()}
{

    setupUi();
    add_connections();

//    mapview = new MapView();
//    mapview->draw_wall(Wall(Point(0,0), Point(500,300)));

//    mapview->update();

//    mapview->scene()->addRect(0,0,250,50);


}

void MainEditor::add_connections()
{
    connect(pushButton, SIGNAL(clicked()), this, SLOT(add_mirror()));
}

void MainEditor::add_mirror()
{
    std::cout << "adding new mirror" << std::endl;
    Mirror mirror(Point(50, 50), 100, 25, 75);
    level_->add_mirror(mirror);

    mapview->draw_mirror(mirror);
    mapview->draw_crystal(Crystal(Point(0,0), 75, 400));

    mapview->update();
    mapview->viewport()->update();
}

void MainEditor::setupUi()
{
    resize(975, 649);


    centralWidget = new QWidget();

    horizontalLayout = new QHBoxLayout(centralWidget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);

    elements = new QWidget(centralWidget);

    verticalLayout = new QVBoxLayout(elements);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);

    pushButton = new QPushButton("Mirror", elements);

    verticalLayout->addWidget(pushButton);

    pushButton_2 = new QPushButton("Source", elements);

    verticalLayout->addWidget(pushButton_2);

    pushButton_3 = new QPushButton("Destination", elements);

    verticalLayout->addWidget(pushButton_3);

    QSizePolicy sp_elements(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_elements.setHorizontalStretch(1);
    elements->setSizePolicy(sp_elements);

    horizontalLayout->addWidget(elements);

    mapview = new QWidget(centralWidget);
    verticalLayout_2 = new QVBoxLayout(mapview);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setContentsMargins(11, 11, 11, 11);


    MapView * map_view = new MapView();
    verticalLayout_2->addWidget(map_view);

    QSizePolicy sp_mapview(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_mapview.setHorizontalStretch(2);
    mapview->setSizePolicy(sp_mapview);

    horizontalLayout->addWidget(mapview);

    properties = new QWidget(centralWidget);

    verticalLayout_3 = new QVBoxLayout(properties);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);



    Properties * prefs = new Properties();
    verticalLayout_3->addWidget(prefs);


    QSizePolicy sp_properties(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_properties.setHorizontalStretch(1);
    properties->setSizePolicy(sp_properties);

    horizontalLayout->addWidget(properties);

    setCentralWidget(centralWidget);
//    menuBar = new QMenuBar();
//    menuBar->setObjectName(QStringLiteral("menuBar"));
//    menuBar->setGeometry(QRect(0, 0, 975, 21));
//    setMenuBar(menuBar);
//    mainToolBar = new QToolBar();
//    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
//    addToolBar(Qt::TopToolBarArea, mainToolBar);
//    statusBar = new QStatusBar();
//    statusBar->setObjectName(QStringLiteral("statusBar"));
//    setStatusBar(statusBar);




}
