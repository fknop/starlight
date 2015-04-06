#include "mainwindow.h"

#include <QFileDialog>

//#include <QtCore/QVariant>
#include <QtWidgets/QAction>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QButtonGroup>
//#include <QtWidgets/QHeaderView>
//#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
//#include <QtWidgets/QWidget>

#include "model/level.h"
#include "mapreader.h"
#include "mapview.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi();


}

void MainWindow::loadLevel()
{
    QString file_name = QFileDialog::getOpenFileName(
                this, tr("Load Starlight level"), "levels/", tr("Files .lvl (*.lvl)"));


    if (file_name != nullptr)
    {
        Level * level = MapReader::level(file_name.toStdString());

        if (level)
        {
            setCentralWidget(new MapView(level));
        }
    }
}

void MainWindow::setupUi()
{
    setWindowTitle("Starlight");
    //resize(400, 300);
    showMaximized();

    menu_bar_ = new QMenuBar(this);
    menu_bar_->setObjectName(QStringLiteral("menuBar"));

    QMenu * fileMenu = menu_bar_->addMenu("&File");

    QAction * open_level_action = new QAction("&Open level", menu_bar_);
    open_level_action->setShortcuts(QKeySequence::Open);
    open_level_action->setStatusTip("Open a Starlight level");
    connect(open_level_action, SIGNAL(triggered()), this, SLOT(loadLevel()));
    fileMenu->addAction(open_level_action);

    QAction * close_level_action = new QAction("&Close level", menu_bar_);
    close_level_action->setShortcuts(QKeySequence::Close);
    close_level_action->setStatusTip("Close a Starlight level");
    fileMenu->addAction(close_level_action);

    QAction * quit_action = new QAction("&Quit", menu_bar_);
    quit_action->setShortcuts(QKeySequence::Quit);
    quit_action->setStatusTip("Quit the program");
    fileMenu->addAction(quit_action);

    setMenuBar(menu_bar_);



    main_tool_bar_ = new QToolBar(this);
    main_tool_bar_->setObjectName(QStringLiteral("mainToolBar"));
    addToolBar(main_tool_bar_);

    central_widget_ = new QWidget(this);
    central_widget_->setObjectName(QStringLiteral("centralWidget"));
    setCentralWidget(central_widget_);

    status_bar_ = new QStatusBar(this);
    status_bar_->setObjectName(QStringLiteral("statusBar"));
    setStatusBar(status_bar_);
}

MainWindow::~MainWindow()
{
    delete ui;
}
