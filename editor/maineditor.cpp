#include "maineditor.h"

#include <QHBoxLayout>

#include <QPushButton>

#include <QMenuBar>
#include <QFormLayout>

#include "view/mapview.h"
#include "properties.h"

#include "view/sourceview.h"
#include "view/destinationview.h"

MainEditor::MainEditor(QWidget *parent) : QMainWindow(parent), level_{new Level(750,580)}
{
    setupUi();
    add_connections();

    pushButton->setEnabled(false);
    pushButton_2->setEnabled(false);
    pushButton_3->setEnabled(false);
}

void MainEditor::add_connections()
{
    connect(pushButton, SIGNAL(clicked()), this, SLOT(add_mirror()));
    connect(level_apply_pb, SIGNAL(clicked()), this, SLOT(create_level()));
}

void MainEditor::add_mirror()
{
    Mirror mirror(Point(50, 50), 58, 100, 1.57);
    level_->add_mirror(mirror);
    mapview_->draw_mirrors();
}

void MainEditor::create_level()
{
    pushButton->setEnabled(true);
    pushButton_2->setEnabled(true);
    pushButton_3->setEnabled(true);

    level_ = new Level(level_height_dsb->value(), level_width_dsb->value());


    Source source(Point(0,0), 29, 4.75, 400);
    Dest dest(Point(level_height_dsb->value() - 29,level_width_dsb->value() - 29), 29);

    level_->set_source(source);
    level_->set_dest(dest);

    verticalLayout_2->removeWidget(mapview_);
    mapview_ = new MapView(level_);
    level_->add_observer(mapview_);
    verticalLayout_2->addWidget(mapview_);
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

    groupBox = new QGroupBox(elements);
    groupBox->setTitle("Level");

    QFormLayout * formLayout = new QFormLayout(groupBox);

    level_height_label = new QLabel(groupBox);
    level_height_label->setText("Height: ");

    formLayout->setWidget(0, QFormLayout::LabelRole, level_height_label);

    level_height_dsb = new QDoubleSpinBox(groupBox);
    level_height_dsb->setMinimum(400);
    level_height_dsb->setMaximum(1000);

    formLayout->setWidget(0, QFormLayout::FieldRole, level_height_dsb);

    level_width_label = new QLabel(groupBox);
    level_width_label->setText("Width: ");

    formLayout->setWidget(1, QFormLayout::LabelRole, level_width_label);

    level_width_dsb = new QDoubleSpinBox(groupBox);
    level_width_dsb->setMinimum(400);
    level_width_dsb->setMaximum(1000);

    formLayout->setWidget(1, QFormLayout::FieldRole, level_width_dsb);

    level_apply_pb = new QPushButton();
    level_apply_pb->setText("Apply");

    formLayout->setWidget(2, QFormLayout::FieldRole, level_apply_pb);


    verticalLayout->addWidget(groupBox);

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
