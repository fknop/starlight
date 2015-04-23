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

    QGraphicsTextItem * name_;

public:
    /**
     * Instancie un nouveau Button.
     * @param name le nom du bouton.
     * @param parent le parent.
     */
    Button(const QString& name, QGraphicsItem * parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;

signals:

    /**
     * Simule un clic.
     */
    void clicked();
};

#endif // BUTTON_H
