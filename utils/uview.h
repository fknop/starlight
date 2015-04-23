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
/**
     * Affiche l'ellipse sur un objet graphique.
     * @param item l'objet graphique représentant une ellipse.
     * @param ellipse l'ellipse.
     */
    void display_ellipse(QGraphicsEllipseItem * item, const Ellipse& ellipse);

    /**
     * Affiche un rectangle sur un objet graphique.
     * @param item l'objet graphique représentant un rectangle.
     * @param rectangle le rectangle.
     */
    void display_rectangle(QGraphicsRectItem * item, const Rectangle& rectangle);

    /**
     * Affiche une ligne (segment) sur un objet graphique.
     * @param item l'objet graphique représentant un segment.
     * @param line le segment.
     */
    void display_line(QGraphicsLineItem * item, const LineSegment& line);

} // namespace uview


#endif // UVIEW

