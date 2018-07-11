#include "requesthandleanalysis.h"

const QMap<QString, int> RequestHandleAnalysis::tankTypes = {{"DIESEL",0},{"PB",1},
                                                             {"LPG",2},{"PBAndLPG",3}};

RequestHandleAnalysis::RequestHandleAnalysis()
{

}

void RequestHandleAnalysis::loadCarNamesList(QString tanktype, QMap<QString, int> &carnames)
{
    QSqlQuery query(db);
    query.prepare("SELECT id,mark, model, plate FROM cars WHERE cars.usr = :usr AND tanks = :tanktype");
    query.bindValue(":usr",userId);
    query.bindValue(":tanktype",tankTypes.value(tanktype));

    if(!query.exec())
    {
        qDebug() << "V: " << userId << " i " << tankTypes.value(tanktype);
        qDebug() << QString("Error: %1 -|- %2").arg(query.lastError().type()).arg(query.lastError().text());
        qDebug() << QString("Class: %1 -|- %2").arg(__FILE__).arg(__FUNCTION__);
        qDebug() << QString("Query: %1").arg(query.lastQuery());
        return;
    }

    while(query.next()){
        QString value = QString(query.value("mark").toString()+" "+query.value("model").toString()
                                + " " + query.value("plate").toString());
        carnames.insert(value,query.value("id").toInt());
    }
}

float RequestHandleAnalysis::fuelsCosts(QString tanktype, QString laterDate, QString earlierDate, int carID)
{
    QSqlQuery query(db);
    query.prepare("SELECT SUM(price) as prices FROM fuel WHERE carid = :carid AND datestump BETWEEN :laterdate AND :earlierdate "
                  "AND tank = :tank");
    query.bindValue(":carid",carID);
    query.bindValue(":laterdate",laterDate);
    query.bindValue(":earlierdate",earlierDate);
    query.bindValue(":tank",tankTypes.value(tanktype));

    if(!query.exec())
    {
        qDebug() << "V: " << userId << " i " << tankTypes.value(tanktype);
        qDebug() << QString("Error: %1 -|- %2").arg(query.lastError().type()).arg(query.lastError().text());
        qDebug() << QString("Class: %1 -|- %2").arg(__FILE__).arg(__FUNCTION__);
        qDebug() << QString("Query: %1").arg(query.lastQuery());
        return -1;
    }
    query.next();
    qDebug() << query.value("prices").toFloat();
    return query.value("prices").toFloat();
}
