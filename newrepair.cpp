#include "newrepair.h"
#include "ui_newrepair.h"

newRepair::newRepair(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newRepair)
{
    ui->setupUi(this);
    connector = new SQL;

    loadCombobox(ui->cb_carid,1);
    loadCombobox(ui->cb_ctype,2);
    ui->dateEdit->setDate(QDate::currentDate());
}

newRepair::~newRepair()
{
    delete connector;
    delete ui;
}

void newRepair::loadCombobox(QComboBox *combo, int cbIndx)
{
    if(cbIndx==1)
    {
        combo->clear();
        QString stream;
        int i=0;
        connector->CarName();
        while (connector->getCarName(stream,i)) {
            combo->addItem(stream,i);
       }
    }
    else if(cbIndx==2)
    {
        combo->clear();
        QString stream;
        int i=0;
        connector->CostNames();
        while(connector->getCostName(stream,i)){
            combo->addItem(stream,i);
        }

    }
}

bool newRepair::formularCheck()
{
    int l1 = ui->le_cost->text().length();
    int l2 = ui->le_milage->text().length();
    int l3 = ui->le_note->text().length();
    int l4 = ui->le_title->text().length();
    if(l1==0 || l2==0 || l3==0 || l4==0)
    {
        return false;
    }
    else
        return true;
}

void newRepair::on_b_addnew_clicked()
{
    if(formularCheck())
    {
        QString date;
        date = ui->dateEdit->date().toString("yyyy-MM-dd");
        connector->insert_cost(ui->le_title->text(),date,ui->cb_ctype->currentData().toInt(),ui->le_note->text(),ui->le_milage->text().toInt(),ui->le_cost->text().toFloat(),ui->cb_carid->currentData().toInt());
        QMessageBox::information(0,"Warsztat","Dodano pomyślnie");
        this->close();
        this->deleteLater();
    }
    else
    {
        QMessageBox::information(0,"Warsztat","Sprawdź, czy uzupełniłeś wszystkie pola");
    }
}
