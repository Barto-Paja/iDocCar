#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>

class SQL
{
public:
    SQL(QString dbHost, QString dbName, QString dbUser, QString dbPass);
    ~SQL();
    void test();
    bool insert_car(QString MARK,QString MODEL,QString PLATE,QString VIN,QString YEAR,QString INSURANCE,int TANKS,int MILAGE, float TANK1,float TANK2);
    void insert_user(QString LOGIN,QString PASS, QString FNAME, QString LNAME, QString EMAIL);
    void insert_cost(QString TITLE, QString DATE, int TYPE, QString NOTES, int MILAGE, float COST, int CARID);
    void insert_fuel(QString DATE, float FUEL, float PRICE, int MILAGE, float COMBUSTION, int TANK, QString NOTES, int CARID);
    QString select_user(int col, int id);
    QSqlQuery list_cost_types();
    QSqlQuery list_cars(int id_user);

    bool isOpen();
    bool isUser(QString login, QString password);

    QString welcomeFunc();

private:

    QSqlQuery *query;
    QSqlQuery list_costs(int carID, QString date_start, QString date_end);

    static int userId;
};

#endif // SQL_H
