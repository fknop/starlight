#include <QCoreApplication>
#include <QFileDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QShortcut>
#include <sstream>

#include "editor/elements.h"
#include "editor/properties.h"
#include "editor/maineditor.h"

#include "utils/mapreader.h"
#include "utils/mapwriter.h"

#include "view/destinationview.h"
#include "view/mapview.h"
#include "view/sourceview.h"


MainEditor::MainEditor(QWidget * parent) : QMainWindow(parent), parent_{parent}, level_{new Level(750, 580)}
{
    setup_ui();
}

void MainEditor::add_crystal()
{
    level_->add_crystal(Crystal(Point(50, 50), 29, 40));
    mapview_->draw_crystals();
}

void MainEditor::add_lens()
{
    level_->add_lens(Lens(Point(50, 50), 58, 116, 500, 600));
    mapview_->draw_lenses();
}

void MainEditor::add_mirror()
{
    level_->add_mirror(Mirror(Point(50, 50), 58, 100, 1.57));
    mapview_->draw_mirrors();
}

void MainEditor::add_nuke()
{
    level_->add_nuke(Nuke(Point(50, 50), 29));
    mapview_->draw_nukes();
}

void MainEditor::add_wall()
{
    level_->add_wall(Wall(Point(20, 20), Point(60, 60)));
    mapview_->draw_walls();
}

ElementView * MainEditor::selected()
{
    return mapview_->selected();
}

void MainEditor::create_level(int width, int height)
{
    properties_->delete_prop();
    properties_->set_element_prop(nullptr);

    level_ = new Level(width, height);
    level_->set_check_collisions(false);
    level_->set_handle_nukes(false);
    level_->set_handle_dest(false);
    level_->set_source(Source(Point(0,0), 29, 4.75, 400));
    level_->set_dest(Dest(Point(level_->width() - 29, level_->height() - 29), 29));

    vertical_layout_2_->removeWidget(mapview_);

    mapview_ = new MapView(level_, true);
    level_->add_observer(mapview_);
    mapview_->add_observer(this);

    vertical_layout_2_->addWidget(mapview_);
}

void MainEditor::setup_ui()
{
    showMaximized();

    menu_bar_ = new QMenuBar(this);
    file_menu_ = menu_bar_->addMenu("&File");

    load_level_action_ = new QAction("&Load level", menu_bar_);
    load_level_action_->setShortcuts(QKeySequence::Open);
    load_level_action_->setStatusTip("Load a Starlight level");

    save_level_action_ = new QAction("&Save level", menu_bar_);
    save_level_action_->setShortcuts(QKeySequence::Save);
    save_level_action_->setStatusTip("Save a Starlight level");

    back_menu_action_ = new QAction("&Back to the menu", menu_bar_);
    back_menu_action_->setShortcuts(QKeySequence::Back);
    back_menu_action_->setStatusTip("Get back to the menu");

    quit_action_ = new QAction("&Quit", menu_bar_);
    quit_action_->setShortcuts(QKeySequence::Quit);
    quit_action_->setStatusTip("Quit the editor");

    file_menu_->addAction(load_level_action_);
    file_menu_->addAction(save_level_action_);
    file_menu_->addAction(back_menu_action_);
    file_menu_->addAction(quit_action_);

    setMenuBar(menu_bar_);

    central_widget_ = new QWidget();

    horizontal_layout_ = new QHBoxLayout(central_widget_);
    horizontal_layout_->setSpacing(6);
    horizontal_layout_->setContentsMargins(11, 11, 11, 11);

    elements_ = new Elements();
    elements_->add_observer(this);

    properties_ = new Properties(central_widget_);
    properties_->add_observer(this);

    mapview_ = static_cast<MapView *>(new QWidget());
    vertical_layout_2_ = new QVBoxLayout(mapview_);
    vertical_layout_2_->setSpacing(6);
    vertical_layout_2_->setContentsMargins(11, 11, 11, 11);

    QSizePolicy sp_mapview(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_mapview.setHorizontalStretch(4);
    mapview_->setSizePolicy(sp_mapview);

    QSizePolicy sp_properties(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp_properties.setHorizontalStretch(1);
    properties_->setSizePolicy(sp_properties);

    horizontal_layout_->addWidget(elements_);
    horizontal_layout_->addWidget(mapview_);
    horizontal_layout_->addWidget(properties_);

    setCentralWidget(central_widget_);

    QShortcut * shortcut = new QShortcut(QKeySequence("Ctrl+X"), this);

    connect(save_level_action_, SIGNAL(triggered()), this, SLOT(save_level()));
    connect(back_menu_action_, SIGNAL(triggered()), this, SLOT(back_menu()));
    connect(quit_action_, SIGNAL(triggered()), this, SLOT(quit()));
    connect(load_level_action_, SIGNAL(triggered()), this, SLOT(load_level()));
    connect(shortcut, SIGNAL(activated()), this, SLOT(delete_selected()));
}

void MainEditor::load_level()
{
    properties_->delete_prop();
    properties_->set_element_prop(nullptr);

    QString file_name = QFileDialog::getOpenFileName(
                this, tr("Load Starlight level"), "levels/", tr("Files .lvl (*.lvl)"));

    if (file_name != nullptr)
    {
        MapReader::end_level();
        level_ = MapReader::level(file_name.toStdString());
        level_->set_check_collisions(false);
        level_->set_handle_nukes(false);
        level_->set_handle_dest(false);

        vertical_layout_2_->removeWidget(mapview_);

        mapview_ = new MapView(level_, true);
        level_->add_observer(mapview_);
        mapview_->add_observer(this);

        vertical_layout_2_->addWidget(mapview_);

        elements_->set_height(level_->height());
        elements_->set_width(level_->width());
        elements_->enable_pushbuttons(true);
    }
}

void MainEditor::save_level()
{
    QString file_name = QFileDialog::getSaveFileName(
                this, tr("Save Starlight level"), "levels/", tr("Files .lvl (*.lvl)"));

    if (file_name != nullptr && level_)
    {
        MapWriter::write(level_, file_name.toStdString());
    }
}

void MainEditor::back_menu()
{
    properties_->delete_prop();
    properties_->set_element_prop(nullptr);
    MapReader::end_level();
    parent_->show();
    close();
}

void MainEditor::quit()
{
    QWidget::close();
}

void MainEditor::closeEvent(QCloseEvent * event)
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Close confirmation",
                                                  "Are you sure you want to exit?",
                                                  QMessageBox::Yes|QMessageBox::No))
    {
        event->accept();
    }
}

