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

private:
    Ui::reg_user *ui;
    SQL *connector;
    QString temp_login;
};

#endif // REG_USER_H
