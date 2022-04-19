#include "functionsforclient.h"

void authorize(QString log, QString pass)
{
    QString res = "";
    res = "auth&" + log + "&" + pass;
    qDebug()<<res;
    //Client::sendToServer(res);
}
