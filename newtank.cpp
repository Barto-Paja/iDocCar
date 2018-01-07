#include "newtank.h"
#include "ui_newtank.h"

#include <QDebug>

newTank::newTank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newTank)
{
    ui->setupUi(this);
    connector = new SQL();

    ui->cb_tanktype->clear();
    ui->cb_tanktype->addItem("ON",0);
    ui->cb_tanktype->addItem("Pb",1);
    ui->cb_tanktype->addItem("LPG",2);

    loadComboBox();
    ui->dateEdit->setDate(QDate::currentDate());
}

newTank::~newTank()
{
    delete ui;
}

void newTank::loadComboBox()
{
    ui->cb_carid->clear();
    QString stream;
    int i=0;
    connector->CarName();
    while (connector->getCarName(stream,i)) {
        ui->cb_carid->addItem(stream,i);
   }

}

void newTank::on_b_send_clicked()
{


      int lastMilage = connector->lastMilage(ui->cb_carid->currentData().toInt());
      float contribution = (ui->le_fuel->text().toFloat()/(ui->le_milage->text().toInt()-lastMilage)*100);
      double cont = contribution;
      qDebug() << contribution << lastMilage;
      double tankI = connector->carTankInfo(ui->cb_carid->currentData().toInt(),ui->cb_tanktype->currentData().toInt());

      if((ui->le_milage->text().toInt()-lastMilage)<0)
      {
         QMessageBox::information(0,"Przebieg","Czy na pewno wprowadziłeś poprawny przebieg? Ostatni przebieg w bazie dla tego auta to: "+QString::number(lastMilage)+"km");
      }
      else if(ui->le_fuel->text().toInt()>tankI)
      {
          QMessageBox::information(0,"Pojemność Baku","Czy na pewno wprowadziłeś poprawnie ilośc zatankowanego paliwa? Pojemnośc zbiornika tego auta to: "+QString::number(tankI)+" litrów");
      }
      else
      {
          QString date = ui->dateEdit->date().toString("yyyy-MM-dd");

          if(ui->cb_tanktype->currentData().toInt()==0)
          {
              connector->fuelInfo(ui->cb_carid->currentData().toInt());

              if(connector->fuelInfoQuest()==0)
              {
                  connector->insert_fuel(date,ui->le_fuel->text().toFloat(),ui->le_price->text().toFloat(),ui->le_milage->text().toInt(),cont,0,ui->le_notes->text(),ui->cb_carid->currentData().toInt());
                  QMessageBox::information(0,"Dodwanie tankowania","Tankowanie dodane pomyślnie");
                  this->close();
                  this->deleteLater();
              }
              else
              {
                  QMessageBox::information(0,"Dodwanie tankowania","Dodawanie tankowania nie powiodło się - auto nie używa ON!");
                  this->close();
                  this->deleteLater();
              }


          }
          else if(ui->cb_tanktype->currentData().toInt()==1)
          {

            connector->fuelInfo(ui->cb_carid->currentData().toInt());
            if(connector->fuelInfoQuest()>=1)
            {
                connector->insert_fuel(date,ui->le_fuel->text().toFloat(),ui->le_price->text().toFloat(),ui->le_milage->text().toInt(),cont,1,ui->le_notes->text(),ui->cb_carid->currentData().toInt());
                QMessageBox::information(0,"Dodwanie tankowania","Tankowanie dodane pomyślnie");
                this->close();
                this->deleteLater();
            }
            else
            {
                QMessageBox::information(0,"Dodwanie tankowania","Dodawanie tankowania nie powiodło się - auto nie używa Pb!");
                this->close();
                this->deleteLater();
            }
          }
          else if(ui->cb_tanktype->currentData().toInt()==2)
          {
             connector->insert_fuel(date,ui->le_fuel->text().toFloat(),ui->le_price->text().toFloat(),ui->le_milage->text().toInt(),contribution,2,ui->le_notes->text(),ui->cb_carid->currentData().toInt());
             QMessageBox::information(0,"Dodwanie tankowania","Tankowanie dodane pomyślnie");
             this->close();
             this->deleteLater();
          }
      }



}
