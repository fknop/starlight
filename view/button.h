#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/**
 * Classe représentant un bouton du menu principal.
 */
class Button : public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    Button(QString name, QGraphicsItem * parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

signals:
    void clicked();

private:
    QGraphicsTextItem * name;
};

#endif // BUTTON_H
