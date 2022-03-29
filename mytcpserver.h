#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <list>
#include "functionsforserver.h"
//! \brief MyTcpServer - класс сервера, содержащий начальные настройки
//! \details В этом классе объявлены слоты для обработки подключения, отключения клиентов и обработки ввода пользователей
//! slotNewConnection() - слот для обработки нового подключения
//! slotClientDisconnected() - слот для обработки отключения клиента
//! slotServerRead() - слот для обработки ввода клиентов

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();

private:
    QTcpServer * mTcpServer;
    std::list <QTcpSocket*> clients;
};
#endif // MYTCPSERVER_H







