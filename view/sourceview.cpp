#include "model/source.h"
#include "sourceview.h"

#include <QGraphicsPixmapItem>


SourceView::SourceView(const Source& source, bool selectable) :
    ElementView(ElementView::TypeView::SOURCEVIEW), selectable_{selectable}
{
    this->source_ = &(const_cast<Source&>(source));
    sound_ = new QMediaPlayer();

    set_pos();
    set_pixmap();
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->source_->set_on(!this->source_->on());
    set_pixmap();

    if (sound_->state() == QMediaPlayer::PlayingState)
        sound_->stop();

    sound_->setMedia(QUrl("qrc:/sounds/switch.mp3"));
    sound_->play();
    // http://soundbible.com/761-Switch.html  Uploaded: 07.20.09 | License: Attribution 3.0 | Recorded by Mike Koenig |
}

void SourceView::translate(double x, double y)
{

}

void SourceView::notify(Observable *sdo,
                        std::string msg,
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
