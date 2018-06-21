#include "requesthandleanalysis.h"

const QMap<QString, int> RequestHandleAnalysis::tankTypes = {{"DIESEL",0},{"PB",1},
                                                             {"PBAndLPG",2},{"LPG",3}};

RequestHandleAnalysis::RequestHandleAnalysis()
{

}

void RequestHandleAnalysis::loadCarNamesList(QString tanktype, QVector<QString> &carnames)
{
    QSqlQuery query(db);
    query.prepare("SELECT MARK, PLATE FROM cars WHERE cars.usr = :usr AND tanks = :tanktype");
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
        carnames.append(QString(query.value("mark").toString()+" "+query.value("model").toString()
                                + " " + query.value("plate").toString()));
    }
}
