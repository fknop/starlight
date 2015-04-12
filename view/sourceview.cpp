#include "model/source.h"
#include "sourceview.h"

#include <QGraphicsPixmapItem>


SourceView::SourceView(const Source& source, bool selectable) :
    ElementView(ElementView::TypeView::SOURCEVIEW), selectable_{selectable}
{
    this->source_ = &(const_cast<Source&>(source));
//    setRect(this->source_->position().x(),
//            this->source_->position().y(),
//            this->source_->edge(),
//            this->source_->edge());
    setPos(this->source_->pos().x(),
           this->source_->pos().y());
    QPixmap p(":/images/lightbulboff.png");
    setPixmap(p.scaled(this->source_->edge(), this->source_->edge(), Qt::KeepAspectRatio));

    sound_ = new QMediaPlayer();

    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!this->source_->on())
    {
        QPixmap p(":/images/lightbulbon.png");
        setPixmap(p.scaled(this->source_->edge(), this->source_->edge(), Qt::KeepAspectRatio));
//        setBrush(QBrush(Qt::yellow));
//        setPen(QPen(Qt::yellow));
    }
    else
    {
        QPixmap p(":/images/lightbulboff.png");
        setPixmap(p.scaled(this->source_->edge(), this->source_->edge(), Qt::KeepAspectRatio));

//        setBrush(QBrush(Qt::white));
//        setPen(QPen(Qt::black));
    }

    if (sound_->state() == QMediaPlayer::PlayingState)
        sound_->stop();

    sound_->setMedia(QUrl("qrc:/sounds/switch.mp3"));
    sound_->play();
    // http://soundbible.com/761-Switch.html  Uploaded: 07.20.09 | License: Attribution 3.0 | Recorded by Mike Koenig |


    this->source_->set_on(!this->source_->on());
}

Source * SourceView::source()
{
    return source_;
}
