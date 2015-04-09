#include "properties.h"
#include "mirrorprop.h"

#include <iostream>

Properties::Properties(QWidget *parent) : QWidget(parent)
{
    setupUi();
    set_element_prop();

    add_connections();

}

void Properties::add_connections()
{
    connect(apply_pb, SIGNAL(clicked()), this, SLOT(create_level()));
    connect(reset_pb, SIGNAL(clicked()), this, SLOT(reset_level()));
}

void Properties::setupUi()
{
    std::cout << "setupUi prefs"<< std::endl;
    resize(400, 300);

    gridLayout = new QGridLayout();

    groupBox = new QGroupBox();
    groupBox->setTitle(tr("Properties"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    groupBox->setFont(font);

    gridLayout->addWidget(groupBox, 0, 0, 1, 3);

//    buttonBox = new QDialogButtonBox();
//    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

//    gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

    apply_pb = new QPushButton();
    apply_pb->setText("Apply");

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

void Properties::set_element_prop()
{
    MirrorProp * mp = new MirrorProp(groupBox);
}
