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
        DataBase();
        DataBase(const DataBase& );
        DataBase& operator = (DataBase &);
        ~DataBase() {}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!dataBasePointer)
            {
                dataBasePointer = new DataBase();
                dataBasePointer->db = QSqlDatabase::addDatabase("QSQLITE");
                dataBasePointer->db.setDatabaseName("DBclients");

                if(!dataBasePointer->db.open())
                        qDebug()<<dataBasePointer->db.lastError().text();

                destroyer.initialize(dataBasePointer);
            }
            return dataBasePointer;
        }

        static QByteArray test()
        {
            return "The response from the database was received :)";
        }

        void closeDB()
        {
            dataBasePointer->db.close();
        }
};


#endif // DATABASE_H
