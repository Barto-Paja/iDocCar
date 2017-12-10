#include "r_costs.h"
#include "ui_r_costs.h"

#include <QDebug>

r_Costs::r_Costs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::r_Costs)
{
    ui->setupUi(this);

    connector = new SQL();

//    series = new QAreaSeries();
    series0 = new QLineSeries();
    series1 = new QLineSeries();
    series2 = new QLineSeries();
    series3 = new QLineSeries();


    axisX = new QCategoryAxis();
    axisY = new QCategoryAxis();

    mainChart = new QChart();
    mainChart->addSeries(series0);


    ui->gridLayoutWidget_2->setVisible(false);
//------------------------------------------

    series0->setName("Renault Laguna II");
    series1->setName("CAT 352F 2017");

               /*<< QPointF(1, 5) << QPointF(2, 1) << QPointF(4, 3) << QPointF(6, 5) << QPointF(8, 5);*/
//       *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
//                << QPointF(16, 4) << QPointF(18, 3);


       QAreaSeries *series = new QAreaSeries(series0);
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

       mainChart->setTitle("Simple chart - średnie spalanie w ciągu miesiąca zestawienie roczne");
       mainChart->createDefaultAxes();

       //mainChart->setAxisX(axisX,series0);

       mainChart->axisX()->setRange(0,12);
       mainChart->axisY()->setRange(0,12);
       mainChart->legend()->setVisible(true);


       chartView = new QChartView(mainChart, ui->widget);
       chartView->setRenderHint(QPainter::Antialiasing);
//       ui->widget->resize((this->width()-5),(this->height()-5));
       chartView->resize((ui->widget->width()-10),(ui->widget->height()-10));


}

r_Costs::~r_Costs()
{
    delete ui;
}

void r_Costs::loadComboBox(int tanktype, QComboBox *combo)
{
    combo->clear();
    QString stream;
    int i=0;

    if(tanktype==0)
    {
        combo->clear();
        connector->tankType(0); // dla diesla tu musi być 0
        //connector->CarName();
        while (connector->getCarName(stream,i)) {
          combo->addItem(stream,i);
    }
    }
    else if(tanktype==1)
    {
         combo->clear();
         connector->tankType(1); // dla Pb tu musi być 1
         //connector->CarName();
         while (connector->getCarName(stream,i)) {
         combo->addItem(stream,i);
    }
    }
    else if(tanktype==2)
    {
          combo->clear();
          connector->tankType(2); // dla Pb+LPG tu musi być 2
          //connector->CarName();
          while (connector->getCarName(stream,i)) {
          combo->addItem(stream,i);
    }
    }
    else
      qDebug() << "Błąd wyboru baku";


        ui->cb_carid->update();

}


