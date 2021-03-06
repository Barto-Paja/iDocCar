#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    connector = new SQL();

    loadCombobox(ui->cb_user,1);
    loadCombobox(ui->cb_car,2);
    ch_u_id=ui->cb_user->currentData().toInt();
    ch_c_id=ui->cb_car->currentData().toInt();

    //update_car(ch_c_id);
    //update_driver(ch_u_id);
    on_cb_car_activated(QString("start0"));
}

admin::~admin()
{
    delete ui;
}

void admin::loadCombobox(QComboBox *combo, int cbIndx)
{
    if(cbIndx==1)
    {
        combo->clear();
        QString stream;
        int i=0;
        connector->Users();
        while (connector->getUsers(stream,i)) {
            combo->addItem(stream,i);
       }
    }
    else if(cbIndx==2)
    {
        combo->clear();
        QString stream;
        int i=0;
        connector->CarNames();
        while(connector->getCarName(stream,i)){
            combo->addItem(stream,i);
        }

    }
}

void admin::update_driver(int id)
{
    ui->l_imie->setText(connector->select_u_fname(id));
    ui->l_nazwisko->setText(connector->select_u_lname(id));
    ui->l_login->setText(connector->select_login_n(id));
}

void admin::update_car(int id)
{
    ui->l_marka->setText(connector->select_cmark(id));
    ui->l_model->setText(connector->select_cmodel(id));
    ui->l_rej->setText(connector->getPlate(id));
    QString przeb;
    przeb.setNum(connector->lastMilage(id));
    ui->l_przebieg->setText(przeb);
}

void admin::on_pushButton_2_clicked()
{
    this->~admin();
}

void admin::on_pushButton_clicked()
{
    if(connector->conn_car_user(ch_u_id,ch_c_id)==true){
        ui->l_info->setText("Zapisano zmiany");
    }else{
        ui->l_info->setText("Błąd SQL-MYSQL");
    }
}

void admin::on_cb_user_currentIndexChanged(const QString &arg1)
{
    update_driver(ui->cb_user->currentData().toInt());
    ch_u_id = ui->cb_user->currentData().toInt();
}

void admin::on_cb_car_activated(const QString &arg1)
{
    //SQL *testowa = new SQL;
    connector->CarQuest(ui->cb_car->currentData().toInt());
    ui->l_marka->setText(connector->CarInfo(0));
    ui->l_model->setText(connector->CarInfo(1));
    ui->l_rej->setText(connector->CarInfo(2));
    ui->l_przebieg->setText(QString::number(connector->lastMilage(ui->cb_car->currentData().toInt())));

    ch_c_id = ui->cb_car->currentData().toInt();
}
