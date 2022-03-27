#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "Server is not started :(";
    } else {
        //server_status=1;
        qDebug() << "Server is started :D";
    }
}

void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket* client;

        client = mTcpServer->nextPendingConnection();
        clients.push_back(client);
        qDebug() << "Some client was connected";

        client->write("Hello, I am echo server! You've connected to me!\r\n");

        connect(client, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(client, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){

    QString res = "";
    QTcpSocket* client = (QTcpSocket*)sender();

    while(client->bytesAvailable()>0)
    {
        QByteArray array = client->readAll();
        res.append(array);
    }
    client->write(parsing(res.toUtf8()));
}

void MyTcpServer::slotClientDisconnected(){

    QTcpSocket* client = (QTcpSocket*)sender();

    clients.remove(client);
    qDebug() << "Client was disconnected";
    client->close();
}
