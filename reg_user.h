#ifndef REG_USER_H
#define REG_USER_H

#include <QDialog>
#include <sql.h>

namespace Ui {
class reg_user;
}

class reg_user : public QDialog
{
    Q_OBJECT

public:
    explicit reg_user(QWidget *parent = 0);
    ~reg_user();

private slots:
    void on_le_login_textEdited(const QString &arg1);

    void on_pb_register_clicked();

    void on_pb_back_clicked();

    void on_le_haslo_2_textEdited(const QString &arg1);

    void on_le_haslo_textEdited(const QString &arg1);

    void on_le_imie_textEdited(const QString &arg1);

    void on_le_nazwisko_textEdited(const QString &arg1);

    void on_le_mail_textEdited(const QString &arg1);

private:
    Ui::reg_user *ui;
    SQL *connector;
    int ch_imie, ch_nazwisko, ch_mail,ch_login,ch_haslo,ch_haslo_2 = 0;
};

#endif // REG_USER_H
