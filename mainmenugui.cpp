#include "mainmenugui.h"
#include "ui_mainmenugui.h"

MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    ui->setupUi(this);
    connector = new SQL("localhost","idoccar","root","");

    ui->l_welcome->setText("Witaj "+connector->welcomeFunc()+" !");
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
