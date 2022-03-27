#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include <QString>

QByteArray parsing (QString data_from_client);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass);

#endif // FUNCTIONSFORSERVER_H
