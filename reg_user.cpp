#include "reg_user.h"
#include "ui_reg_user.h"

reg_user::reg_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg_user)
{
    ui->setupUi(this);
    connector = new SQL();
}

reg_user::~reg_user()
{
    delete ui;
}
void reg_user::on_le_login_textEdited(const QString &arg1)
{
    if(ui->le_login->text().length()<5){
        ch_login=0;
        ui->l_info->setText("Login musi skladać się z minimum 5 znaków.");
    }else{
        if(connector->select_login(ui->le_login->text())==1){
            ui->l_info->setText("Login jest już zajęty.");
            ch_login=0;
        }else{
            ui->l_info->setText("");
            ch_login=1;
        };
    };

}

void reg_user::on_pb_register_clicked()
{
    if((ui->le_haslo->text().length()>4) and (ui->le_haslo_2->text().length()>4) and (ui->le_haslo->text()==ui->le_haslo_2->text())){
            ch_haslo=1;
            ch_haslo_2=1;
    }
    if(ch_haslo==0 or ch_haslo_2==0 or ch_imie==0 or ch_login==0 or ch_mail==0 or ch_nazwisko==0){
        ui->l_info->setText("Sprawdź poprawność wprowadzonych danych");
    }else{
        if(connector->insert_user(ui->le_login->text(),ui->le_haslo->text(),ui->le_imie->text(),ui->le_nazwisko->text(),ui->le_mail->text(),1)==true){
            ui->l_info->setText("Konto stworzone pomyślnie");
        }else{
            ui->l_info->setText("Błąd tworzenia konta SQL-MYSQL");
        }
    }
}

void reg_user::on_pb_back_clicked()
{
    this->~reg_user();
}

void reg_user::on_le_haslo_2_textEdited(const QString &arg1)
{
    if(ui->le_haslo_2->text().length()<4){
        ui->l_info->setText("Hasło za krótkie");
        ch_haslo_2=0;
    }else{
        if(ui->le_haslo_2->text() != ui->le_haslo->text()){
            ui->l_info->setText("Hasła się różnią");
            ch_haslo_2=0;
        }else{
            ui->l_info->setText("");
            ch_haslo_2=1;
        }
    }
}

void reg_user::on_le_haslo_textEdited(const QString &arg1)
{
    if(ui->le_haslo->text().length()<4){
        ui->l_info->setText("Hasło za krótkie");
        ch_haslo=0;
    }else{
        if(ui->le_haslo_2->text() != ui->le_haslo->text()){
            ui->l_info->setText("Hasła się różnią");
            ch_haslo=0;
        }else{
            ui->l_info->setText("");
            ch_haslo=1;
        }
    }
}

void reg_user::on_le_imie_textEdited(const QString &arg1)
{
    if(ui->le_imie->text().length()<3){
        ui->l_info->setText("Za krótkie imię.");
        ch_imie=0;
    }else{
        ui->l_info->setText("");
        ch_imie=1;
    }
}

void reg_user::on_le_nazwisko_textEdited(const QString &arg1)
{
    if(ui->le_nazwisko->text().length()<3){
        ui->l_info->setText("Za krótkie nazwisko.");
        ch_nazwisko=0;
    }else{
        ui->l_info->setText("");
        ch_nazwisko=1;
    }
}

void reg_user::on_le_mail_textEdited(const QString &arg1)
{
    QRegExp mail("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mail.setCaseSensitivity(Qt::CaseInsensitive);
    mail.setPatternSyntax(QRegExp::RegExp);
    if(!mail.exactMatch(ui->le_mail->text()))
    {
        ui->l_info->setText("Błędny adres e-mail");
        ch_mail=0;
    }else{
        ui->l_info->setText("");
        ch_mail=1;
    }
}
