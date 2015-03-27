#ifndef SOURCEVIEW_H
#define SOURCEVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

#include <QGraphicsSceneMouseEvent>

class SourceView : public QGraphicsRectItem
{
public:
    SourceView(int posX, int posY, int width, int height);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    bool active;

};

#endif // SOURCEVIEW_H
