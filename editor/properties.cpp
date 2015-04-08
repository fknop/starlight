#include "properties.h"
#include "mirrorprop.h"

#include <iostream>

Properties::Properties(QWidget *parent) : QWidget(parent)
{
    setupUi();
    set_element_prop();

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

    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    buttonBox = new QDialogButtonBox();
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

    setLayout(gridLayout);
}

void Properties::set_element_prop()
{
    MirrorProp * mp = new MirrorProp(groupBox);
}
