#include "r_costs.h"
#include "ui_r_costs.h"

#include <QDebug>

r_Costs::r_Costs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::r_Costs)
{
    ui->setupUi(this);

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

       series0->append(0,5.7);
       series0->append(1,5.2);
       series0->append(2,5.0);
       series0->append(3,4.5);
       series0->append(4,4.7);
       series0->append(6,4.3);
       series0->append(7,5.0);
       series0->append(8,4.6);
       series0->append(9,4.9);
       series0->append(10,5.1);
       series0->append(11,5.2);
       series0->append(12,6.3);

    axisX = new QCategoryAxis();

    axisX->append("Styczeń", 1);
    axisX->append("Luty", 2);
    axisX->append("Marzec", 3);
    axisX->append("Kwiecień",4);
    axisX->append("Maj",5);
    axisX->append("Czerwiec",6);
    axisX->append("Lipiec",7);
    axisX->append("Sierpień",8);
    axisX->append("Wrzesień",9);
    axisX->append("Październik",10);
    axisX->append("Listopad",11);
    axisX->append("Grudzień",12);
    axisX->setRange(0, 12);

               /*<< QPointF(1, 5) << QPointF(2, 1) << QPointF(4, 3) << QPointF(6, 5) << QPointF(8, 5);*/
//       *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
//                << QPointF(16, 4) << QPointF(18, 3);


       QAreaSeries *series = new QAreaSeries(series0/*, series1*/);
       series->setName("Batman");
       series->setBrush(Qt::NoBrush);
       QPen pen(0x059605);
       pen.setWidth(3);
       qDebug() << pen.isSolid();
       series->setPen(pen);

//       QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
//       gradient.setColorAt(0.0, 0x3cc63c);
//       gradient.setColorAt(1.0, 0x26f626);
//       gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//       series->setBrush(gradient);

       mainChart = new QChart();
       mainChart->addSeries(series0);
       mainChart->setTitle("Simple chart - średnie spalanie w ciągu miesiąca");
       mainChart->createDefaultAxes();
       mainChart->setAxisX(axisX,series0);
       mainChart->axisX()->setRange(0, 12);
       mainChart->axisY()->setRange(0, 7);

       chartView = new QChartView(mainChart, ui->widget);
       chartView->setRenderHint(QPainter::Antialiasing);
//       ui->widget->resize((this->width()-5),(this->height()-5));
       chartView->resize((ui->widget->width()-10),(ui->widget->height()-10));

}

r_Costs::~r_Costs()
{
    delete ui;
}
