#ifndef R_COSTS_H
#define R_COSTS_H

#include <QMainWindow>

#include <QTableView>
#include <QComboBox>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

#include <sql.h>

namespace Ui {
class r_Costs;
}

class r_Costs : public QMainWindow
{
    Q_OBJECT

public:
    explicit r_Costs(QWidget *parent = 0);
    ~r_Costs();

private slots:

    void on_chb_on_clicked();

    void on_cb_carid_currentIndexChanged(const QString &arg1);

    void on_chb_pb_clicked();

    void on_chb_lpg_clicked();

    void on_pushButton_clicked();

    void on_cb_carid_2_currentIndexChanged(const QString &arg1);

    void on_cb_carid_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_b_search_clicked();

    void on_b_quantity_clicked();

private:
    Ui::r_Costs *ui;

    void chart0init();
    void chart1init();

    void loadComboBox(int tanktype, QComboBox *combo);
    void loadSeries(QLineSeries *seriesN, int carId, int typeSeries);
    void setXAxis();
    void setYAxis();
    void setyMinMax(float v);
    void setyMinMax(float yMin1, float yMax1, float yMin2, float yMax2);
    void setyMinMax(float yMin1, float yMax1, float yMin2, float yMax2, float yMin3, float yMax3);
    void setyMaxMin(float v, float &tempyMin, float &tempyMax);

    void loadBars(QBarSet *barsetN, int elderyear, int nowyear, int fuelType, int typeChart);
    void loadBars(QBarSet *barsetN, int elderyear, int nowyear, int fuelType, int typeChart, int carID);

    SQL *connector;

    //--- Axises ---

    float yMax = 0;
    float yMin = 0;

    float temp_yMin1 = 0, temp_yMin2 = 0, temp_yMin3 = 0;
    float temp_yMax1 = 0, temp_yMax2 = 0, temp_yMax3 = 0;

    int t_Cost =-1;

    QCategoryAxis *axisX;
    QCategoryAxis *axisY;
    QCategoryAxis *axisZ;

    QChart *mainChart;
    QChartView *chartView;
    QChartView *chartViewbeta;
//    QAreaSeries *series;

    QLineSeries *series0;
    QLineSeries *series1;
    QLineSeries *series2;
    QLineSeries *series3;

    QChart *barChart;
    QChartView *barChartView;

    QBarSet *barset0;
    QBarSet *barset1;
    QBarSet *barset2;

    QBarSeries *seriesX;
    QBarCategoryAxis *axis;
};

#endif // R_COSTS_H
