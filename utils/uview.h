#ifndef UVIEW
#define UVIEW

#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

#include "model/ellipse.h"
#include "model/rectangle.h"
#include "model/linesegment.h"

namespace uview
{
    void display_ellipse(QGraphicsEllipseItem * item, const Ellipse& ellipse);
    void display_rectangle(QGraphicsRectItem * item, const Rectangle& rectangle);
    void display_line(QGraphicsLineItem * item, const LineSegment& line);
} // namespace uview


#endif // UVIEW

