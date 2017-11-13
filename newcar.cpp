#include "newcar.h"
#include "ui_newcar.h"

newCar::newCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newCar)
{
    ui->setupUi(this);
}

newCar::~newCar()
{
    delete ui;
}

void newCar::on_radioButton_2_toggled(bool checked)
{
    ui->checkBox->setEnabled(true);
}

void newCar::on_radioButton_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    ui->checkBox->setChecked(false);
    ui->le_Tank2->setEnabled(false);
    ui->le_Tank2->clear();
}

void newCar::on_checkBox_toggled(bool checked)
{
    ui->le_Tank2->setEnabled(true);
    if(ui->checkBox->checkState() == Qt::Unchecked)
    {
        ui->le_Tank2->setEnabled(false);
        ui->le_Tank2->clear();
    }
}

void newCar::on_b_send_clicked()
{

}
