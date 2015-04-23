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

    /**
     * Réagit comme un QPushButton s’il est cliqué.
     * @param event un événement souris.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    /**
     * Change la couleur du bouton lorsque la souris survole le bouton.
     * @param event un événement souris.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
    /**
     * Change la couleur du bouton lorsque la souris arrete de survoler le bouton.
     * @param event un événement souris.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;

private:
    void set_yellow_brush();
    void set_green_brush();

signals:

    /**
     * Simule un clic.
     */
    void clicked();
};

#endif // BUTTON_H
