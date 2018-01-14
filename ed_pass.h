#ifndef ED_PASS_H
#define ED_PASS_H

#include <QDialog>
#include <sql.h>

namespace Ui {
class ed_pass;
}

class ed_pass : public QDialog
{
    Q_OBJECT

public:
    explicit ed_pass(QWidget *parent = 0);
    ~ed_pass();

private slots:
    void on_pb_cancel_clicked();

    void on_pb_ok_clicked();

    void on_le_pass_textChanged(const QString &arg1);

    void on_le_pass_2_textChanged(const QString &arg1);

private:
    Ui::ed_pass *ui;
    SQL *connector;
    int ch_haslo,ch_haslo_2;
};

#endif // ED_PASS_H
