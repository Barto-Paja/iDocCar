#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <reg_user.h>


#include <sql.h>
#include <mainmenugui.h>
#include <ed_pass.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_p_register_clicked();

    void on_b_helpdesk_clicked();

private:
    Ui::MainWindow *ui;

    SQL *connector;
};

#endif // MAINWINDOW_H
