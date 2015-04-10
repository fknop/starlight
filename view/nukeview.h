#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsView>
#include <QGraphicsEllipseItem>

#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "model/nuke.h"

class NukeView : public QGraphicsEllipseItem, public ObserverInterface
{
public:
    NukeView(const Nuke & nuke);
    void notify(Observable *sdo, std::string msg, const std::vector<std::string> &args);

private:
    Nuke * nuke_;
};

#endif // NUKESVIEW_H
