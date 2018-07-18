#ifndef FORMANALYSIS_H
#define FORMANALYSIS_H

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

namespace Ui {
class FormAnalysis;
}

class FormAnalysis : public QWidget
{
    Q_OBJECT

public:
    explicit FormAnalysis(QWidget *parent = 0);
    ~FormAnalysis();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_ShowResults_clicked();

private:
    RequestHandleAnalysis *handler;
    Ui::FormAnalysis *ui;

    /* Series Chart */
    QChart *seriesChart;
    QChartView *chartView;
    QBarSet *seriesFuelPurchaseCosts;
    
    QVector<QLineSeries> *series;
    QStringList categories;

    QCategoryAxis *axisX;
    QBarCategoryAxis *barCategory;
    QBarSeries *barSeries;

    void LoadComboBox(QString tankType, QComboBox *comboBox);
    void LoadSeries(QBarSet *series);
    void setUpAxisX();
};

#endif // FORMANALYSIS_H
