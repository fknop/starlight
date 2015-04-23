#ifndef WALLVIEW_HPP
#define WALLVIEW_HPP

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>

#include "model/wall.h"
#include "view/elementview.h"
#include "obs/observerinterface.h"

/**
 * Modélisation visuelle d’un mur (ne reflétant pas la lumière).
 */
class WallView : public QGraphicsLineItem, public ElementView, public ObserverInterface
{
    Wall * wall_;
    bool selectable_;

public:
    /**
     * Construit un segment de droite représentant un mur.
     * @param wall le mur à construire.
     * @param selectable le mur est-il sélectionnable ?
     */
    WallView(const Wall & wall, bool selectable = false);

    /**
     * Retourne le mur représenté.
     * @return le mur représenté.
     */
    inline Wall * wall();

    /**
     * Retourne vrai si le mur est sélectionnable, faux sinon.
     * @return vrai si le mur est sélectionnable, faux sinon.
     */
    inline bool selectable() const;

    /**
     * Rend le mur sélectionnable ou non.
     * @param value vrai si le mur est sélectionnable, faux sinon.
     */
    inline void set_selectable(bool value);

    void translate(const double x = .0, const double y = .0) override;
    void rotate(const double angle) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

};

/* Fonctions inlines */

Wall * WallView::wall()
{
    return wall_;
}

bool WallView::selectable() const
{
    return selectable_;
}

void WallView::set_selectable(bool value)
{
    selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}



#endif // WALLVIEW_HPP

