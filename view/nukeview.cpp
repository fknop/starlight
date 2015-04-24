#include <QPen>
#include <QPixmap>

#include "utils/uview.h"

#include "view/nukeview.h"


NukeView::NukeView(const Nuke & nuke, bool selectable)  :
    ElementView(ElementView::TypeView::NUKEVIEW), selectable_{selectable}
{
    nuke_ = &(const_cast<Nuke &>(nuke));
    nuke_->add_observer(this);

    // pixabay.com/static/uploads/photo/2014/04/02/10/26/nuclear-303831_640.png
    setPos(nuke_->position().x() - nuke_->radius(),
           nuke_->position().y() - nuke_->radius());
    QPixmap p(":/images/nuke-yellow.png");
    setPixmap(p.scaled(nuke_->radius() * 2, nuke_->radius() * 2, Qt::KeepAspectRatio));



    setFlag(QGraphicsItem::ItemIsSelectable, selectable_);
}

void NukeView::notify(Observable * o, const std::string& msg,
                      const std::vector<std::string>& args)
{
    if (msg.compare("LIGHTED_UP") == 0)
    {
         QPixmap p(":/images/nuke-red.png");
         setPixmap(p.scaled(nuke_->radius() * 2, nuke_->radius() * 2, Qt::KeepAspectRatio));
    }
    else
    {
        setPos(nuke_->position().x() - nuke_->radius(),
               nuke_->position().y() - nuke_->radius());
        QPixmap p(":/images/nuke-yellow.png");
        setPixmap(p.scaled(nuke_->radius() * 2, nuke_->radius() * 2, Qt::KeepAspectRatio));
    }
}

void NukeView::translate(const double x, const double y)
{
    nuke_->translate(x, y);
}


