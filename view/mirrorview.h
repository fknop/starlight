#ifndef MirrorView_HPP
#define MirrorView_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include <iostream>

#include "model/mirror.h"
#include "obs/observable.h"
#include "obs/observerinterface.h"

#include "elementview.h"

/**
 * Modélisation visuelle d’un miroir.
 */
class MirrorView : public QGraphicsLineItem, public ObserverInterface, public ElementView
{
public:
    /**
     * Construit un miroir capable de refléter la lumière du rayon émis depuis la source.
     * @param pivotX abscisse du pivot du miroir.
     * @param pivotY ordonnée du pivot du miroir.
     * @param xpad distance entre le pivot et l’extrémité gauche du miroir.
     * @param len longueur totale du miroir.
     * @param angle angle d’inclinaison du miroir.
     */
    MirrorView(const Mirror &mirror, bool selectable = false);

    inline Mirror* mirror();

    void translate(double x = .0, double y = .0);
    void rotate(double angle);
    void notify(Observable * obs,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());



    inline bool selectable() const;
    inline void set_selectable(bool value);

private:
    Mirror* mirror_;
    bool selectable_;
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
