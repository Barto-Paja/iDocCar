#include "r_workshop.h"
#include "ui_r_workshop.h"

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QtPrintSupport>

r_Workshop::r_Workshop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::r_Workshop)
{
    ui->setupUi(this);
    connector = new SQL;

    //ui->l_vfuel2->setVisible(false);
    //ui->l_vfuel2->hide();
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(pal);
    loadComboBox(ui->cb_carid);
}

r_Workshop::~r_Workshop()
{
    delete ui;
}

void r_Workshop::on_pushButton_clicked()
{
    auto tmp = ui->widget->grab();
    QImage image = tmp.toImage();

    QTextDocument doc;
    QTextCursor tc(&doc);
    tc.insertImage(image,QString("Raport"));

    QPrinter printer(QPrinter::HighResolution); //= new QPrinter(QPrinter::HighResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setOutputFileName("Raport roczny.pdf");
             printer.setPaperSize(QSizeF(210,297),QPrinter::Millimeter);
             printer.setPageMargins(5, 5, 5, 5, QPrinter::Millimeter);
     doc.print(&printer);

}

void r_Workshop::loadComboBox(QComboBox *combo)
{
    combo->clear();
    //ui->cb_carid->clear();
    QString stream;
    int i=0;
    connector->CarName();
    while (connector->getCarName(stream,i)) {
        combo->addItem(stream,i);
    //ui->cb_carid->addItem(stream,i);
    }
}


void r_Workshop::on_b_load_clicked()
{
    ui->l_vfuel2->clear();
    int w;

    int i = ui->cb_carid->currentData().toInt();
    ui->l_carname->setText(connector->CarName(i));
    ui->l_plate->setText(connector->getPlate(i));
    ui->l_vmilage->setText(QString::number(connector->lastMilage(i)));
    ui->l_vtanktype->setText(connector->fuelWInfo(i));
    QString date = QString::number(ui->dateEdit->date().year());

    if(connector->fuelWInfo(i)=="Diesel")
    {
        ui->l_vfuel1->setText(QString::number(connector->fuelCountCost(i,0,date)));
        ui->l_vf1f2->setText(QString::number(connector->fuelCountCost(i,0,date))+" zł");
        w = connector->fuelCountCost(i,0,date);
    }
    else if(connector->fuelWInfo(i)=="Pb")
    {
        ui->l_vfuel1->setText(QString::number(connector->fuelCountCost(i,1,date)));
        ui->l_vf1f2->setText(QString::number(connector->fuelCountCost(i,1,date))+" zł");
        w = connector->fuelCountCost(i,1,date);
    }
    else if(connector->fuelWInfo(i)=="Pb+LPG")
    {
        ui->l_vfuel1->setText(QString::number(connector->fuelCountCost(i,1,date)));
        ui->l_vfuel2->setText(QString::number(connector->fuelCountCost(i,2,date)));

        float temp = connector->fuelCountCost(i,1,date) + connector->fuelCountCost(i,2,date);
        ui->l_vf1f2->setText(QString::number(temp)+" zł");
        w = temp;
    }
    else
        ui->l_vfuel1->setText("Error");

    ui->l_vBiD->setText(QString::number(connector->costCountCost(i,4)));
    ui->l_vPiL->setText(QString::number(connector->costCountCost(i,5)));
    ui->l_vK->setText(QString::number(connector->costCountCost(i,3)));
    ui->l_vN->setText(QString::number(connector->costCountCost(i,2)));
    ui->l_vOAN->setText(QString::number(connector->costCountCost(i,6)));
    ui->l_vZE->setText(QString::number(connector->costCountCost(i,1)));

    float tcost=0;
    int j=1;
    while(j<7)
    {
        tcost=tcost+connector->costCountCost(i,j);
        ++j;
    }
    ui->l_vKonserwacja->setText(QString::number(tcost)+" zł");

    ui->l_vSuma->setText(QString::number(tcost+w)+" zł");
}
