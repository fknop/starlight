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
     * Instancie une vue représentant un miroir.
     * @param mirror le miroir.
     * @param selectable vrai si le miroir est sélectionnable, faux sinon.
     */
    MirrorView(const Mirror & mirror, bool selectable = false);

    /**
     * Retourne le miroir représenté par cet objet.
     * @return le miroir représenté par cet objet.
     */
    inline Mirror* mirror();

    /**
     * Retourne vrai si le miroir est sélectionnable.
     * @return vrai si le miroir est sélectionnable, faux sinon.
     */
    inline bool selectable() const;

    /**
     * Rend le miroir sélectionnable ou non.
     * @param value vrai si le miroir est sélectionnable, faux sinon.
     */
    inline void set_selectable(bool value);

    /**
     * Montre la zone dans laquelle peut etre déplacé le miroir.
     */
    void show_zone();

    /**
     * Cache la zone dans laquelle peut etre déplacé le miroir.
     */
    void hide_zone();

    void translate(const double x = .0, const double y = .0) override;
    void rotate(const double angle) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args = std::vector<std::string>()) override;

private:
    void set_zone();
};

/* Fonctions inlines */

Mirror * MirrorView::mirror()
{
    return mirror_;
}

bool MirrorView::selectable() const
{
    return selectable_;
}

void MirrorView::set_selectable(bool value)
{
    selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
}

#endif // MirrorView_HPP
