#ifndef SOURCEVIEW_H
#define SOURCEVIEW_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QMediaPlayer>

#include "model/source.h"
#include "obs/observerinterface.h"
#include "view/elementview.h"

/**
 * Modélisation visuelle d’une source.
 */
class SourceView : public QGraphicsPixmapItem, public ElementView, public ObserverInterface
{
    Source * source_;
    QMediaPlayer * sound_;
    bool selectable_;

public:
    /**
     * Construit un carré représentant une source lumineuse qui peut être allumée ou éteinte.
     * @param posX abscisse du coin supérieur gauche de la source.
     * @param posY ordonnée du coin supérieur gauche de la source.
     * @param width longueur du carré représentant la source.
     * @param height hauteur du carré représentant la source.
     */
    SourceView(const Source & source, bool selectable = false);

    inline Source * source();

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void translate(const double x = .0, const double y = .0) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

private:
    void set_pos();
    void set_pixmap();
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
