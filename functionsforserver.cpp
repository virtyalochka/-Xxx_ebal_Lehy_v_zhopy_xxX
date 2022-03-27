#include "functionsforserver.h"
#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>

QByteArray reg(QString log, QString pass)
{
    return "You have registered";
}

QByteArray auth(QString log, QString pass)
{
    return "You have authorized";
}

QByteArray parsing (QString data_from_client)
{

    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));

    QString NoF = data_from_client_list.at(0);
    data_from_client_list.pop_front();

    if(NoF == "auth")
    {
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    }
    else if(NoF == "reg")
    {
        return reg(data_from_client_list.at(0), data_from_client_list.at(1));
    }
    else
    {
        return "Error\n";
    }
}




