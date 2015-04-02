#include "view/nukeview.h"


NukeView::NukeView(const Nuke & nuke) : nuke_{nuke}
{
    //    setRect(nuke.getLocation().getX(), nuke.getLocation().getY(), nuke.getRadius(), nuke.getRadius());
    Point p = nuke.position();
    double radius = nuke.radius();

    setRect(p.x() - radius, p.y() + radius,
            radius + radius, radius + radius);
}
