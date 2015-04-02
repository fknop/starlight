#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsView>
#include <QGraphicsEllipseItem>

#include "model/nuke.h"

class NukeView : public QGraphicsEllipseItem
{
public:
    NukeView(const Nuke & nuke);

private:
    Nuke nuke_;
};

#endif // NUKESVIEW_H
