#include "model/source.h"
#include "sourceview.h"

#include <QGraphicsPixmapItem>


SourceView::SourceView(const Source& source)
{
    this->source_ = &(const_cast<Source&>(source));
//    setRect(this->source_->position().x(),
//            this->source_->position().y(),
//            this->source_->edge(),
//            this->source_->edge());
    setPos(this->source_->position().x(),
           this->source_->position().y());
    QPixmap p(":/images/lightbulboff.png");
    setPixmap(p.scaled(this->source_->edge(), this->source_->edge(), Qt::KeepAspectRatio));

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

    this->source_->set_on(!this->source_->on());
}

