#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsView>
#include <QGraphicsEllipseItem>

class NukeView : QGraphicsEllipseItem
{
public:
    NukeView(int x, int y, int radius);
};

#endif // NUKESVIEW_H
