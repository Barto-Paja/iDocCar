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

    void on_b_fuel_clicked();

    void on_b_workshop_clicked();

    void on_b_fuels_clicked();

private:
    Ui::r_Costs *ui;

    void loadComboBox(int tanktype, QComboBox *combo);
    void loadSeries(QLineSeries *seriesN, int carId);
    void setXAxis();
    void setYAxis();
    void setyMaxMin(float v);

    void loadBars(QBarSet *barsetN);

    SQL *connector;

    //--- Axises ---

    float yMax = 0;
    float yMin = 0;

    int t_Cost =-1;

    QCategoryAxis *axisX;
    QCategoryAxis *axisY;
    QCategoryAxis *axisZ;

    QChart *mainChart;
    QChartView *chartView;
//    QAreaSeries *series;

    QLineSeries *series0;
    QLineSeries *series1;
    QLineSeries *series2;
    QLineSeries *series3;

    QBarSet *barset0;
    QBarSet *barset1;
    QBarSet *barset2;
};

#endif // R_COSTS_H
