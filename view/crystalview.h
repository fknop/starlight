#ifndef CRYSTALVIEW_H
#define CRYSTALVIEW_H

#include <QGraphicsEllipseItem>

#include "model/crystal.h"

#include "obs/observable.h"
#include "obs/observerinterface.h"

#include "view/elementview.h"


/**
 * Modélisation visuelle d’un cristal.
 */
class CrystalView : public QGraphicsEllipseItem, public ElementView, public ObserverInterface
{
    Crystal * crystal_;
    bool selectable_;

public:
    /**
     * Instancie une représentation visuelle d’un cristal passé en paramètre.
     * @param crystal le cristal à afficher.
     * @param selectable le cristal est-il sélectionnable sur la carte ?
     */
    CrystalView(const Crystal & crystal, bool selectable = false);

    /**
     * Retourne le cristal affiché.
     * @return le cristal affiché.
     */
    inline Crystal * crystal();

    /**
     * Retourne vrai si le cristal est sélectionnable, faux sinon.
     * @return vrai si le cristal est sélectionnable, faux sinon.
     */
    inline bool selectable() const;

    /**
     * Modifie le fait que le cristal soit sélectionnable.
     * @param value vrai si le cristal est sélectionnable, faux sinon.
     */
    inline void set_selectable(bool value);

    void translate(const double x = .0, const double y = .0) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

private:
    void set_rect();
};

/* Fonctions inlines */

Crystal * CrystalView::crystal()
{
    return crystal_;
}

bool CrystalView::selectable() const
{
    return selectable_;
}

void CrystalView::set_selectable(bool value)
{
    selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // CRYSTALVIEW_H
