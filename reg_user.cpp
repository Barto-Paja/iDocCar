#include "reg_user.h"
#include "ui_reg_user.h"

reg_user::reg_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg_user)
{
    ui->setupUi(this);
    connector = new SQL();
    ui->pb_register->setVisible(false);
}

reg_user::~reg_user()
{
    delete ui;
}
void reg_user::on_le_login_textEdited(const QString &arg1)
{
    temp_login=ui->le_login->text();
    if(ui->le_login->text().length()<5){
        ui->pb_register->setVisible(false);
        ui->l_info->setText("Login musi skladać się z minimum 5 znaków.");
    }else{
        if(connector->select_login(temp_login)==1){
            ui->l_info->setText("Login jest już zajęty.");
            ui->pb_register->setVisible(false);
        }else{
            ui->l_info->setText("");
            ui->pb_register->setVisible(true);
        };
    };

}

void reg_user::on_pb_register_clicked()
{

}
