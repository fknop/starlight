#include "view/nukeview.h"


NukeView::NukeView(const Nuke & nuke) : nuke_{nuke}
{
    //    setRect(nuke.getLocation().getX(), nuke.getLocation().getY(), nuke.getRadius(), nuke.getRadius());
    Point p = nuke_.position();
    double radius = nuke_.radius();

    setRect(p.x() - radius, p.y() + radius,
            radius + radius, radius + radius);
}
