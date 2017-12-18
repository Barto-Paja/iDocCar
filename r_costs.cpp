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

    barset0 = new QBarSet("ON");
    barset1 = new QBarSet("Pb");
    barset2 = new QBarSet("LPG");

    axisX = new QCategoryAxis();
    axisY = new QCategoryAxis();

    mainChart = new QChart();
    chart0init();

    barChart = new QChart();
    chart1init();

    ui->gridLayoutWidget_2->setVisible(false);
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
        while (connector->getCarName(stream,i)) {
          combo->addItem(stream,i);
    }
    }
    else if(tanktype==1)
    {
         combo->clear();
         connector->tankType(1); // dla Pb tu musi być 1
         while (connector->getCarName(stream,i)) {
         combo->addItem(stream,i);}
         connector->tankType(2);
         while(connector->getCarName(stream,i)){ // dołożenie aut Pb+LPG
         combo->addItem(stream,i);}
    }
    else if(tanktype==2)
    {
          combo->clear();
          connector->tankType(2); // dla Pb+LPG tu musi być 2
          while (connector->getCarName(stream,i)) {
          combo->addItem(stream,i);
    }
    }
    else
      qDebug() << "Błąd wyboru baku";


        ui->cb_carid->update();

}


void r_Costs::loadSeries(QLineSeries *seriesN, int carId, int typeSeries)
{
    QString date;
    int fuelId;
    float fuelCon;
    int i=0, temp_day;

    SQL *lS = new SQL();
    lS->fuelInfo(carId);

    seriesN->clear();

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
            seriesN->append((0+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 2:
            seriesN->append((1+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 3:
            seriesN->append((2+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 4:
            seriesN->append((3+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 5:
            seriesN->append((4+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 6:
            seriesN->append((5+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 7:
            seriesN->append((6+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 8:
            seriesN->append((7+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 9:
            seriesN->append((8+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 10:
            seriesN->append((9+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 11:
            seriesN->append((10+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
            break;
        case 12:
            seriesN->append((11+temp_day_v),fuelCon);
            setyMaxMin(fuelCon);
            qDebug() << QString::number(yMin) + " " + QString::number(yMax);
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
    mainChart->setAxisX(axisX,series0);
    //mainChart->axisX()->setLabelsAngle(90);
    mainChart->axisX()->setRange(0,12);
}

void r_Costs::setYAxis()
{
    axisY->setRange(yMin,yMax);
}

void r_Costs::setyMinMax(float v)
{
    if(v<=yMin)
    {
        yMin=v;
    }
    else if(v>=yMax)
    {
        yMax=v;
    }
}

void r_Costs::setyMinMax(float yMin1, float yMax1, float yMin2, float yMax2)
{
    if(yMin<yMin1 && yMin<yMin2)
    {
        if(yMin1<yMin2)
        {
            yMin=yMin1;
        }
        else
        {
            yMin=yMin2;
        }
    }
    else
    {
        if(yMin1<yMin2)
        {
            yMin=yMin1;
        }
        else
        {
            yMin=yMin2;
        }
    }

    if(yMax>yMax1 && yMax>yMax2)
    {
        if(yMax1>yMax2)
        {
            yMax=yMax1;
        }
        else
        {
            yMax=yMax2;
        }
    }
    else
    {
        if(yMax1>yMax2)
        {
            yMax=yMax1;
        }
        else
        {
            yMax=yMax2;
        }
    }
}

void r_Costs::setyMinMax(float yMin1, float yMax1, float yMin2, float yMax2, float yMin3, float yMax3)
{
    if(yMin<yMin1 && yMin<yMin2 && yMin<yMin3)
    {
        int temp=0;
        if(yMin1<yMin2)
        {
            temp=yMin1;
        }
        else
        {
            temp=yMin2;
        }

        if(temp<yMin3)
        {
            yMin=temp;
        }
        else
        {
            yMin=yMin3;
        }
    }

    if(yMax>yMax1 && yMax>yMax2 && yMax>yMax3)
    {
        int temp=0;
        if(yMax1>yMax2)
        {
            temp = yMax1;
        }
        else
        {
            temp = yMax2;
        }

        if(temp>yMax3)
        {
            yMax=temp;
        }
        else
        {
            yMax= yMax3;
        }
    }
}

void r_Costs::setyMaxMin(float v, float &tempyMin, float &tempyMax)
{
    if(v<=tempyMin)
    {
        tempyMin=v;
    }
    else if(v>=tempyMax)
    {
        tempyMax=v;
    }
}

void r_Costs::loadBars(QBarSet *barsetN, int elderyear, int nowyear, int fuelType, int typeChart)
{
    SQL *bS = new SQL;
    if(typeChart==1)
    {
        int i=1;
        while (i<13) {
            *barsetN << (bS->fuelsCosts(fuelType,elderyear,nowyear,i));
            setyMaxMin(bS->fuelsCosts(fuelType,elderyear,nowyear,i));
            ++i;
        }
    }
    else
    {
        int i=1;
        while(i<13)
        {
            *barsetN <<(bS->fuelQuantity(fuelType,elderyear,nowyear,i));
            setyMaxMin(bS->fuelQuantity(fuelType,elderyear,nowyear,i));
            ++i;
        }
    }


}

void r_Costs::loadBars(QBarSet *barsetN, int elderyear, int nowyear, int fuelType, int typeChart, int carID)
{
    SQL *bS = new SQL;
    //qDebug() << "Suma: " + QString::number(bS->fuelsCosts(1,2017,4));
    if(typeChart==1)
    {
        int i=1;
        while (i<13) {
            *barsetN << (bS->fuelsCosts(fuelType,elderyear,nowyear,i,carID));
            setyMaxMin(bS->fuelsCosts(fuelType,elderyear,nowyear,i,carID));
            ++i;
        }
    }
    else
    {
        int i=1;
        while(i<13)
        {
            *barsetN <<(bS->fuelQuantity(fuelType,elderyear,nowyear,i,carID));
            setyMaxMin(bS->fuelQuantity(fuelType,elderyear,nowyear,i,carID));
            ++i;
        }
    }
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
    QDate today;
    int td = today.currentDate().year();


    SQL *tempCon = new SQL;

    int i;
    i = ui->cb_carid->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);

    yMax=1;yMin=0;

    loadSeries(series0,i);
    series0->setName(ui->cb_carid->currentText());
    mainChart->axisY()->setRange(yMin,yMax);
    chartView->repaint();
    ui->widget->update();

    tempCon->fuelInfo(i);

    barset0->remove(1,12);

    yMax=1;yMin=0;
    loadBars(barset0,td,td,tempCon->fuelInfoQuest(),i);
    barset0->setLabel(ui->cb_carid->currentText());
    barChart->axisY()->setRange(yMin,yMax);
    barChart->setTitle("Zakup paliw w Litrach");
    barChartView->repaint();
    ui->widget_2->update();
}

void r_Costs::on_cb_carid_2_currentIndexChanged(const QString &arg1)
{
    QDate today;
    int td = today.currentDate().year();

    SQL *tempCon = new SQL;

    int i;
    i = ui->cb_carid_2->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);

//    yMax=1;yMin=0;

    loadSeries(series1,i);
    series1->setName(ui->cb_carid_2->currentText());
    chartView->repaint(); // <-- tutaj ma ładować 2 serie
    ui->widget->update();

    tempCon->fuelInfo(i);

    barset1->remove(1,12);

//    yMax=1;yMin=1;
    loadBars(barset1,td,td,tempCon->fuelInfoQuest(),i);
    barset1->setLabel(ui->cb_carid->currentText());
    barChart->axisY()->setRange(yMin,yMax);
    //barChart->setTitle("Zakup paliw w Litrach");
    barChartView->repaint();
    ui->widget_2->update();
}


void r_Costs::on_cb_carid_3_currentIndexChanged(const QString &arg1)
{
    QDate today;
    int td = today.currentDate().year();

    SQL *tempCon = new SQL;

//    yMax=1;yMin=0;

    int i;
    i = ui->cb_carid_3->currentData().toInt();
    qDebug() << "reaguje: " + QString::number(i);

    loadSeries(series2,i);
    series2->setName(ui->cb_carid_3->currentText());
    chartView->repaint(); // <-- tutaj ma ładować 3 serie
    ui->widget->update();

    tempCon->fuelInfo(i);

//    yMax=1;yMin=1;

    barset2->remove(1,12);

    loadBars(barset2,td,td,tempCon->fuelInfoQuest(),i);
    barset2->setLabel(ui->cb_carid->currentText());
    barChart->axisY()->setRange(yMin,yMax);
    //barChart->setTitle("Zakup paliw w Litrach");
    barChartView->repaint();
    ui->widget_2->update();
}

void r_Costs::on_pushButton_2_clicked()
{
    ui->widget->grab().save("image.jpg");
}

void r_Costs::chart0init()
{
    mainChart->addSeries(series0);
    mainChart->createDefaultAxes();
    mainChart->legend()->setVisible(true);
    mainChart->setTitle("Średnia spalania w ciągu roku");
    setXAxis();
    chartView = new QChartView(mainChart, ui->widget);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->chart()->setTheme(QChart::ChartThemeBlueNcs);
    chartView->resize((ui->widget->width()-10),(ui->widget->height()-10));
}

void r_Costs::chart1init()
{

//    loadBars(barset0,today.currentDate().year(),today.currentDate().year(),1,1);
//    loadBars(barset1,today.currentDate().year(),today.currentDate().year(),2,1);
//    loadBars(barset2,today.currentDate().year(),today.currentDate().year(),0,1);

    seriesX = new QBarSeries();
    seriesX->append(barset0);
    seriesX->append(barset1);
    seriesX->append(barset2);

    barChart->setTitle("Zakup paliw w PLN");
    barChart->addSeries(seriesX);

    barChartView = new QChartView(barChart,ui->widget_2);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->resize((ui->widget_2->width()-10),(ui->widget_2->height()-10));

    QStringList categories;
    categories << "Styczeń" << "Luty" << "Marzec" << "Kwiecień" << "Maj" << "Czerwiec" << "Lipiec" << "Sierpień"
               << "Wrzesień" << "Październik" << "Listopad" << "Grudzień";

    axis = new QBarCategoryAxis();
    axis->append(categories);
    barChart->createDefaultAxes();
    barChart->setAxisX(axis, seriesX);

    barChartView->repaint();
    ui->widget_2->repaint();
    ui->widget_2->update();
}


void r_Costs::on_b_search_clicked()
{
    barset0->remove(1,12);
    barset1->remove(1,12);
    barset2->remove(1,12);

    int elder = ui->dateEdit->date().year();
    int younger = ui->dateEdit_2->date().year();
    if(younger-elder<0)
    {
        QMessageBox::information(0,"Błąd","Data 'Od' jest młodsza od daty 'Do'");
    }
    else
    {
        loadBars(barset0,elder,younger,1,1);
        loadBars(barset1,elder,younger,2,1);
        loadBars(barset2,elder,younger,0,1);

        barChart->setTitle("Zakup paliw w PLN");
        barChartView->repaint();
        ui->widget_2->repaint();
        ui->widget_2->update();
    }


}

void r_Costs::on_b_quantity_clicked()
{
    barset0->remove(0,12);
    barset1->remove(0,12);
    barset2->remove(0,12);

    barChart->axisY()->setRange(-1,1);
    yMax = 1;
    yMin = 0;

    int elder = ui->dateEdit->date().year();
    int younger = ui->dateEdit_2->date().year();
    if(younger-elder<0)
    {
        QMessageBox::information(0,"Błąd","Data 'Od' jest młodsza od daty 'Do'");
    }
    else
    {
        loadBars(barset0,elder,younger,1,2);
        loadBars(barset1,elder,younger,2,2);
        loadBars(barset2,elder,younger,0,2);

        barChart->axisY()->setRange(yMin,yMax);

        barChart->setTitle("Zakup paliw w Litrach");
        barChartView->repaint();
        ui->widget_2->repaint();
        ui->widget_2->update();
    }
}
