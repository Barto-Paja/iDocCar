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

private:
    Ui::admin *ui;

    SQL *connector;
    void loadCombobox(QComboBox *combo, int cbIndx);
};

#endif // ADMIN_H
