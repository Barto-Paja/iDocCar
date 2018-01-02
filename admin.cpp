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
        connector->CarName();
        while(connector->getCarName(stream,i)){
            combo->addItem(stream,i);
        }

    }
}

void admin::on_pushButton_2_clicked()
{
    delete ui;
}
