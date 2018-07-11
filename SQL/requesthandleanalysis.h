#ifndef REQUESTHANDLEANALYSIS_H
#define REQUESTHANDLEANALYSIS_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVector>
#include <QMap>
#include <QString>
#include <sql.h>
#include <QDebug>

class RequestHandleAnalysis: public SQL
{
public:
    RequestHandleAnalysis();

    static const QMap<QString, int> tankTypes;

    void loadCarNamesList(QString tanktype, QMap<QString, int> &carnames);
    float fuelsCosts(QString tanktype, QString laterDate, QString earlierDate, int carID);

private:

};

#endif // REQUESTHANDLEANALYSIS_H
