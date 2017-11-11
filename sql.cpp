#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include "sql.h"

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

int USR=1;

SQL::SQL(QString dbHost, QString dbName, QString dbUser, QString dbPass)
{
    db.setHostName(dbHost);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPass);

    if(!db.open())
        qDebug() << "Nieudane połączenie z bazą danych";
}

SQL::~SQL()
{
    db.close();
}

void SQL::test()
{
        QStringList tables = db.tables();
        for(int i=0;i<tables.size();i++)
            qDebug() << tables.at(i);

        QSqlQuery pobieranie;
        if(!pobieranie.exec("SELECT * FROM users"))
            qDebug() << "Brak rekordów w tabeli Users";

        while(pobieranie.next())
        {
            QString a = pobieranie.value(0).toString();
            QString b = pobieranie.value(1).toString();
            QString c = pobieranie.value(2).toString();
            QString d = pobieranie.value(3).toString();
            QString e = pobieranie.value(4).toString();
            QString f = pobieranie.value(5).toString();

            qDebug() << a << b << c << d << e << f;
        }
}

void SQL::insert_car(QString MARK,QString MODEL,QString PLATE,QString VIN,QString YEAR,QString INSURANCE,int TANKS,int MILAGE, float TANK1,float TANK2)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO cars (`MARK`, `MODEL`, `PLATE`, `VIN`, `YEAR`, `INSURANCE`, `TANKS`, `TANK1`, `TANK2`, `MILAGE`, `USER`) "
                    "VALUES (:MARK,:MODEL,:PLATE,:VIN,:YEAR,:INSURANCE,:TANKS,:TANK1,:TANK2,:MILAGE,:USER)");
    insert.bindValue(0,MARK);
    insert.bindValue(1,MODEL);
    insert.bindValue(2,PLATE);
    insert.bindValue(3,VIN);
    insert.bindValue(4,YEAR);
    insert.bindValue(5,INSURANCE);
    insert.bindValue(6,TANKS);
    insert.bindValue(7,TANK1);
    insert.bindValue(8,TANK2);
    insert.bindValue(9,MILAGE);
    insert.bindValue(10,USR);

    if(!insert.exec())
         qDebug() << "Błąd dodania pojazdu";
}

void SQL::insert_user(QString LOGIN,QString PASS, QString FNAME, QString LNAME, QString EMAIL)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO users (`FIRST_NAME`, `LAST_NAME`, `LOGIN`, `PASS`, `EMAIL`) "
                    "VALUES (:FNAME,:LNAME,:LOGIN,:PASS,:EMAIL)");
    insert.bindValue(0,FNAME);
    insert.bindValue(1,LNAME);
    insert.bindValue(2,LOGIN);
    insert.bindValue(3,PASS);
    insert.bindValue(4,EMAIL);

    if(!insert.exec())
         qDebug() << "Błąd dodania użytkownika";
}

void SQL::insert_cost(QString TITLE, QString DATE, int TYPE, QString NOTES, int MILAGE, float COST, int CARID)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO costs (`TITLE`, `DATE`, `TYPE`, `NOTES`, `MILAGE`, `COST`, `CARID`) "
                    "VALUES (:TITLE,:DATE,:TYPE,:NOTES,:MILAGE,:COST,:CARID)");
    insert.bindValue(0,TITLE);
    insert.bindValue(1,DATE);
    insert.bindValue(2,TYPE);
    insert.bindValue(3,NOTES);
    insert.bindValue(4,MILAGE);
    insert.bindValue(5,COST);
    insert.bindValue(6,CARID);


    if(!insert.exec())
         qDebug() << "Błąd dodania kosztu";
}

void SQL::insert_fuel(QString DATE, float FUEL, float PRICE, int MILAGE, float COMBUSTION, int TANK, QString NOTES, int CARID)
{
    QSqlQuery insert;
    insert.prepare("INSERT INTO fuel (`DATE`, `FUEL`, `PRICE`, `MILAGE`, `COMBUSTION`, `TANK`, `NOTES`, `CARID`) "
                   "VALUES (:DATE,:FUEL,:PRICE,:MILAGE,:COMBUSTION,:TANK,:NOTES,:CARID)");
    insert.bindValue(0,DATE);
    insert.bindValue(1,FUEL);
    insert.bindValue(2,PRICE);
    insert.bindValue(3,MILAGE);
    insert.bindValue(4,COMBUSTION);
    insert.bindValue(5,TANK);
    insert.bindValue(6,NOTES);
    insert.bindValue(7,CARID);

    if(!insert.exec())
         qDebug() << "Błąd dodania tankowania";
}
//wyciąganie danych usera po kolumnie
QString SQL::select_user(int col, int id)
{
    QSqlQuery pobieranie;
    pobieranie.prepare("SELECT * from users where ID = 1");
    pobieranie.bindValue(0,id);
    pobieranie.exec();

    if(pobieranie.first())
    {
        QString result = pobieranie.value(col).toString();
        return result;
    }else
        return "Błąd";

}
//wyciaganie typów kosztów
QSqlQuery SQL::list_cost_types()
{
    QSqlQuery select;
    select.exec("SELECT * FROM costtypes");
    return select;
}
//wyciąganie samochodów
QSqlQuery SQL::list_cars(int id_user)
{
    QSqlQuery select;
    select.prepare("SELECT * FROM cars WHERE USER = :id");
    select.bindValue(0,id_user);
    select.exec();
    return select;
}
// wyciąganie kosztów
QSqlQuery SQL::list_costs(int carID, QString date_start, QString date_end)
{
    QSqlQuery select;
    select.prepare("SELECT * FROM costs WHERE DATE BETWEEN :date_s AND :date_e AND CARID = :id");
    select.bindValue(0,date_start);
    select.bindValue(1,date_end);
    select.bindValue(2,carID);
    select.exec();
    return select;
}
