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
    widget = new QWidget(centralWidget);
    widget->setObjectName(QStringLiteral("widget"));

    horizontalLayout->addWidget(widget);

    widget_2 = new QWidget(centralWidget);
    widget_2->setObjectName(QStringLiteral("widget_2"));

    horizontalLayout->addWidget(widget_2);

    widget_3 = new QWidget(centralWidget);
    widget_3->setObjectName(QStringLiteral("widget_3"));

    horizontalLayout->addWidget(widget_3);

    setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 975, 21));
    setMenuBar(menuBar);
//    mainToolBar = new QToolBar(this);
//    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
//    addToolBar(Qt::TopToolBarArea, mainToolBar);
//    statusBar = new QStatusBar(this);
//    statusBar->setObjectName(QStringLiteral("statusBar"));
//    setStatusBar(statusBar);



}
