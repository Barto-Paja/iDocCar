#ifndef SQL_H
#define SQL_H
#include <QSqlQuery>
#include <QString>

class SQL
{
public:
    SQL(QString dbHost, QString dbName, QString dbUser, QString dbPass);
    ~SQL();
    void test();
    void insert_car(QString MARK,QString MODEL,QString PLATE,QString VIN,QString YEAR,QString INSURANCE,int TANKS,int MILAGE, float TANK1,float TANK2);
    void insert_user(QString LOGIN,QString PASS, QString FNAME, QString LNAME, QString EMAIL);
    void insert_cost(QString TITLE, QString DATE, int TYPE, QString NOTES, int MILAGE, float COST, int CARID);
    void insert_fuel(QString DATE, float FUEL, float PRICE, int MILAGE, float COMBUSTION, int TANK, QString NOTES, int CARID);
    QString select_user(int col, int id);
//    void tables(int col);
    QSqlQuery rekord();
};

#endif // SQL_H
