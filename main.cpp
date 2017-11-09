<<<<<<< HEAD
﻿#include "mainwindow.h"
=======

#include <QString>
>>>>>>> base
#include <QApplication>
#include "sql.h"
#include <QDebug>

#include "sql.h"

int main(int argc, char *argv[])
{
<<<<<<< HEAD
//    SQL p("localhost","idoccar","root","");
=======
    SQL p("localhost","idoccar","root","");
>>>>>>> base
//    p.insert_car("Toyota", "Corolla", "WCI Kebs", "tojestvin", "2005-05-07", "2019-01-01",2 ,23451, 100, 52);
//    p.insert_user("test","pass","Łukasz","Witkowski","wito@gmail.com");
//    p.insert_cost("Elo","2012-12-20",2,"Testowa notka",25000,10.25,1);
//    p.insert_fuel("2015-01-01",29.59,59.62,25000,7.1,1,"Notka tankowania",1);
<<<<<<< HEAD
  
     // --- Dodanie obsługi formularzy --- //

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
  // --- Pierwszy główny -------------- //
=======
//    QString test = p.select_user(3,1);
//    p.tables(3);
    QSqlQuery pobieranie;
    pobieranie = p.list_cars(1);
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

    pobieranie = p.list_cost_types();
    while(pobieranie.next())
    {
        int ID = pobieranie.value(0).toInt();
        QString name = pobieranie.value(1).toString();

        qDebug() << ID << name;
    }
    return 1;
>>>>>>> base

}
