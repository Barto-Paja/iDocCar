#include "mainmenugui.h"
#include "ui_mainmenugui.h"

MainMenuGUI::MainMenuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuGUI)
{
    ui->setupUi(this);
    connector = new SQL();

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

void MainMenuGUI::on_pushButton_2_clicked()
{
    newTank *form = new newTank;
    form->show();
}

void MainMenuGUI::on_pushButton_3_clicked()
{
    r_Costs *form = new r_Costs;
    form->show();
}

void MainMenuGUI::on_pushButton_4_clicked()
{
    newRepair *form = new newRepair;
    form->show();
}
