#include <QFileDialog>

#include <QtWidgets/QAction>
#include <QtWidgets/QMenuBar>
#include <QCoreApplication>
#include <QMessageBox>

#include "mainmenu.h"
#include "mainwindow.h"
#include "utils/mapreader.h"
#include "mapview.h"
#include "utils/constants.h"
#include "model/level.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), parent_{parent}
{
    setupUi();
}

void MainWindow::load_level()
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

void MainWindow::close_level()
{
    level_->remove_observer(map_view_);
    MapReader::end_level();
    centralWidget()->setEnabled(false);
    open_level_action_->setEnabled(true);
    close_level_action_->setEnabled(false);

    delete map_view_;
    map_view_ = nullptr;
}

void MainWindow::setupUi()
{
    setWindowTitle("Starlight");
    showMaximized();

    menu_bar_ = new QMenuBar(this);

    file_menu_ = menu_bar_->addMenu("&File");

    open_level_action_ = new QAction("&Open level", menu_bar_);
    open_level_action_->setShortcuts(QKeySequence::Open);
    open_level_action_->setStatusTip("Open a Starlight level");
    connect(open_level_action_, SIGNAL(triggered()), this, SLOT(load_level()));

    file_menu_->addAction(open_level_action_);


    close_level_action_ = new QAction("&Close level", menu_bar_);
    close_level_action_->setShortcuts(QKeySequence::Close);
    close_level_action_->setStatusTip("Close a Starlight level");
    connect(close_level_action_, SIGNAL(triggered()), this, SLOT(close_level()));

    file_menu_->addAction(close_level_action_);


    back_menu_action_ = new QAction("&Back to the menu", menu_bar_);
    back_menu_action_->setShortcuts(QKeySequence::Back);
    back_menu_action_->setStatusTip("Get back to the menu");
    connect(back_menu_action_, SIGNAL(triggered()), this, SLOT(back_menu()));

    file_menu_->addAction(back_menu_action_);


    quit_action_ = new QAction("&Quit", menu_bar_);
    quit_action_->setShortcuts(QKeySequence::Quit);
    quit_action_->setStatusTip("Quit the program");
    connect(quit_action_, &QAction::triggered, &QCoreApplication::quit);

    file_menu_->addAction(quit_action_);


    help_action_ = menu_bar_->addAction("&Help");
    connect(help_action_, SIGNAL(triggered()), this, SLOT(help()));

    setMenuBar(menu_bar_);

    QWidget * central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    centralWidget()->setEnabled(false);
    open_level_action_->setEnabled(true);
    close_level_action_->setEnabled(false);
}

void MainWindow::help()
{
    QMessageBox::information(this, "Help", STARLIGHT_RULES.c_str());
}

void MainWindow::back_menu()
{
    parent_->show();
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete map_view_;
    map_view_ = nullptr;
    delete level_;
    level_ = nullptr;
}

