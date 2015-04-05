#include "model/source.h"
#include "sourceview.h"


SourceView::SourceView(const Source& source) : source_{source}
{
    setRect(source.position().x(), source.position().y(),
            source.edge(), source.edge());
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!source_.on())
    {
        setBrush(QBrush(Qt::yellow));
        setPen(QPen(Qt::yellow));
    }
    else
    {
        setBrush(QBrush(Qt::white));
        setPen(QPen(Qt::black));
    }

    source_.set_on(!source_.on());
}