void MainEditor::notify(Observable * o, const std::string& msg, const std::vector<std::string>& args)
{
    if (msg.compare("LEVEL_CREATED") == 0)
    {
        std::stringstream ssw(args.at(0));
        std::stringstream ssh(args.at(1));
        double w = (ssw >> w, w);
        double h = (ssh >> h, h);
        create_level(w , h);
    }

    else if (msg.compare("LEVEL_RESET") == 0)
    {
        properties_->delete_prop();
        properties_->set_element_prop(nullptr);
        mapview_->clear();
    }

    else if (msg.compare("MIRROR_ADDED") == 0)
        add_mirror();

    else if (msg.compare("CRYSTAL_ADDED") == 0)
        add_crystal();

    else if (msg.compare("LENS_ADDED") == 0)
        add_lens();

    else if (msg.compare("NUKE_ADDED") == 0)
        add_nuke();

    else if (msg.compare("WALL_ADDED") == 0)
        add_wall();

    else if (msg.compare("SELECTED") == 0)
        properties_->set_element_prop(this->selected());

    else if (msg.compare("ELEMENT_DELETED") == 0)
    {
        properties_->delete_prop();
        properties_->set_element_prop(nullptr);
        delete_selected();
    }

    else if (msg.compare("ELEMENT_CHANGED") == 0)
        mapview_->repaint();
}

void MainEditor::delete_selected()
{
    ElementView * ev_selected = this->selected();
    if (ev_selected != nullptr)
    {
        switch (ev_selected->type_view())
        {
        case ElementView::TypeView::CRYSTALVIEW:
        {
            CrystalView * cv = (static_cast<CrystalView *>(ev_selected));
            level_->remove_crystal(*cv->crystal());
            break;
        }
        case ElementView::TypeView::LENSVIEW:
        {
            LensView * lv = static_cast<LensView *> (ev_selected);
            level_->remove_lens(*lv->lens());
            break;
        }
        case ElementView::TypeView::MIRRORVIEW:
        {
            level_->remove_mirror(*(static_cast<MirrorView *>(ev_selected)->mirror()));
            break;
        }
        case ElementView::TypeView::NUKEVIEW:
        {
            level_->remove_nuke(*(static_cast<NukeView *>(ev_selected)->nuke()));
            break;
        }
        case ElementView::TypeView::WALLVIEW:
        {
            WallView * wv = static_cast<WallView *> (ev_selected);

            if (wv->wall()->movable())
                level_->remove_wall(*wv->wall());
            else
                QMessageBox::information(this, "Error !", "This element cannot be deleted");

            break;
        }
        case ElementView::TypeView::DESTVIEW:
        case ElementView::TypeView::SOURCEVIEW:
             QMessageBox::information(this, "Error !", "This element cannot be deleted");
        }

        mapview_->repaint();
    }
}
