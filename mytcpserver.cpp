#include "mytcpserver.h"
#include "functionsforserver.h"
#include <QDebug>
#include <QCoreApplication>

//! \brief Деструктор объекта сервера
//!
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}

//! \brief Конструктор объекта сервера
//! \details Производит инициализацию объекта сервера с уведомлением о статусе сервера
//!
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    DataBase::getInstance();

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "Server is not started :(";
    } else {
        //server_status=1;
        qDebug() << "Server is started :D";
    }
}

//! \brief Слот нового подключения
//! \details Создаёт новый объект сокета, инициализирует его и производит запись в список клиентов
//!
void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket* client;

        client = mTcpServer->nextPendingConnection();
        clients.push_back(client);
        qDebug() << "Some client was connected";

        connect(client, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(client, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
   // }
}

//! \brief Слот чтения
//! \details Считывает пользовательский ввод и передаёт данные в функцию парсинга
//!
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

//! \brief Слот отключения
//! \details Удаляет сокета из списка клиентов и закрывает его
//!
void MyTcpServer::slotClientDisconnected(){

    QTcpSocket* client = (QTcpSocket*)sender();

    clients.remove(client);
    qDebug() << "Client was disconnected";
    client->close();
}