void r_Costs::loadSeries(QLineSeries *seriesN, int carId)
{
    QString date;
    int fuelId;
    float fuelCon;
    int i=0, temp_day;

        SQL *lS = new SQL();
        lS->fuelInfo(carId);

    seriesN->clear();
    seriesN->append(0,6.0);
    while(lS->fuelInfoQuest(fuelId,date,fuelCon))
    {
        QDate temp_date;
        temp_date = QDate::fromString(date,"yyyy-MM-dd");
        temp_day = temp_date.day();
        float temp_day_v = temp_day*0.03;
        int month = -1;
        month = temp_date.month();
        qDebug() << QString::number(month) + " td: " + QString::number(temp_day_v);

        float a = (1+temp_day_v);

        switch(month)
        {
        case 1:
            seriesN->append((1+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 2:
            seriesN->append((2+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 3:
            seriesN->append((3+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 4:
            seriesN->append((4+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 5:
            seriesN->append((5+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 6:
            seriesN->append((6+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 7:
            seriesN->append((7+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 8:
            seriesN->append((8+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 9:
            seriesN->append((9+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 10:
            seriesN->append((10+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 11:
            seriesN->append((11+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        case 12:
            seriesN->append((12+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            break;
        default:
            break;
        }

    }

}

void r_Costs::setXAxis()
{
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
    //mainChart->axisX()->setRange(0, 12);
}

void r_Costs::setYAxis()
{
    axisY->setRange(yMin,yMax);
}

void r_Costs::setyMaxMin(float v)
{
    if(v<yMin)
    {
        yMin=v;
    }
    else if(v>yMax)
    {
        yMax=v;
    }
    //mainChart->axisY()->setRange(yMin,yMax);
}

void r_Costs::on_chb_on_clicked()
{
    ui->gridLayoutWidget_2->setVisible(false);
    ui->cb_carid_2->clear();
    ui->cb_carid_3->clear();
    ui->cb_carid_2->setVisible(false);
    ui->cb_carid_3->setVisible(false);
    ui->l_carname3->setVisible(false);
    ui->chb_lpg->setChecked(false);
    ui->chb_pb->setChecked(false);
    loadComboBox(0,ui->cb_carid);
}

void r_Costs::on_chb_pb_clicked()
{
    ui->gridLayoutWidget_2->setVisible(false);
    ui->cb_carid_2->clear();
    ui->cb_carid_3->clear();
    ui->cb_carid_2->setVisible(false);
    ui->cb_carid_3->setVisible(false);
    ui->l_carname3->setVisible(false);
    ui->chb_on->setChecked(false);
    ui->chb_lpg->setChecked(false);
    loadComboBox(1,ui->cb_carid);
}

void r_Costs::on_chb_lpg_clicked()
{
    ui->gridLayoutWidget_2->setVisible(false);
    ui->cb_carid_2->clear();
    ui->cb_carid_3->clear();
    ui->cb_carid_2->setVisible(false);
    ui->cb_carid_3->setVisible(false);
    ui->l_carname3->setVisible(false);
    ui->chb_on->setChecked(false);
    ui->chb_pb->setChecked(false);
    loadComboBox(2,ui->cb_carid);
}

void r_Costs::on_pushButton_clicked()
{

    if((ui->cb_carid_2->isVisible() == false))
    {
        ui->gridLayoutWidget_2->setVisible(true);
        ui->cb_carid_2->setVisible(true);
        if(ui->chb_on->isChecked())
        {
            loadComboBox(0,ui->cb_carid_2);
        }
        else if(ui->chb_pb->isChecked())
        {
            loadComboBox(1,ui->cb_carid_2);
        }
        else if(ui->chb_lpg->isChecked())
        {
            loadComboBox(2,ui->cb_carid_2);
        }
        else
            qDebug() << "Bład wyboru baku";


        mainChart->addSeries(series1);
    }
    else if(ui->cb_carid_2->isVisible())
    {
        ui->l_carname3->setVisible(true);
        ui->cb_carid_3->setVisible(true);
        if(ui->chb_on->isChecked())
        {
            loadComboBox(0,ui->cb_carid_3);
        }
        else if(ui->chb_pb->isChecked())
        {
            loadComboBox(1,ui->cb_carid_3);
        }
        else if(ui->chb_lpg->isChecked())
        {
            loadComboBox(2,ui->cb_carid_3);
        }
        else
            qDebug() << "Bład wyboru baku";

        mainChart->addSeries(series2);
    }
}

void r_Costs::on_cb_carid_currentIndexChanged(const QString &arg1)
{
    int i;
    i = ui->cb_carid->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);

    loadSeries(series0,i);
    series0->setName(ui->cb_carid->currentText());
    chartView->repaint();
    ui->widget->update();
}

void r_Costs::on_cb_carid_2_currentIndexChanged(const QString &arg1)
{
    int i;
    i = ui->cb_carid_2->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);


    loadSeries(series1,i);
    series1->setName(ui->cb_carid_2->currentText());
    chartView->repaint(); // <-- tutaj ma ładować 2 serie
    ui->widget->update();
}


void r_Costs::on_cb_carid_3_currentIndexChanged(const QString &arg1)
{
    int i;
    i = ui->cb_carid_3->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);

    loadSeries(series2,i);
    series2->setName(ui->cb_carid_3->currentText());
    chartView->repaint(); // <-- tutaj ma ładować 3 serie
    ui->widget->update();
}

void r_Costs::on_pushButton_2_clicked()
{
    ui->widget->grab().save("image.jpg");
}
