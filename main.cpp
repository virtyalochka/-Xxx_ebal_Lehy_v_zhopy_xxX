#include <QCoreApplication>
#include "mytcpserver.h"
//! \brief Тело программы
//! \param argc Параметр командной строки 1, int
//! \param argv Параметр командной строки 2, char[]
//! \return Запуск программы

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
