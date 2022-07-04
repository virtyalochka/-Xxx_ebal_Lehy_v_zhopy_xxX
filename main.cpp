#include <QCoreApplication>
#include "mytcpserver.h"
//#include "database.h"
//! \brief Тело программы
//! \param argc Параметр командной строки 1, int
//! \param argv Параметр командной строки 2, char[]
//! \return Запуск программы

DataBase * DataBase::dataBasePointer = 0;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

int main(int argc, char *argv[])
{   
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
