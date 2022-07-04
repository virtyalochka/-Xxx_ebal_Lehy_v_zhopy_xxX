#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * dataBasePointer;
    public:
        ~DataBaseDestroyer()
        {
            delete dataBasePointer;
        };
        void initialize(DataBase * p)
        {
            dataBasePointer = p;
        };
};


class DataBase
{
    private:
        static DataBase * dataBasePointer;
        static DataBaseDestroyer destroyer;
        static QSqlDatabase db;
    protected:
        DataBase()
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("D:/echoServer/PTechnologies/DBclients.db");

            if(!db.open())
                    qDebug()<<db.lastError().text();
        }

        DataBase(const DataBase& ) = delete;
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {db.close();}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance()
        {
            if (!dataBasePointer)
            {
                dataBasePointer = new DataBase();
                destroyer.initialize(dataBasePointer);
            }
            return dataBasePointer;
        }

        static QSqlQuery send_query(QString query_text)
        {
            QSqlQuery query(db);
            query.exec(query_text);

            return query;
        }
};

#endif // DATABASE_H
