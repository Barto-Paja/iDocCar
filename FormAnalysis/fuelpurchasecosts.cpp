#include "fuelpurchasecosts.h"

FuelPurchaseCosts::FuelPurchaseCosts()
{
    seriesFuelPurchaseCosts = new QBarSet("Koszt miesięczny zakupu paliw");
    handler = new RequestHandleAnalysis;
}

FuelPurchaseCosts::~FuelPurchaseCosts()
{
    delete handler;
    delete seriesFuelPurchaseCosts;
}

void FuelPurchaseCosts::LoadSeries(QDate early, QDate late, char fuelType)
{
    int monthsTo =(late.year()-early.year())*12+late.month()-early.month();
    qDebug() << monthsTo;

    int monthsTo =(late.year()-early.year())*12+late.month()-early.month();
    qDebug() << monthsTo;

    if(fuelType=="DIESEL"){

        for(int i=0;i<monthsTo;++i){
           *seriesFuelPurchaseCosts << handler->fuelsCosts(QString("DIESEL"),early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
        }
    }
    else if(fuelType=="PB"){
        for(int i=0;i<monthsTo;++i){
           *seriesFuelPurchaseCosts << handler->fuelsCosts(QString("PB"),early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
        }
    }
    else if(fuelType=="LPG"){
        for(int i=0;i<monthsTo;++i){
           *seriesFuelPurchaseCosts << handler->fuelsCosts(QString("LPG"),early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
        }
    }
    else{
        qDebug() << "FuelType Error";
        return;
    }


}
