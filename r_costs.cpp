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

       series0->append(0,1);
       series0->append(1,1);
       series0->append(2,3);
       series0->append(3,7);
       series0->append(5,4);
       series0->append(7,1);

               /*<< QPointF(1, 5) << QPointF(2, 1) << QPointF(4, 3) << QPointF(6, 5) << QPointF(8, 5);*/
//       *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
//                << QPointF(16, 4) << QPointF(18, 3);

       QAreaSeries *series = new QAreaSeries(series0/*, series1*/);
       series->setName("Batman");
       series->setBrush(Qt::NoBrush);
       QPen pen(0x059605);
       //0x059605
       pen.setWidth(3);
       qDebug() << pen.isSolid();
       series->setPen(pen);

//       QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
//       gradient.setColorAt(0.0, 0x3cc63c);
//       gradient.setColorAt(1.0, 0x26f626);
//       gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//       series->setBrush(gradient);

       QChart *chart = new QChart();
       chart->addSeries(series0);
       chart->setTitle("Simple areachart example");
       chart->createDefaultAxes();
       chart->axisX()->setRange(0, 20);
       chart->axisY()->setRange(0, 10);

       QChartView *chartView = new QChartView(chart, ui->widget);
       chartView->setRenderHint(QPainter::Antialiasing);
       ui->widget->resize((this->width()-5),(this->height()-5));
       chartView->resize((this->width()-10),(this->height()-10));




//       ui->widget->s
}

r_Costs::~r_Costs()
{
    delete ui;
}
