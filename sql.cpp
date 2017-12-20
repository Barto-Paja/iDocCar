#include "sql.h"




QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

int SQL::userId = -1;

int USR=1;

SQL::SQL()
{
    QString dbHost, dbName, dbUser,dbPass;
    load_config(dbHost,dbUser,dbPass,dbName);
    db.setHostName(dbHost);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPass);

    if(!db.open())
        qDebug() << "Nieudane połączenie z bazą danych";

    query = new QSqlQuery;
}

SQL::~SQL()
{
    db.close();
}

bool SQL::insert_car(QString MARK,QString MODEL,QString PLATE,QString VIN,QString YEAR,QString INSURANCE,int TANKS,int MILAGE, float TANK1,float TANK2)
{
    QDate date(QDate::currentDate());
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
    insert.bindValue(10,userId);
    insert.exec();

    insert.prepare("SELECT id from cars order by id DESC");
    insert.exec();
    insert.first();

    int idcar = insert.value(0).toInt();

    QString stream = date.toString("yyyy-MM-dd");

    if(TANKS==0)
    {
        insert.prepare("INSERT INTO fuel (`DATE`, `FUEL`, `PRICE`, `MILAGE`, `COMBUSTION`, `TANK`, `NOTES`, `CARID`) "
                       "VALUES (:DATE,'0','0',:MILAGE,'0.00','0','First System Tank for ON',:CARID)");
        insert.bindValue(0,stream);
        insert.bindValue(1,MILAGE);
        insert.bindValue(2,idcar);
        insert.exec();
    }
    else if(TANKS==1)
    {
        insert.prepare("INSERT INTO fuel (`DATE`, `FUEL`, `PRICE`, `MILAGE`, `COMBUSTION`, `TANK`, `NOTES`, `CARID`) "
                       "VALUES (:DATE,'0','0',:MILAGE,'0.00','1','First System Tank for Pb',:CARID)");
        insert.bindValue(0,stream);
        insert.bindValue(1,MILAGE);
        insert.bindValue(2,idcar);
        insert.exec();
    }
    else if(TANKS==2)
    {
        insert.prepare("INSERT INTO fuel (`DATE`, `FUEL`, `PRICE`, `MILAGE`, `COMBUSTION`, `TANK`, `NOTES`, `CARID`) "
                       "VALUES (:DATE,'0','0',:MILAGE,'0.00','1','First System Tank for Pb',:CARID)");
        insert.bindValue(0,stream);
        insert.bindValue(1,MILAGE);
        insert.bindValue(2,idcar);
        insert.exec();

        insert.prepare("INSERT INTO fuel (`DATE`, `FUEL`, `PRICE`, `MILAGE`, `COMBUSTION`, `TANK`, `NOTES`, `CARID`) "
                       "VALUES (:DATE,'0','0',:MILAGE,'0.00','2','First System Tank for LPG',:CARID)");
        insert.bindValue(0,stream);
        insert.bindValue(1,MILAGE);
        insert.bindValue(2,idcar);
        insert.exec();
    }

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
         qDebug() << "Błąd dodania tankowania" << insert.lastError();
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


bool SQL::isOpen()
{
    if(db.isOpen())
    {
        return true;
    }
    else
        return false;
}

bool SQL::isUser(QString login, QString password)
{
    query->prepare("SELECT * FROM users WHERE LOGIN = :login AND PASS = :password");
    query->bindValue(0,login);
    query->bindValue(1,password);
    query->exec();
    if(query->next())
    {
        query->prepare("SELECT users.id FROM users WHERE LOGIN =:login");
        query->bindValue(0,login);
        query->exec();
        query->first();
        userId = query->value(0).toInt();
        return true;
    }
    else
        return false;
}

bool SQL::getCarName(QString &stream, int &idcar)
{

    if(query->next())
    {
        QString result = query->value(1).toString() + " " + query->value(2).toString() + " " + query->value(3).toString();
        stream = result;
        qDebug() << stream;
        idcar = query->value(0).toInt();
        qDebug() << idcar;
        return true;
    }
    else
        return false;
}

QString SQL::welcomeFunc()
{
    qDebug() << userId;
    query->prepare("SELECT CONCAT(first_name,' ',last_name) from users where users.id = :id");
    query->bindValue(0,userId);
    query->exec();
    query->first();
    return query->value(0).toString();
}

int SQL::lastMilage(int idcar)
{
    query->prepare("SELECT milage FROM fuel where carid =:idcar ORDER BY date DESC");
    query->bindValue(0,idcar);
    query->exec();
    query->first();
    return query->value(0).toInt();
}

void SQL::tankType(int tankid)
{
    //return query->value(4).toInt();

    query->prepare("SELECT id,mark, model, plate, tanks FROM cars WHERE user = :userid AND tanks =:tank");
    query->bindValue(0,userId);
    query->bindValue(1,tankid);
    query->exec();

    qDebug() << query->lastQuery();
    qDebug() << query->lastError().text();
}

void SQL::fuelInfo(int carId)
{
    query->prepare("SELECT * FROM `fuel` where CARID =:carid");
    query->bindValue(0,carId);
    query->exec();
}

void SQL::fuelInfo(int carId, int elderyear, int nowyear, int tt)
{
    query->prepare("SELECT * FROM `fuel` where CARID =:carid AND TANK =:tankType AND DATE BETWEEN '"+QString::number(elderyear)+"0000' AND '"+QString::number(nowyear)+"1231'");
    query->bindValue(0,carId);
    query->bindValue(1,tt);
    query->exec();
}

int SQL::fuelInfoCount(int carId)
{
    query->prepare("SELECT COUNT(1) FROM (SELECT * FROM `fuel` where CARID = :carid) AS tempTable");
    query->bindValue(0,carId);
    query->exec();
    query->first();
    if(query->result())
    {
        return query->value(0).toInt();
    }
}

bool SQL::fuelInfoQuest(int &fId, QString &fdate, float &fcon)
{
    if(query->next())
    {
        fId=query->value(0).toInt();
        fdate=query->value(1).toString();
        fcon=query->value(5).toFloat();

        qDebug() << fdate;

        return true;
    }
    else
        qDebug() << "Nima nic";
        return false;
}

int SQL::fuelInfoQuest()
{
    query->first();
    return query->value(6).toInt();
}

float SQL::fuelsCosts(int fuelType, int elderyear, int nowyear, int month)
{
    int cost =0;
    QString temp_numb, temp_numb2;
    if(month < 10)
    {
        temp_numb =("'"+QString::number(elderyear)+"0"+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+"0"+QString::number(month)+"31'");
        //qDebug() << "Temp < 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    else
    {
        temp_numb =("'"+QString::number(elderyear)+""+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+""+QString::number(month)+"31'");
        //qDebug() << "Temp > 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    query->prepare("SELECT price FROM fuel WHERE tank =:fuelType AND DATE BETWEEN "+temp_numb+" AND "+temp_numb2);
    query->bindValue(0,fuelType);
    query->exec();
    while(query->next())
    {
        cost=cost+query->value(0).toFloat();
    }

    //qDebug() << QString::number(cost);
    return cost;
}

float SQL::fuelsCosts(int fuelType, int elderyear, int nowyear, int month, int carID)
{
    int cost =0;
    QString temp_numb, temp_numb2;
    if(month < 10)
    {
        temp_numb =("'"+QString::number(elderyear)+"0"+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+"0"+QString::number(month)+"31'");
        //qDebug() << "Temp < 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    else
    {
        temp_numb =("'"+QString::number(elderyear)+""+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+""+QString::number(month)+"31'");
        //qDebug() << "Temp > 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    query->prepare("SELECT price FROM fuel WHERE tank =:fuelType AND DATE BETWEEN "+temp_numb+" AND "+temp_numb2+"AND carid =:car");
    query->bindValue(0,fuelType);
    query->bindValue(1,carID);
    query->exec();
    while(query->next())
    {
        cost=cost+query->value(0).toFloat();
    }

    //qDebug() << QString::number(cost);
    return cost;
}

float SQL::fuelQuantity(int fuelType, int elderyear, int nowyear, int month)
{
    int fuel =0;
    QString temp_numb, temp_numb2;
    if(month < 10)
    {
        temp_numb =("'"+QString::number(elderyear)+"0"+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+"0"+QString::number(month)+"31'");
        qDebug() << "Temp < 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    else
    {
        temp_numb =("'"+QString::number(elderyear)+""+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+""+QString::number(month)+"31'");
        qDebug() << "Temp > 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    query->prepare("SELECT fuel FROM fuel WHERE tank =:fuelType AND DATE BETWEEN "+temp_numb+" AND "+temp_numb2);
    query->bindValue(0,fuelType);
    query->exec();
    while(query->next())
    {
        fuel=fuel+query->value(0).toFloat();
    }

    qDebug() << QString::number(fuel);
    return fuel;
}

float SQL::fuelQuantity(int fuelType, int elderyear, int nowyear, int month, int carID)
{
    int fuel =0;
    QString temp_numb, temp_numb2;
    if(month < 10)
    {
        temp_numb =("'"+QString::number(elderyear)+"0"+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+"0"+QString::number(month)+"31'");
        qDebug() << "Temp < 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    else
    {
        temp_numb =("'"+QString::number(elderyear)+""+QString::number(month)+"00'");
        temp_numb2 =("'"+QString::number(nowyear)+""+QString::number(month)+"31'");
        qDebug() << "Temp > 10: " +temp_numb + " Temp2: "+ temp_numb2;
    }
    query->prepare("SELECT fuel FROM fuel WHERE tank =:fuelType AND DATE BETWEEN "+temp_numb+" AND "+temp_numb2+"AND carid =:car");
    query->bindValue(0,fuelType);
    query->bindValue(1,carID);
    query->exec();
    while(query->next())
    {
        fuel=fuel+query->value(0).toFloat();
    }

    qDebug() << QString::number(fuel);
    return fuel;
}

void SQL::error()
{
    QMessageBox::information(0,"Brak połączenia z serwerem","W trakcie wykonywania operacji utracono połaczenie z serwerem");


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

void SQL::CarName()
{
    query->prepare("SELECT id,mark, model, plate, tanks FROM cars WHERE user = :userid");
    query->bindValue(0,userId);
    query->exec();
}

void SQL::load_config(QString &lhost, QString &luser, QString &lpass, QString &ldb)
{
    QFile file("config.cfg");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "host\nuser\ndbname\npass\n";
        file.close();
        file.open(QIODevice::ReadOnly | QIODevice::Text);
    }
    QTextStream in( & file );
    in >> lhost;
    in >> luser;
    in >> ldb;
    in >> lpass;
    qDebug()<<lhost<<luser<<lpass<<ldb;
    //nie moga byc puste pola w pliku bo sie krzaczy
}
