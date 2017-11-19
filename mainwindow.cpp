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



    //--- Wywoływanie okna raportów ---//

    r_Costs* form = new r_Costs;
    form->show();

    //--- SQL Connector def ---//
    connector = new SQL("localhost","idoccar","root","");

    if(connector->isOpen())
    {
        ui->le_login->setEnabled(true);
        ui->le_pass->setEnabled(true);
    }
    else
        ui->l_message->setText("Błąd C-001 - Nie połączono z bazą danych");

    //ui->pushButton_3->setVisible(false);

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
