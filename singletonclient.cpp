#include "singletonclient.h"


singletonclient::singletonclient(QObject *parent):QObject(parent)
{
    //mTcpSocket = new QTcpSocket(this);
    mTcpSocket.connectToHost("127.0.0.1",33333);
    // connect to host
    connect(&mTcpSocket, SIGNAL(readyRead()),this, SLOT(slotServerRead()));
}

 singletonclient* singletonclient::getlnstance(){
    if (!p_instance)
    {
        p_instance = new singletonclient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

 void singletonclient::serv(QString text) //отправка на сервер
 {
     mTcpSocket.write(text.toUtf8());
 }

 void singletonclient::slotServerRead(){
 qDebug();
 QString msg = "";
 while (mTcpSocket.bytesAvailable()>0)
 {
     QByteArray array =mTcpSocket.readAll();
     msg.append(array);
 }
    qDebug()<<msg;
    emit message_from_server(msg); // Принятие сообщений от сервера
}
