#include "formanalysis.h"
#include "ui_formanalysis.h"

FormAnalysis::FormAnalysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAnalysis)
{
    ui->setupUi(this);
    handler = new RequestHandleAnalysis;
    seriesFuelCosts = new FuelPurchaseCosts;

    seriesChart = new QChart();
    chartView = new QChartView(seriesChart);

    series = new QVector<QLineSeries>();
    seriesFuelPurchaseCosts = new QBarSet("Koszt zakupu paliw");
    barSeries = new QBarSeries();

    axisX = new QCategoryAxis();
    barCategory = new QBarCategoryAxis();

    ui->tab->setChart(seriesChart);
    ui->tab->setRenderHint(QPainter::Antialiasing);
    ui->tab->update();
}

FormAnalysis::~FormAnalysis()
{
    delete ui;
    delete handler;
    delete seriesChart;
    delete chartView;
    delete seriesFuelPurchaseCosts;
    delete seriesFuelCosts;
}

void FormAnalysis::LoadComboBox(QString tankType, QComboBox *comboBox)
{
    QMap<QString, int> carnames;
    carnames.clear();
    comboBox->clear();
    handler->loadCarNamesList(tankType,carnames);
    QMapIterator<QString, int> i(carnames);
    while(i.hasNext())
    {   i.next();
        comboBox->addItem(i.key(),i.value());
    }
    comboBox->update();
}

void FormAnalysis::LoadSeries(QBarSet *series)
{
    QDate early=ui->dateEdit_early->date();
    QDate late=ui->dateEdit_late->date();

    int monthsTo =(late.year()-early.year())*12+late.month()-early.month();
    qDebug() << monthsTo;

    if(ui->radioButton->isChecked()){

        for(int i=0;i<monthsTo;++i){
           *series << handler->fuelsCosts(QString("DIESEL"),early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
        }
    }
    else if(ui->radioButton_2->isChecked()){
        for(int i=0;i<monthsTo;++i){
           *series << handler->fuelsCosts(QString("PB"),early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
        }
    }
    else if(ui->radioButton_3->isChecked()){
        for(int i=0;i<monthsTo;++i){
           *series << handler->fuelsCosts(QString("LPG"),early.addMonths(i).toString("yy/MM/dd"),
           early.addMonths(i+1).toString("yy/MM/dd"),ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
        }
    }
    else
        return;
}

void FormAnalysis::setUpAxisX()
{
    QStringList categories;
    categories << "Styczeń" << "Luty" << "Marzec" << "Kwiecień" << "Maj" << "Czerwiec" << "Lipiec" << "Sierpień"
               << "Wrzesień" << "Październik" << "Listopad" << "Grudzień";

    barCategory->append(categories);
}

void FormAnalysis::on_radioButton_clicked()
{
    LoadComboBox(QString("DIESEL"),ui->comboBox);
    LoadComboBox(QString("DIESEL"),ui->comboBox_2);
    LoadComboBox(QString("DIESEL"),ui->comboBox_3);
}

void FormAnalysis::on_radioButton_2_clicked()
{
    LoadComboBox(QString("PB"),ui->comboBox);
    LoadComboBox(QString("PB"),ui->comboBox_2);
    LoadComboBox(QString("PB"),ui->comboBox_3);
}

void FormAnalysis::on_radioButton_3_clicked()
{
    LoadComboBox(QString("LPG"),ui->comboBox);
    LoadComboBox(QString("LPG"),ui->comboBox_2);
    LoadComboBox(QString("LPG"),ui->comboBox_3);
}

void FormAnalysis::on_pushButton_ShowResults_clicked()
{
    //LoadSeries(seriesFuelPurchaseCosts);
    seriesFuelPurchaseCosts->remove(0,seriesFuelPurchaseCosts->count());
    seriesFuelCosts->LoadSeries(ui->dateEdit_early->date(),ui->dateEdit_late->date(),"DIESEL",ui->comboBox->currentData().toInt());
    setUpAxisX();
    barSeries->append(seriesFuelCosts->showSet());
    seriesChart->addSeries(barSeries);
    seriesChart->setAxisX(barCategory,barSeries);
    chartView->repaint();
    seriesChart->update();
    ui->tab->repaint();
    ui->tab->update();
    ui->tabWidget->update();
}
