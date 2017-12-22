#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <QDate>
#include <QFile>
#include <QMessageBox>

class SQL
{
public:
    SQL();
    ~SQL();
    void test();
    bool insert_car(QString MARK,QString MODEL,QString PLATE,QString VIN,QString YEAR,QString INSURANCE,int TANKS,int MILAGE, float TANK1,float TANK2);
    bool insert_user(QString LOGIN, QString PASS, QString FNAME, QString LNAME, QString EMAIL, int LVL);
    void insert_cost(QString TITLE, QString DATE, int TYPE, QString NOTES, int MILAGE, float COST, int CARID);
    void insert_fuel(QString DATE, float FUEL, float PRICE, int MILAGE, float COMBUSTION, int TANK, QString NOTES, int CARID);
    QSqlQuery list_costs(int carID, QString date_start, QString date_end);
    int select_login(QString id);
    QSqlQuery list_cost_types();
    QSqlQuery list_cars(int id_user);
    void load_config(QString &lhost, QString &luser, QString &lpass, QString &ldb);

    bool isOpen();
    bool isUser(QString login, QString password);

    void CarName();
    bool getCarName(QString &stream, int &idcar);
    QString welcomeFunc();
    int lastMilage(int idcar);


    //--- For Charts r_Costs --- //
    void tankType(int tankid);
    void fuelInfo(int carId);
    void fuelInfo(int carId, int elderyear, int nowyear, int tt);
    int fuelInfoCount(int carId);
    bool fuelInfoQuest(int &fId, QString &fdate, float &fcon);
    int fuelInfoQuest();
    float fuelsCosts(int fuelType, int elderyear, int nowyear, int month);
    float fuelsCosts(int fuelType, int elderyear, int nowyear, int month, int carID);
    float fuelQuantity(int fuelType, int elderyear, int nowyear, int month);
    float fuelQuantity(int fuelType, int elderyear, int nowyear, int month, int carID);

    //--- For Workshop --- //
    void CostNames();
    bool getCostName(QString &stream, int &idCost);

    //--- SQL errors --- // 
    void error();


private:

    QSqlQuery *query;
    static int userId;
};

#endif // SQL_H
