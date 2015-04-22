#include "editor/crystalprop.h"
#include "editor/destprop.h"
#include "editor/lensprop.h"
#include "editor/mirrorprop.h"
#include "editor/nukeprop.h"
#include "editor/properties.h"
#include "editor/sourceprop.h"
#include "editor/wallprop.h"


Properties::Properties(QWidget * parent) : QWidget(parent)
{
    setup_ui();

    prop_interface_ = nullptr;

    add_connections();
}

void Properties::add_connections()
{
    connect(apply_pb_, SIGNAL(clicked()), this, SLOT(apply_changes()));
    connect(delete_pb_, SIGNAL(clicked()), this, SLOT(delete_element()));
}

void Properties::setup_ui()
{
    resize(400, 300);

    grid_layout_ = new QGridLayout();

    group_box_ = new QGroupBox();
    group_box_->setTitle(tr("Properties"));
    QHBoxLayout * qhl = new QHBoxLayout;
    group_box_->setLayout(qhl);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    group_box_->setFont(font);

    grid_layout_->addWidget(group_box_, 0, 0, 1, 3);

    apply_pb_ = new QPushButton();
    apply_pb_->setText("Apply");
    apply_pb_->setEnabled(false);

    grid_layout_->addWidget(apply_pb_, 1, 0, 1, 1);

    delete_pb_ = new QPushButton();
    delete_pb_->setText("Delete");
    delete_pb_->setEnabled(false);

    grid_layout_->addWidget(delete_pb_, 1, 1, 1, 1);

    setLayout(grid_layout_);
}

void Properties::delete_prop()
{
    if (prop_interface_ != nullptr)
    {
        delete prop_interface_;
        prop_interface_ = nullptr;
    }
}

void Properties::set_element_prop(ElementView * ev)
{
    delete_prop();

    if (ev != nullptr)
    {
        switch(ev->type_view())
        {
        case ElementView::TypeView::CRYSTALVIEW:
        {
            CrystalView * cv = dynamic_cast<CrystalView *> (ev);
            prop_interface_ = new CrystalProp(cv->crystal(), group_box_);

            break;
        }
        case ElementView::TypeView::DESTVIEW:
        {
            DestinationView * dv = dynamic_cast<DestinationView *> (ev);
            prop_interface_ = new DestProp(dv->dest(), group_box_);

            break;
        }
        case ElementView::TypeView::LENSVIEW:
        {
            LensView * lv = dynamic_cast<LensView *> (ev);
            prop_interface_ = new LensProp(lv->lens(), group_box_);

            break;
        }
        case ElementView::TypeView::MIRRORVIEW:
        {
            MirrorView * mv = dynamic_cast<MirrorView *> (ev);
            prop_interface_ = new MirrorProp(mv->mirror(), group_box_);

            break;
        }
        case ElementView::TypeView::NUKEVIEW:
        {
            NukeView * nv = dynamic_cast<NukeView *> (ev);
            prop_interface_ = new NukeProp(nv->nuke(), group_box_);

            break;
        }
        case ElementView::TypeView::SOURCEVIEW:
        {
            SourceView * sv = dynamic_cast<SourceView *> (ev);
            prop_interface_ = new SourceProp(sv->source(), group_box_);

            break;
        }
        case ElementView::TypeView::WALLVIEW:
        {
            WallView * wv = dynamic_cast<WallView *> (ev);
            prop_interface_ = new WallProp(wv->wall(), group_box_);

            break;
        }
        }
    }

    if (prop_interface_ != nullptr)
    {
        group_box_->layout()->addWidget(prop_interface_);
        apply_pb_->setEnabled(true);
        delete_pb_->setEnabled(true);
    }
    else
    {
        apply_pb_->setEnabled(false);
        delete_pb_->setEnabled(false);
    }
}

void Properties::apply_changes()
{
    if (prop_interface_ != nullptr)
    {
        prop_interface_->apply();
        apply_pb_->setEnabled(true);
    }

    notify_all(std::string("ELEMENT_CHANGED"));
}

void Properties::delete_element()
{
    notify_all(std::string("ELEMENT_DELETED"));
    set_element_prop(nullptr);
}
