#include "newrepair.h"
#include "ui_newrepair.h"

newRepair::newRepair(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newRepair)
{
    ui->setupUi(this);
}

newRepair::~newRepair()
{
    delete ui;
}
