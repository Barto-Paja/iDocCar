#include "ed_pass.h"
#include "ui_ed_pass.h"

ed_pass::ed_pass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ed_pass)
{
    ui->setupUi(this);
    connector = new SQL();
    ch_haslo=0;
    ch_haslo_2=0;
}

ed_pass::~ed_pass()
{
    delete ui;
}

void ed_pass::on_pb_cancel_clicked()
{
    this->~ed_pass();
}

void ed_pass::on_pb_ok_clicked()
{
    if((ui->le_pass->text().length()>=4) and (ui->le_pass_2->text().length()>=4) and (ui->le_pass->text()==ui->le_pass_2->text())){
            ch_haslo=1;
            ch_haslo_2=1;
    }
    if(ch_haslo==0 or ch_haslo_2==0){
        ui->l_info->setText("Sprawdź poprawność wprowadzonych danych");
    }else{
        if(connector->change_pass(ui->le_pass->text())==true){
            ui->l_info->setText("Hasło zmienione pomyślnie");
            ui->pb_ok->setVisible(false);
            ui->pb_cancel->setText("Zamknij");
        }else{
            ui->l_info->setText("Błąd zmiany hasła SQL-MYSQL");
        }
    }
}

void ed_pass::on_le_pass_textChanged(const QString &arg1)
{
    if(ui->le_pass->text().length()<4){
        ui->l_info->setText("Hasło za krótkie");
        ch_haslo=0;
    }else{
        if(ui->le_pass_2->text() != ui->le_pass->text()){
            ui->l_info->setText("Hasła się różnią");
            ch_haslo=0;
        }else{
            ui->l_info->setText("");
            ch_haslo=1;
        }
    }
}

void ed_pass::on_le_pass_2_textChanged(const QString &arg1)
{
    if(ui->le_pass_2->text().length()<4){
        ui->l_info->setText("Hasło za krótkie");
        ch_haslo_2=0;
    }else{
        if(ui->le_pass_2->text() != ui->le_pass->text()){
            ui->l_info->setText("Hasła się różnią");
            ch_haslo_2=0;
        }else{
            ui->l_info->setText("");
            ch_haslo_2=1;
        }
    }
}
