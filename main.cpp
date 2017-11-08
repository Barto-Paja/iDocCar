#include "mainwindow.h"
#include <QApplication>

#include "sql.h"

int main(int argc, char *argv[])
{
//    SQL p("localhost","idoccar","root","");
//    p.insert_car("Toyota", "Corolla", "WCI Kebs", "tojestvin", "2005-05-07", "2019-01-01",2 ,23451, 100, 52);
//    p.insert_user("test","pass","Łukasz","Witkowski","wito@gmail.com");
//    p.insert_cost("Elo","2012-12-20",2,"Testowa notka",25000,10.25,1);
//    p.insert_fuel("2015-01-01",29.59,59.62,25000,7.1,1,"Notka tankowania",1);
  
     // --- Dodanie obsługi formularzy --- //

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
  // --- Pierwszy główny -------------- //

}
