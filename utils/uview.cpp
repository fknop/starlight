#include "utils/uview.h"

void uview::display_ellipse(QGraphicsEllipseItem * item, const Ellipse& ellipse)
{
    item->setRect(ellipse.center().x() - ellipse.x_rad(),
                  ellipse.center().y() - ellipse.y_rad(),
                  ellipse.x_rad() * 2,
                  ellipse.y_rad() * 2);
}

void uview::display_rectangle(QGraphicsRectItem * item, const Rectangle& rectangle)
{
    item->setRect(rectangle.upper_left().x(),
                  rectangle.upper_left().y(),
                  rectangle.width(),
                  rectangle.height());
}

void uview::display_line(QGraphicsLineItem * item, const LineSegment& line)
{
    item->setLine(line.start().x(),
                  line.start().y(),
                  line.end().x(),
                  line.end().y());
}
