#ifndef NEWCAR_H
#define NEWCAR_H

#include <QDialog>
#include <QMessageBox>
#include <sql.h>

namespace Ui {
class newCar;
}

class newCar : public QDialog
{
    Q_OBJECT

public:
    explicit newCar(QWidget *parent = 0);
    ~newCar();

private slots:
    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void on_checkBox_toggled(bool checked);

    void on_b_send_clicked();

private:
    Ui::newCar *ui;

    bool formularCheck();
    SQL *connector;
};

#endif // NEWCAR_H
