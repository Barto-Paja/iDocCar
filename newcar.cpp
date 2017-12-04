#include "newcar.h"
#include "ui_newcar.h"

newCar::newCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newCar)
{
    ui->setupUi(this);
    connector = new SQL();

    connector->test();
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
    if(formularCheck())
    {
        if(ui->checkBox->isEnabled())
        {
            connector->insert_car(ui->le_mark->text(),ui->le_model->text(),ui->le_plate->text(),ui->le_vin->text(),ui->le_year->text(),ui->lineEdit->text(),2,ui->le_milage->text().toInt(),ui->le_Tank1->text().toFloat(),ui->le_Tank2->text().toFloat());
            QMessageBox::information(0,"Sukces","Dodano pojazd");
            this->close();
            this->deleteLater();
        }
        else
        {
            if(ui->radioButton->isChecked())
            {
                connector->insert_car(ui->le_mark->text(),ui->le_model->text(),ui->le_plate->text(),ui->le_vin->text(),ui->le_year->text(),ui->lineEdit->text(),0,ui->le_milage->text().toInt(),ui->le_Tank1->text().toFloat(),0);
                QMessageBox::information(0,"Sukces","Dodano pojazd");
                this->close();
                this->deleteLater();
            }
            else
                connector->insert_car(ui->le_mark->text(),ui->le_model->text(),ui->le_plate->text(),ui->le_vin->text(),ui->le_year->text(),ui->lineEdit->text(),1,ui->le_milage->text().toInt(),ui->le_Tank1->text().toFloat(),0);
                QMessageBox::information(0,"Sukces","Dodano pojazd");
                this->close();
                this->deleteLater();
        }
    }
}

bool newCar::formularCheck()
{
    if(ui->le_mark->text().length()<=0)
    {
        QMessageBox::information(0,"Błąd formularza","Wprowadź markę");
        return false;
    }
    else if(ui->le_model->text().length()<=0)
    {
        QMessageBox::information(0,"Błąd formularza","Wprowadź model");
        return false;
    }
    else if(ui->le_plate->text().length()<=0)
    {
        QMessageBox::information(0,"Błąd formularza","Wprowadź nr rejestracyjny");
        return false;
    }
    else if(ui->le_milage->text().length()<=0)
    {
        QMessageBox::information(0,"Błąd formularza","Wprowadź przebieg");
        return false;
    }
    else if(ui->le_vin->text().length()<=0)
    {
        QMessageBox::information(0,"Błąd formularza","Wprowadź VIN pojazdu");
        return false;
    }
    else if(ui->checkBox->isChecked() && ui->le_Tank2->text().length()==0)
    {
        QMessageBox::information(0,"Błąd formularza","Nie wprowadzono stanu LPG");
        return false;
    }
    else if(ui->le_Tank1->text().length()==0)
    {
        QMessageBox::information(0,"Błąd formularza","Nie wprowadzono stanu paliwa");
        return false;
    }
    else if(ui->radioButton->isChecked()==false && ui->radioButton_2->isChecked()==false)
    {
        QMessageBox::information(0,"Błąd formularza","Nie określono typu paliwa");
        return false;
    }
//    else if((ui->de_insurance->date().daysTo(QDate::currentDate()))>=0)
//    {
//        QMessageBox::information(0,"Błąd formularza","Data jest wcześniejsza niż dzień dzisiejszy/nWykup OC/AC i wprowadź nową datę!");
//        return false;
//    }
    else
        return true;


}
