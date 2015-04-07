#include "model/source.h"
#include "sourceview.h"


SourceView::SourceView(const Source& source)
{
    this->source_ = &(const_cast<Source&>(source));
    setRect(this->source_->position().x(),
            this->source_->position().y(),
            this->source_->edge(),
            this->source_->edge());
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!this->source_->on())
    {
        setBrush(QBrush(Qt::yellow));
        setPen(QPen(Qt::yellow));
    }
    else
    {
        setBrush(QBrush(Qt::white));
        setPen(QPen(Qt::black));
    }

    this->source_->set_on(!this->source_->on());
}

