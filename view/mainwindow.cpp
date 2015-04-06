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
#include <QCoreApplication>

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
        level_ = MapReader::level(file_name.toStdString());

        if (level_)
        {
            map_view_ = new MapView(level_);
            level_->add_observer(map_view_);
            setCentralWidget(map_view_);

            centralWidget()->setEnabled(true);
            open_level_action_->setEnabled(false);
            close_level_action_->setEnabled(true);
        }
    }
}

void MainWindow::closeLevel()
{
    level_->remove_observer(map_view_);

    centralWidget()->setEnabled(false);
    open_level_action_->setEnabled(true);
    close_level_action_->setEnabled(false);

    delete map_view_;
    map_view_ = nullptr;
}

void MainWindow::setupUi()
{
    setWindowTitle("Starlight");
    //resize(400, 300);
    showMaximized();



    menu_bar_ = new QMenuBar(this);
    menu_bar_->setObjectName(QStringLiteral("menuBar"));

    file_menu_ = menu_bar_->addMenu("&File");

    open_level_action_ = new QAction("&Open level", menu_bar_);
    open_level_action_->setShortcuts(QKeySequence::Open);
    open_level_action_->setStatusTip("Open a Starlight level");
    connect(open_level_action_, SIGNAL(triggered()), this, SLOT(loadLevel()));
    file_menu_->addAction(open_level_action_);

    close_level_action_ = new QAction("&Close level", menu_bar_);
    close_level_action_->setShortcuts(QKeySequence::Close);
    close_level_action_->setStatusTip("Close a Starlight level");
    connect(close_level_action_, SIGNAL(triggered()), this, SLOT(closeLevel()));
    file_menu_->addAction(close_level_action_);

    quit_action_ = new QAction("&Quit", menu_bar_);
    quit_action_->setShortcuts(QKeySequence::Quit);
    quit_action_->setStatusTip("Quit the program");
    connect(quit_action_, &QAction::triggered, &QCoreApplication::quit);
    file_menu_->addAction(quit_action_);

    setMenuBar(menu_bar_);



//    main_tool_bar_ = new QToolBar(this);
//    main_tool_bar_->setObjectName(QStringLiteral("mainToolBar"));
//    addToolBar(main_tool_bar_);

    central_widget_ = new QWidget(this);
    central_widget_->setObjectName(QStringLiteral("centralWidget"));
    setCentralWidget(central_widget_);

//    status_bar_ = new QStatusBar(this);
//    status_bar_->setObjectName(QStringLiteral("statusBar"));
//    setStatusBar(status_bar_);


    centralWidget()->setEnabled(false);
    open_level_action_->setEnabled(true);
    close_level_action_->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
