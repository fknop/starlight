#include "maineditor.h"

#include <QHBoxLayout>

#include <QPushButton>

#include <QMenuBar>
#include <QFormLayout>

#include "view/mapview.h"
#include "properties.h"

#include "view/sourceview.h"
#include "view/destinationview.h"

#include "elements.h"

MainEditor::MainEditor(QWidget *parent) : QMainWindow(parent), level_{new Level(750,580)}
{
    setupUi();


//    pushButton->setEnabled(false);
//    pushButton_2->setEnabled(false);
//    pushButton_3->setEnabled(false);
}



void MainEditor::add_mirror()
{
    Mirror mirror(Point(50, 50), 58, 100, 1.57);
    level_->add_mirror(mirror);
    mapview_->draw_mirrors();
}

//Element MainEditor::selected()
//{
//    return mapview_->selec
//}

void MainEditor::create_level()
{
//    pushButton->setEnabled(true);
//    pushButton_2->setEnabled(true);
//    pushButton_3->setEnabled(true);



//    level_ = new Level(level_height_dsb->value(), level_width_dsb->value());


//    Source source(Point(0,0), 29, 4.75, 400);
//    Dest dest(Point(level_height_dsb->value() - 29,level_width_dsb->value() - 29), 29);

//    level_->set_source(source);
//    level_->set_dest(dest);

//    verticalLayout_2->removeWidget(mapview_);
//    mapview_ = new MapView(level_);
//    level_->add_observer(mapview_);
//    verticalLayout_2->addWidget(mapview_);
}

void MainEditor::setupUi()
{
    resize(975, 649);


    centralWidget = new QWidget();

    horizontalLayout = new QHBoxLayout(centralWidget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);

    elements = new Elements();
    elements->add_observer(this);
    horizontalLayout->addWidget(elements);


    horizontalLayout->addWidget(elements);

    mapview_ = new QWidget(); //new MapView();
    verticalLayout_2 = new QVBoxLayout(mapview_);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setContentsMargins(11, 11, 11, 11);


    QSizePolicy sp_mapview(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_mapview.setHorizontalStretch(4);
    mapview_->setSizePolicy(sp_mapview);

    horizontalLayout->addWidget(mapview_);

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
}

void MainEditor::notify(Observable * sdo, std::string msg="UPDATE_RAYS")
{
    if (msg == "LEVEL_CREATED")
    {
        create_level();
    }
    else if (msg == "MIRROR_ADDED")
    {
        std::cout << "mirror added!" << std::endl;
    }
}
