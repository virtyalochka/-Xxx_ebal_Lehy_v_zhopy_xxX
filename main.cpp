#include <QCoreApplication>
#include "singletonclient.h"


singletonclient * singletonclient::p_instance;
SingletonDestroyer singletonclient::destroyer;
QTcpSocket singletonclient::mTcpSocket;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    singletonclient::getlnstance();
    singletonclient::serv("auth&user&123");
    return a.exec();
}
