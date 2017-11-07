#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include "sql.h"

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

SQL::SQL()
{
    db.setHostName("localhost");
    db.setDatabaseName("idoccar");
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
        qDebug() << "Nieudane polaczenie z baza danych";
    else
        qDebug() << "Połączono z baza danych";
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

SQL::~SQL()
{
    db.close();
}
