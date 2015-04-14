#ifndef SOURCEVIEW_H
#define SOURCEVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
//#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

#include "model/source.h"
#include "view/elementview.h"
#include "obs/observable.h"
#include "obs/observerinterface.h"

/**
 * Modélisation visuelle d’une source.
 */
class SourceView : public QGraphicsPixmapItem, public ElementView, public ObserverInterface
{
public:
    /**
     * Construit un carré représentant une source lumineuse qui peut être allumée ou éteinte.
     * @param posX abscisse du coin supérieur gauche de la source.
     * @param posY ordonnée du coin supérieur gauche de la source.
     * @param width longueur du carré représentant la source.
     * @param height hauteur du carré représentant la source.
     */
    SourceView(const Source& source, bool selectable = false);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    inline Source * source();

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void translate(double x = .0, double y = .0);
    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
    Source* source_;
    QMediaPlayer * sound_;
    bool selectable_;

};

/* Fonctions inlines */

Source * SourceView::source()
{
    return source_;
}

bool SourceView::selectable() const
{
    return this->selectable_;
}

void SourceView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // SOURCEVIEW_H
