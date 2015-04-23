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
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->source_->set_on(!this->source_->on());

    if (sound_->state() == QMediaPlayer::PlayingState)
        sound_->stop();

    sound_->setMedia(QUrl("qrc:/sounds/switch.mp3"));
    sound_->play();
}

void SourceView::translate(const double x, const double y)
{
    this->source_->translate(x ,y);
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
    setPos(this->source_->pos().x(),
           this->source_->pos().y());
}

void SourceView::set_pixmap()
{
    if (this->source_->on())
    {
        QPixmap p(":/images/lightbulbon.png");
        setPixmap(p.scaled(this->source_->edge(), this->source_->edge(), Qt::KeepAspectRatio));
    }
    else
    {
        QPixmap p(":/images/lightbulboff.png");
        setPixmap(p.scaled(this->source_->edge(), this->source_->edge(), Qt::KeepAspectRatio));
    }
}
