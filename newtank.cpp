#include "newtank.h"
#include "ui_newtank.h"

newTank::newTank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newTank)
{
    ui->setupUi(this);
    connector = new SQL("localhost","idoccar","root","");

    connector->test();

    //--- Load Combox for Tank ---//

    ui->cb_tanktype->clear();
    ui->cb_tanktype->addItem("ON/Pb",0);
    ui->cb_tanktype->addItem("LPG",1);

    loadComboBox();

    //--- Load Combox for Tank ---//

//    wskQb->groupNames();
//    ui->comboBox->clear();
//    QString stream;
//    int i=0;
//    while (wskQb->getGroupName(stream,i)) {
//        ui->comboBox->addItem(stream,i);

//    }
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
    while (connector->getCarName(stream)) {
        ui->cb_carid->addItem(stream,i);
   }

}

void newTank::on_b_send_clicked()
{
//    float contribution = (le_fuel->text().toFloat()/ui->le_milage->text().toInt()*100);
//    int carid = ui->cb_carid->findData(1);
//    connector->insert_fuel(ui->le_date->text(),ui->le_fuel->text().toFloat(),ui->le_price->text().toFloat(),ui->le_milage->text().toInt(),contribution,1,ui->le_notes->text(),);
}
