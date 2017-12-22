#ifndef NEWREPAIR_H
#define NEWREPAIR_H

#include <QDialog>
#include <QComboBox>
#include <sql.h>

namespace Ui {
class newRepair;
}

class newRepair : public QDialog
{
    Q_OBJECT

public:
    explicit newRepair(QWidget *parent = 0);
    ~newRepair();

private slots:
    void on_b_addnew_clicked();

private:
    Ui::newRepair *ui;

    SQL *connector;

    void loadCombobox(QComboBox *combo, int cbIndx);
    bool formularCheck();

};

#endif // NEWREPAIR_H
