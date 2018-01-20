#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QComboBox>
#include <sql.h>

namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_cb_user_currentIndexChanged(const QString &arg1);

    void on_cb_car_activated(const QString &arg1);

private:
    Ui::admin *ui;

    SQL *connector;
    void loadCombobox(QComboBox *combo, int cbIndx);
    void update_driver(int id);
    void update_car(int id);

    int ch_u_id = 0;
    int ch_c_id = 0;
};

#endif // ADMIN_H
