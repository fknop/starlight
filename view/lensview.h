#ifndef LENSVIEW_H
#define LENSVIEW_H

#include <QGraphicsEllipseItem>

#include "model/lens.h"
#include "obs/observerinterface.h"
#include "view/elementview.h"

/**
 * Modélisation visuelle de la lentille.
 */
class LensView : public QGraphicsEllipseItem, public ElementView, public ObserverInterface
{
    Lens * lens_;
    bool selectable_;

public:
    /**
     * Instancie une représentation visuelle d’une lentille passée en paramètre.
     * @param lens la lentille à afficher.
     * @param selectable la lentille est-elle sélectionnable sur la carte ?
     */
    LensView(const Lens & lens, bool selectable = false);

    /**
     * Retourne la lentille affichée.
     * @return la lentille affichée.
     */
    inline Lens * lens();

    /**
     * Retourne vrai si la lentille est sélectionnable, faux sinon.
     * @return vrai si la lentille est sélectionnable, faux sinon.
     */
    inline bool selectable() const;

    /**
     * Modifie le fait que la lentille soit sélectionnable.
     * @param value vrai si la lentille est sélectionnable, faux sinon.
     */
    inline void set_selectable(bool value);

    void translate(const double x = .0, const double y = .0) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;
};

/* Fonctions inlines */

Lens * LensView::lens()
{
    return lens_;
}

bool LensView::selectable() const
{
    return selectable_;
}

void LensView::set_selectable(bool value)
{
    selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // LENSVIEW_H
