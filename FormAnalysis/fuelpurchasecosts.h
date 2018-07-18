#ifndef FUELPURCHASECOSTS_H
#define FUELPURCHASECOSTS_H

#include <QWidget>
#include <SQL/requesthandleanalysis.h>
#include <QComboBox>

#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChartView>

class FuelPurchaseCosts
{
public:
    FuelPurchaseCosts();
    ~FuelPurchaseCosts();

    void LoadSeries(QDate early, QDate late, char fuelType);

private:

    RequestHandleAnalysis *handler;
    QBarSet *seriesFuelPurchaseCosts;
};

#endif // FUELPURCHASECOSTS_H
