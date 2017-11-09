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


namespace Ui {
class r_Costs;
}

class r_Costs : public QMainWindow
{
    Q_OBJECT

public:
    explicit r_Costs(QWidget *parent = 0);
    ~r_Costs();

private:
    QCategoryAxis *axisX;
    QCategoryAxis *axisY;
    QCategoryAxis *axisZ;

    QChart *mainChart;
    QChartView *chartView;

private slots:


private:
    Ui::r_Costs *ui;
};

#endif // R_COSTS_H
