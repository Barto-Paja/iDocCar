#include "ed_user.h"
#include "ui_ed_user.h"

ed_user::ed_user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ed_user)
{
    ui->setupUi(this);
    connector = new SQL();
    loadCombobox(ui->cb_user,1);
    loadCombobox(ui->cb_grupa,2);
    ch_u_id=ui->cb_user->currentData().toInt();
    update_info(ch_u_id);
}

ed_user::~ed_user()
{
    delete ui;
}

void ed_user::on_pushButton_clicked()
{
    this->~ed_user();
}

void ed_user::loadCombobox(QComboBox *combo, int cbIndx)
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
        connector->Lvl();
        while(connector->getLvl(stream,i)){
            combo->addItem(stream,i);
        }

    }
}

void ed_user::on_le_haslo_2_textEdited()
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

void ed_user::on_le_haslo_textEdited()
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

void ed_user::on_le_imie_textEdited()
{
    if(ui->le_imie->text().length()<3){
        ui->l_info->setText("Za krótkie imię.");
        ch_imie=0;
    }else{
        ui->l_info->setText("");
        ch_imie=1;
    }
}

void ed_user::on_le_nazwisko_textEdited()
{
    if(ui->le_nazwisko->text().length()<3){
        ui->l_info->setText("Za krótkie nazwisko.");
        ch_nazwisko=0;
    }else{
        ui->l_info->setText("");
        ch_nazwisko=1;
    }
}

void ed_user::on_le_mail_textEdited()
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

void ed_user::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked()){
        chck_bx=1;
    }else{
        chck_bx=0;
    }
    if((ui->le_haslo->text().length()>4) and (ui->le_haslo_2->text().length()>4) and (ui->le_haslo->text()==ui->le_haslo_2->text())){
            ch_haslo=1;
            ch_haslo_2=1;
    }
    if(ch_haslo==0 or ch_haslo_2==0 or ch_imie==0 or ch_mail==0 or ch_nazwisko==0){
        ui->l_info->setText("Sprawdź poprawność wprowadzonych danych");
    }else{
        if(connector->editUser(ch_u_id,ui->le_imie->text(),ui->le_nazwisko->text(),ui->le_haslo->text(),ui->le_mail->text(),ui->cb_grupa->currentData().toInt(), chck_bx)==true){
            ui->l_info->setText("Zapisano zmiany");
            ui->pushButton->setText("Zamknij");
        }else{
            ui->l_info->setText("Błąd SQL-MYSQL");
        }
    }
}

void ed_user::on_cb_user_currentIndexChanged()
{
    ch_u_id=ui->cb_user->currentData().toInt();
    this->update_info(ch_u_id);
    ch_imie=1;
    ch_nazwisko=1;
    ch_mail=1;
    ch_haslo=1;
    ch_haslo_2=1;
}

void ed_user::update_info(int id)
{
    ui->le_imie->setText(connector->select_u_fname(id));
    ui->le_nazwisko->setText(connector->select_u_lname(id));
    ui->le_mail->setText(connector->selec_u_mail(id));
    ui->le_haslo->setText(connector->select_u_pass(id));
    ui->le_haslo_2->setText(connector->select_u_pass(id));
    int index = ui->cb_grupa->findData(connector->select_u_lvl(id));
    ui->cb_grupa->setCurrentIndex(index);
}

void ed_user::on_button_del_clicked()
{
    if(connector->del_user(ch_u_id)==true){
        ui->l_info->setText("Usunięto użytkownika");
        ui->cb_user->removeItem(ui->cb_user->currentIndex());
        ui->pushButton->setText("Zamknij");
    }else{
        ui->l_info->setText("Nie udało się usunąc użytkownika");
    };

}
