#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsView>
#include <QGraphicsEllipseItem>

class NukesView : QGraphicsEllipseItem
{
public:
    NukesView(int x, int y, int radius);
};

#endif // NUKESVIEW_H
