#include "database.h"

//DataBase* DataBase:: dataBasePointer = 0;
//DataBaseDestroyer DataBase::destroyer;

/*
DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DBclients.db");

    if(!db.open())
            qDebug()<<db.lastError().text();
}

DataBase* DataBase::getInstance()
{
    if (!dataBasePointer)
    {
        dataBasePointer = new DataBase();
        destroyer.initialize(dataBasePointer);
    }
    return dataBasePointer;
}

*/
