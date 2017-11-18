#ifndef NEWTANK_H
#define NEWTANK_H

#include <QDialog>
#include <QMessageBox>

#include <sql.h>

namespace Ui {
class newTank;
}

class newTank : public QDialog
{
    Q_OBJECT

public:
    explicit newTank(QWidget *parent = 0);
    ~newTank();

private slots:
    void on_b_send_clicked();

private:
    Ui::newTank *ui;

    void loadComboBox();

    SQL *connector;
};

#endif // NEWTANK_H
