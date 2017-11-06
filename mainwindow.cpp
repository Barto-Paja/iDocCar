#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <r_costs.h>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    r_Costs* form = new r_Costs;
    form->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
