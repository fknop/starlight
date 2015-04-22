#ifndef MirrorView_HPP
#define MirrorView_HPP

#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>

#include "model/mirror.h"
#include "obs/observerinterface.h"
#include "view/elementview.h"

/**
 * Modélisation visuelle d’un miroir.
 */
class MirrorView : public QGraphicsLineItem, public ObserverInterface, public ElementView
{
    Mirror * mirror_;
    bool selectable_;
    QGraphicsRectItem * zone_;

public:
    /**
     * Construit un miroir capable de refléter la lumière du rayon émis depuis la source.
     * @param pivotX abscisse du pivot du miroir.
     * @param pivotY ordonnée du pivot du miroir.
     * @param xpad distance entre le pivot et l’extrémité gauche du miroir.
     * @param len longueur totale du miroir.
     * @param angle angle d’inclinaison du miroir.
     */
    MirrorView(const Mirror & mirror, bool selectable = false);

    /**
     * Retourne le miroir représenté par cet objet.
     * @return le miroir représenté par cet objet.
     */
    inline Mirror* mirror();

    inline bool selectable() const;
    inline void set_selectable(bool value);
    void show_zone();
    void hide_zone();
    void translate(const double x = .0, const double y = .0) override;
    void rotate(const double angle) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

private:
    void set_line();
    void set_zone();
};

/* Fonctions inlines */

Mirror * MirrorView::mirror()
{
    return mirror_;
}

bool MirrorView::selectable() const
{
    return this->selectable_;
}

void MirrorView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // MirrorView_HPP
