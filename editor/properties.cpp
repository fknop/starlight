#include "crystalprop.h"
#include "lensprop.h"
#include "mirrorprop.h"
#include "nukeprop.h"
#include "wallprop.h"
#include "properties.h"

#include <iostream>

Properties::Properties(QWidget *parent) : QWidget(parent)
{
    setupUi();

    add_connections();
}

void Properties::add_connections()
{
    connect(apply_pb, SIGNAL(clicked()), this, SLOT(apply_changes()));
    connect(reset_pb, SIGNAL(clicked()), this, SLOT(reset_changes()));
    connect(delete_pb, SIGNAL(clicked()), this, SLOT(delete_element()));
}

void Properties::setupUi()
{
    std::cout << "setupUi prefs"<< std::endl;
    resize(400, 300);

    gridLayout = new QGridLayout();

    groupBox = new QGroupBox();
    groupBox->setTitle(tr("Properties"));
    QHBoxLayout * qhl = new QHBoxLayout;
    groupBox->setLayout(qhl);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    groupBox->setFont(font);

    gridLayout->addWidget(groupBox, 0, 0, 1, 3);

    apply_pb = new QPushButton();
    apply_pb->setText("Apply");
    apply_pb->setEnabled(false);

    gridLayout->addWidget(apply_pb, 1, 0, 1, 1);

    reset_pb = new QPushButton();
    reset_pb->setText("Reset");
    reset_pb->setEnabled(false);

    gridLayout->addWidget(reset_pb, 1, 1, 1, 1);

    delete_pb = new QPushButton();
    delete_pb->setText("Delete");
    delete_pb->setEnabled(false);

    gridLayout->addWidget(delete_pb, 1, 2, 1, 1);

    setLayout(gridLayout);
}

void Properties::set_element_prop(ElementView * ev)
{
    std::cout << "[Properties - set_element_prop]" << std::endl;

    if (prop_interface_ != nullptr)
    {
        delete prop_interface_;
        prop_interface_ = nullptr;
    }

    if (ev != nullptr)
    {
        switch(ev->type_view())
        {
        case ElementView::TypeView::MIRRORVIEW:
        {
            MirrorView * mv = dynamic_cast<MirrorView *> (ev);
            prop_interface_ = new MirrorProp(mv->mirror(), groupBox);

            break;
        }
        case ElementView::TypeView::CRYSTALVIEW:
        {
            CrystalView * cv = dynamic_cast<CrystalView *> (ev);
            prop_interface_ = new CrystalProp(cv->crystal(), groupBox);

            break;
        }
        case ElementView::TypeView::LENSVIEW:
        {
            LensView * lv = dynamic_cast<LensView *> (ev);
            prop_interface_ = new LensProp(lv->lens(), groupBox);

            break;
        }
        case ElementView::TypeView::NUKEVIEW:
        {
            NukeView * nv = dynamic_cast<NukeView *> (ev);
            prop_interface_ = new NukeProp(nv->nuke(), groupBox);

            break;
        }
        case ElementView::TypeView::WALLVIEW:
        {
            WallView * wv = dynamic_cast<WallView *> (ev);
            prop_interface_ = new WallProp(wv->wall(), groupBox);

            break;
        }
        default:
        {
            std::cout << "Unknown ElementView" << std::endl;
        }
        }

        groupBox->layout()->addWidget(prop_interface_);
    }

    apply_pb->setEnabled(true);
    reset_pb->setEnabled(true);
    delete_pb->setEnabled(true);
}

void Properties::apply_changes()
{
    prop_interface_->apply();
    apply_pb->setEnabled(true);
    reset_pb->setEnabled(true);

    notify_all("ELEMENT_CHANGED");
}

void Properties::reset_changes()
{
    prop_interface_->reset();
    apply_pb->setEnabled(true);
    reset_pb->setEnabled(true);
}

void Properties::delete_element()
{
    notify_all("ELEMENT_DELETED");
}
