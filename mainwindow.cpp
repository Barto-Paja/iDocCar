#include <mainwindow.h>
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //--- Wywoływanie okna raportów ---//

    r_Costs* form = new r_Costs;
    form->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
