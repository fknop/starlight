#include "starlightui.hpp"
#include "ui_starlightui.h"

StarlightUI::StarlightUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StarlightUI)
{
    ui->setupUi(this);
}

StarlightUI::~StarlightUI()
{
    delete ui;
}
