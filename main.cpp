#include "mainwindow.h"
#include <QApplication>

#include "sql.h"

int main(int argc, char *argv[])
{
    SQL p;
    p.test();
    //return 1;
  
     // --- Dodanie obsługi formularzy --- //

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
  // --- Pierwszy główny -------------- //

}
