#include "maineditor.h"

#include <QHBoxLayout>

#include <QPushButton>

#include <QMenuBar>

MainEditor::MainEditor(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi();
}

void MainEditor::setupUi()
{

    resize(975, 649);


    centralWidget = new QWidget();
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    horizontalLayout = new QHBoxLayout(centralWidget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    elements = new QWidget(centralWidget);
    elements->setObjectName(QStringLiteral("elements"));
    verticalLayout = new QVBoxLayout(elements);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    pushButton = new QPushButton(elements);
    pushButton->setObjectName(QStringLiteral("pushButton"));

    verticalLayout->addWidget(pushButton);

    pushButton_2 = new QPushButton(elements);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

    verticalLayout->addWidget(pushButton_2);

    pushButton_3 = new QPushButton(elements);
    pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

    verticalLayout->addWidget(pushButton_3);

    QSizePolicy sp_elements(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_elements.setHorizontalStretch(1);
    elements->setSizePolicy(sp_elements);

    horizontalLayout->addWidget(elements);

    mapview = new QWidget(centralWidget);
    mapview->setObjectName(QStringLiteral("mapview"));
    verticalLayout_2 = new QVBoxLayout(mapview);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setContentsMargins(11, 11, 11, 11);
    verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
    pushButton_4 = new QPushButton(mapview);
    pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

    verticalLayout_2->addWidget(pushButton_4);

    pushButton_5 = new QPushButton(mapview);
    pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

    verticalLayout_2->addWidget(pushButton_5);

    pushButton_6 = new QPushButton(mapview);
    pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

    verticalLayout_2->addWidget(pushButton_6);


    QSizePolicy sp_mapview(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_mapview.setHorizontalStretch(2);
    mapview->setSizePolicy(sp_mapview);

    horizontalLayout->addWidget(mapview);

    properties = new QWidget(centralWidget);
    properties->setObjectName(QStringLiteral("properties"));
    verticalLayout_3 = new QVBoxLayout(properties);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
    pushButton_7 = new QPushButton(properties);
    pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

    verticalLayout_3->addWidget(pushButton_7);

    pushButton_8 = new QPushButton(properties);
    pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

    verticalLayout_3->addWidget(pushButton_8);

    pushButton_9 = new QPushButton(properties);
    pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

    verticalLayout_3->addWidget(pushButton_9);


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
