#include <mainwindow.h>
#include "ui_mainwindow.h"

#include <QDate>
#include <mainmenugui.h>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDate c_date = QDate::currentDate();
    ui->label->setText(c_date.toString());
      
    ui->pushButton_4->clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(connector->isUser(ui->le_login->text(),ui->le_pass->text()))
    {
        MainMenuGUI *form2 = new MainMenuGUI;
        form2->show();
    }
    else
        ui->l_message->setText("Błąd U-001 - Niepoprawny login lub hasło");


}

void MainWindow::on_pushButton_4_clicked()
{
    connector = new SQL();
    if(connector->isOpen())
    {
        ui->le_login->setEnabled(true);
        ui->le_pass->setEnabled(true);
        ui->pushButton_3->setVisible(true);
        ui->p_register->setVisible(true);
        ui->pushButton_4->setVisible(false);
        ui->l_message->setText("Połączono z bazą danych, możesz się zalogować");
    }
    else
    {
        ui->l_message->setText("Błąd C-001 - Nie połączono z bazą danych");
        ui->pushButton_3->setVisible(false);
        ui->p_register->setVisible(false);
        ui->pushButton_4->setVisible(true);
        ui->le_login->setEnabled(false);
        ui->le_pass->setEnabled(false);
    }

}

void MainWindow::on_p_register_clicked()
{
    reg_user *form_reg = new reg_user();
    form_reg->show();
}
