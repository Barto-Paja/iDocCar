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
    bool insert_user(QString LOGIN, QString PASS, QString FNAME, QString LNAME, QString EMAIL, int LVL, int ch_pass);
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


    //--- For Charts r_Costs and newTank--- //
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
    double carTankInfo(int carId, int tankId);


    //--- For Workshop --- //
    void CostNames();
    bool getCostName(QString &stream, int &idCost);
    QString CarName(int carid);
    QString getPlate(int carid);
    QString fuelWInfo(int carid);
    float fuelCountCost(int carid, int tType, QString date);
    float costCountCost(int carid, int costtype);

    //--- SQL errors --- // 
    void error();

    //--- For admin ---//
    bool getUsers(QString &stream, int &idUser);
    void Users();

    //--- For ed_user ---//
    bool getLvl(QString &stream, int &idLvl);
    bool editUser(int id_user, QString FNAME, QString LNAME, QString PASS, QString EMAIL, int LVL, int ch_pass);
    void Lvl();
    QString select_u_fname(int id);
    QString select_u_lname(int id);
    QString selec_u_mail(int id);
    QString select_u_pass(int id);
    int select_u_lvl(int id);
    bool del_user(int id);

    //--- For ed_pass ---//

    bool change_pass(QString pass);
    int select_pass_change();

private:

    QSqlQuery *query;
    static int userId;
};

#endif // SQL_H
