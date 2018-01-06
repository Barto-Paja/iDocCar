#ifndef ED_USER_H
#define ED_USER_H

#include <QMainWindow>
#include <QComboBox>
#include <sql.h>

namespace Ui {
class ed_user;
}

class ed_user : public QMainWindow
{
    Q_OBJECT

public:
    explicit ed_user(QWidget *parent = 0);
    ~ed_user();

private slots:
    void on_pushButton_clicked();
    void loadCombobox(QComboBox *combo, int cbIndx);
    void on_le_haslo_2_textEdited(const QString &arg1);
    void on_le_haslo_textEdited(const QString &arg1);
    void on_le_imie_textEdited(const QString &arg1);
    void on_le_nazwisko_textEdited(const QString &arg1);
    void on_le_mail_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::ed_user *ui;
    SQL *connector;
    int ch_imie, ch_nazwisko, ch_mail,ch_haslo,ch_haslo_2 = 0;
};

#endif // ED_USER_H
