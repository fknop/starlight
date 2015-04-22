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

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void translate(double x = .0, double y = .0);
    void rotate(double angle);
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
    void set_line();

};

/* Fonctions inlines */

Wall * WallView::wall()
{
    return wall_;
}

bool WallView::selectable() const
{
    return this->selectable_;
}

void WallView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}



#endif // WALLVIEW_HPP

