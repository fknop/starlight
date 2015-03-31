#include "view/NukeView.h"

NukeView::NukeView(const Nuke& nuke) : nuke{nuke}
{
    //    setRect(nuke.getLocation().getX(), nuke.getLocation().getY(), nuke.getRadius(), nuke.getRadius());
    Point p = nuke.getLocation();
    double radius = nuke.getRadius();
    setRect(p.getX() - radius, p.getY() + radius,
            radius + radius, radius + radius);
}
