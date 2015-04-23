#include <QGraphicsPixmapItem>

#include "model/source.h"
#include "view/sourceview.h"

SourceView::SourceView(const Source& source, bool selectable) :
    ElementView(ElementView::TypeView::SOURCEVIEW), selectable_{selectable}
{
    source_ = &(const_cast<Source&>(source));
    source_->add_observer(this);
    sound_ = new QMediaPlayer();

    set_pos();
    set_pixmap();
    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    source_->set_on(!source_->on());

    if (sound_->state() == QMediaPlayer::PlayingState)
        sound_->stop();

    sound_->setMedia(QUrl("qrc:/sounds/switch.mp3"));
    sound_->play();
}

void SourceView::translate(const double x, const double y)
{
    source_->translate(x ,y);
}

void SourceView::notify(Observable * o,
                        const std::string& msg,
                        const std::vector<std::string>& args)
{
    set_pos();
    set_pixmap();
}

void SourceView::set_pos()
{
    setPos(source_->pos().x(),
           source_->pos().y());
}

void SourceView::set_pixmap()
{
    if (source_->on())
    {
        QPixmap p(":/images/lightbulbon.png");
        setPixmap(p.scaled(source_->edge(), source_->edge(), Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap p(":/images/lightbulboff.png");
        setPixmap(p.scaled(source_->edge(), source_->edge(), Qt::KeepAspectRatio));
    }
}
