#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include <QMainWindow>

#include <newcar.h>
#include <newtank.h>
#include <newrepair.h>

#include <r_costs.h>

#include <sql.h>

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

private:
    Ui::MainMenuGUI *ui;

    SQL *connector;
};

#endif // MAINMENUGUI_H
