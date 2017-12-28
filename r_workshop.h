#ifndef R_WORKSHOP_H
#define R_WORKSHOP_H

#include <QDialog>
#include <QComboBox>

#include <sql.h>

namespace Ui {
class r_Workshop;
}

class r_Workshop : public QDialog
{
    Q_OBJECT

public:
    explicit r_Workshop(QWidget *parent = 0);
    ~r_Workshop();

private slots:
    void on_pushButton_clicked();

    void on_b_load_clicked();

private:
    Ui::r_Workshop *ui;
    void loadComboBox(QComboBox *combo);

    SQL *connector;
};

#endif // R_WORKSHOP_H
