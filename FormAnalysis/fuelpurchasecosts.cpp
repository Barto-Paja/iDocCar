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

void FuelPurchaseCosts::LoadSeries(QDate early, QDate late, QString fuelType, int carID)
{
    int monthsTo =(late.year()-early.year())*12+late.month()-early.month();
    qDebug() << monthsTo;

    if(seriesFuelPurchaseCosts->count()){
        clearCache();
    }

    if(fuelType=="DIESEL" || fuelType=="PB" || fuelType=="LPG"){
        for(int i=0;i<monthsTo;++i){
           *seriesFuelPurchaseCosts << handler->fuelsCosts(fuelType,early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),carID);
        }
    }
    else{
       qDebug() << "FuelType Error";
       qDebug() << "Avaible types: DIESEL PB LPG";
       return;
    }
}

void FuelPurchaseCosts::clearCache()
{
    seriesFuelPurchaseCosts->remove(0,seriesFuelPurchaseCosts->count());
}
