#ifndef R_COSTS_H
#define R_COSTS_H

#include <QMainWindow>

#include <QTableView>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QCategoryAxis>

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

private:
    Ui::r_Costs *ui;

    void loadComboBox(int tanktype);
    void loadSeries(QLineSeries *seriesN, int carId);
    void setXAxis();
    void setYAxis();
    void setyMaxMin(float v);

    SQL *connector;

    //--- Axises ---

    float yMax = 0;
    float yMin = 0;

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
};

#endif // R_COSTS_H
