#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsView>
#include <QGraphicsEllipseItem>

#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "model/nuke.h"
#include "view/elementview.h"

class NukeView : public QGraphicsEllipseItem, public ObserverInterface, public ElementView
{
public:
    NukeView(const Nuke & nuke);
    Nuke * nuke();

    void notify(Observable *sdo, std::string msg, const std::vector<std::string> &args);

private:
    Nuke * nuke_;
};

#endif // NUKESVIEW_H
