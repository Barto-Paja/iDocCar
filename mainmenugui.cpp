#include "mainmenugui.h"
#include "ui_mainmenugui.h"

MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    ui->setupUi(this);
}

MainMenuGUI::~MainMenuGUI()
{
    delete ui;
}

void MainMenuGUI::on_pushButton_clicked()
{
    newCar *form = new newCar;
    form->show();
}
