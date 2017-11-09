
#include <QString>
#include <QApplication>
#include "sql.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    SQL p("localhost","idoccar","root","");
//    p.insert_car("Toyota", "Corolla", "WCI Kebs", "tojestvin", "2005-05-07", "2019-01-01",2 ,23451, 100, 52);
//    p.insert_user("test","pass","Łukasz","Witkowski","wito@gmail.com");
//    p.insert_cost("Elo","2012-12-20",2,"Testowa notka",25000,10.25,1);
//    p.insert_fuel("2015-01-01",29.59,59.62,25000,7.1,1,"Notka tankowania",1);
//    QString test = p.select_user(3,1);
//    p.tables(3);

    QSqlQuery pobieranie = p.rekord();
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
    return 1;

}
