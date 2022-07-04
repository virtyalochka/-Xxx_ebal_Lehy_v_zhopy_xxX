#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/echoServer/PTechnologies/DBclients.db");

    if(!db.open())
            qDebug()<<db.lastError().text();
    else
        qDebug()<< "fdsfds";

    QSqlQuery query;
    query.exec("SELECT * FROM User");
    query.next();
    qDebug()<< query.record().value(1);


    db.close();

    return a.exec();
}
