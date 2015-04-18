#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMessageBox>

#include "view/mapview.h"


MapView::MapView()
{
    scene_ = new QGraphicsScene(0, 0, 500, 500);
    setScene(scene_);
    selected_mirror_ = nullptr;
}

MapView::MapView(Level* level, bool selectable) : level_{level}, selectable_{selectable}
{
    scene_ = new QGraphicsScene(0, 0, this->level_->width(), this->level_->height());
    sound_ = new QMediaPlayer(nullptr);
    selected_mirror_ = nullptr;
    setScene(scene_);
    setRenderHints(QPainter::Antialiasing);

    repaint();
}

MapView::~MapView()
{
    clear();
    delete scene_;
    scene_ = nullptr;
    delete sound_;
    sound_ = nullptr;
}

ElementView * MapView::selected()
{
    if (scene_->selectedItems().size() > 0)
    {
        ElementView *ev = dynamic_cast<ElementView *> (scene_->selectedItems().at(0));
        return ev;
    }

    return nullptr;
}

void MapView::clear()
{
    for (auto &i : mirror_views_)
        delete i;
    mirror_views_.clear();

    for (auto &i : ray_views_)
        delete i;
    ray_views_.clear();

    for (auto &i : lens_views_)
        delete i;
    lens_views_.clear();

    for (auto &i : crystal_views_)
        delete i;
    crystal_views_.clear();

    for (auto &i : nuke_views_)
        delete i;
    nuke_views_.clear();

    for (auto &i : wall_views_)
        delete i;
    wall_views_.clear();

    scene_->clear();
}

void MapView::repaint()
{
    draw_source();
    draw_dest();
    draw_walls();
    draw_nukes();
    draw_lenses();
    draw_crystals();
    draw_mirrors();
}

void MapView::draw_walls()
{
    if (wall_views_.size() > 0)
    {
        for (auto &i : wall_views_)
            scene_->removeItem(i);

        wall_views_.clear();
    }

    for (auto &i : level_->walls())
        draw_wall(i);
}

void MapView::draw_mirrors()
{
    if (mirror_views_.size() > 0)
    {
        for (auto &i : mirror_views_)
            scene_->removeItem(i);

        mirror_views_.clear();
    }

    for (auto &i : level_->mirrors())
        draw_mirror(i);
}

void MapView::draw_nukes()
{
    if (nuke_views_.size() > 0)
    {
        for (auto &i : nuke_views_)
            scene_->removeItem(i);

        nuke_views_.clear();
    }
    for (auto &i : level_->nukes())
        draw_nuke(i);
}

void MapView::draw_lenses()
{
    if (lens_views_.size() > 0)
    {
        for (auto &i : lens_views_)
            scene_->removeItem(i);

        lens_views_.clear();
    }

    for (auto &i : level_->lenses())
        draw_lens(i);
}

void MapView::draw_crystals()
{
    if (crystal_views_.size() > 0)
    {
        for (auto &i : crystal_views_)
            scene_->removeItem(i);

        crystal_views_.clear();
    }

    for (auto &i : level_->crystals())
        draw_crystal(i);
}

void MapView::draw_rays()
{
    if (ray_views_.size() > 0)
    {
        for (auto &i : ray_views_)
        {
            scene_->removeItem(i);
            delete i;
        }
        ray_views_.clear();
    }

    for (auto &i : level_->rays())
        draw_ray(i);
}

void MapView::draw_source()
{
    if (source_view_ != nullptr)
        scene_->removeItem(source_view_);

    source_view_ = new SourceView(level_->source(), selectable_);
    scene_->addItem(source_view_);
}

void MapView::draw_dest()
{
    if (dest_view_ != nullptr)
        scene_->removeItem(dest_view_);

    dest_view_ = new DestinationView(level_->dest(), selectable_);
    scene_->addItem(dest_view_);
}

void MapView::draw_ray(const Ray& ray)
{
    RayView* rv = new RayView(ray);
    ray_views_.push_back(rv);
    scene_->addItem(rv);
}

void MapView::draw_wall(const Wall& wall)
{
    WallView* wv = new WallView(wall, selectable_);
    wall_views_.push_back(wv);
    scene_->addItem(wv);
}

void MapView::draw_mirror(const Mirror& mirror)
{
    MirrorView* mv = new MirrorView(mirror, true);
    mirror_views_.push_back(mv);
    scene_->addItem(mv);
}

void MapView::draw_nuke(const Nuke& nuke)
{
    NukeView* nv = new NukeView(nuke, selectable_);
    nuke_views_.push_back(nv);
    scene_->addItem(nv);
}

void MapView::draw_lens(const Lens& lens)
{
    LensView* lv = new LensView(lens, selectable_);
    lens_views_.push_back(lv);
    scene_->addItem(lv);
}

void MapView::draw_crystal(const Crystal& crystal)
{
    CrystalView* cv = new CrystalView(crystal, selectable_);
    crystal_views_.push_back(cv);
    scene_->addItem(cv);
}

void MapView::mousePressEvent(QMouseEvent * event)
{
    if (selected_mirror_ != nullptr)
    {
        selected_mirror_->hide_zone();
        selected_mirror_ = nullptr;
    }

    ElementView * ev_selected = this->selected();
    if (ev_selected != nullptr)
    {
        if (ev_selected->type_view() == MirrorView::TypeView::MIRRORVIEW)
        {
            selected_mirror_ = dynamic_cast<MirrorView*> (ev_selected);
            selected_mirror_->show_zone();
        }
        notify_all(std::string("SELECTED"));
    }
}

void MapView::keyPressEvent(QKeyEvent *event)
{
    ElementView * i = selected();
    if (i != nullptr)
    {
        switch(event->key())
        {
        case Qt::Key_Left:
            if (event->modifiers() & Qt::ShiftModifier)
                i->rotate(-5);
            else
                i->rotate(-1);
            break;

        case Qt::Key_Right:
            if (event->modifiers() & Qt::ShiftModifier)
                i->rotate(5);
            else
                i->rotate(1);
            break;
        case Qt::Key_Z:
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(0, -5);
            else
                i->translate(0, -1);
            break;
        case Qt::Key_S:
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(0, 5);
            else
                i->translate(0, 1);
            break;
        case Qt::Key_Q:
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(-5, 0);
            else
                i->translate(-1, 0);
            break;
        case Qt::Key_D:
            if (event->modifiers() & Qt::ShiftModifier)
                i->translate(5, 0);
            else
                i->translate(1, 0);
            break;
        }
    }
}

void MapView::notify(Observable * sdo, std::string msg, const std::vector<std::string> & args)
{
    if (msg.compare("RECOMPUTE") == 0)
        draw_rays();

    if (level_->lost())
    {
        if (sound_->state() == QMediaPlayer::PlayingState)
            sound_->stop();

        sound_->setMedia(QUrl("qrc:/sounds/nuke.mp3"));
        sound_->play();

        setEnabled(false);

        QMessageBox::information(this, "You lose!", "Outch, looks like you exploded the whole map…");
    }
    else if (level_->won())
    {
        if (sound_->state() == QMediaPlayer::PlayingState)
            sound_->stop();

        sound_->setMedia(QUrl("qrc:/sounds/victory.mp3"));
        sound_->play();

        setEnabled(false);

        QMessageBox::information(this, "WIN!", "Congrats! You made it!");
    }
}

