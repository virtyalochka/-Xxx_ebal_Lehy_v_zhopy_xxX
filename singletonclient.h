#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class singletonclient;

class SingletonDestroyer
{
    private:
         singletonclient * p_instance;
    public:
        ~SingletonDestroyer() {delete p_instance;}
        void initialize(singletonclient * p){p_instance = p;};
};


class singletonclient:public QObject //наследование, чтобы были сигналы
{
    Q_OBJECT
    private:
        static singletonclient * p_instance;
        static SingletonDestroyer destroyer;
        static QTcpSocket mTcpSocket;
    protected:
        explicit singletonclient(QObject *parent = nullptr);
        singletonclient(singletonclient&)= delete;
        singletonclient& operator = (singletonclient&) = delete;
        ~singletonclient()
        {
            mTcpSocket.close(); //деструктор, отключение от сервера
        }
        friend class SingletonDestroyer;
    public:
        static singletonclient* getlnstance();
        static void serv(QString text); //отправка на сервер


    signals:
        void message_from_server(QString msg); // принятие

    private slots:
        void slotServerRead();

};

#endif // SINGLETONCLIENT_H
