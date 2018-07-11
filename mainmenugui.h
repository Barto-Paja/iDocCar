#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include <QMainWindow>

#include <newcar.h>
#include <newtank.h>
#include <newrepair.h>

#include <r_costs.h>
#include <r_workshop.h>
#include <formanalysis.h>

#include <sql.h>
#include <admin.h>
#include <ed_user.h>
#include <reg_user.h>

namespace Ui {
class MainMenuGUI;
}

class MainMenuGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuGUI(QWidget *parent = 0);
    ~MainMenuGUI();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainMenuGUI *ui;

    SQL *connector;
};

#endif // MAINMENUGUI_H
