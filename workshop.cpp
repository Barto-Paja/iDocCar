#include "workshop.h"
#include "ui_workshop.h"

Workshop::Workshop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workshop)
{
    ui->setupUi(this);
}

Workshop::~Workshop()
{
    delete ui;
}
