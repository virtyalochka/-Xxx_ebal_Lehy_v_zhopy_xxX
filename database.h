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
        QByteArray reg(QString log, QString pass)
        {
            QSqlQuery query(dataBasePointer->db);

            query.prepare("SELECT * FROM User WHERE login==:login");
               query.bindValue(":login", log);
               query.exec();

               QSqlRecord rec = query.record();
               const int logIndex = rec.indexOf("login");
               const int passIndex = rec.indexOf("password");
               query.next();

               if(!query.isValid())
               {
                   query.prepare("INSERT INTO User(login, password) "
                                     "VALUES (:login, :password)");
                   query.bindValue(":password", pass);
                   query.bindValue(":login", log);
                   query.exec();
                   return "You are successfully registered!";
               }
               else if(query.value(logIndex) == log && query.value(passIndex) != pass)
               {
                   return "Invalid password.";
               }
               else
               {
                   return "Such user is already exists.";
               }
        }

        QByteArray auth(QString log, QString pass)
        {
            QSqlQuery query(dataBasePointer->db);

            query.prepare("SELECT * FROM User WHERE login==:login");
            query.bindValue(":login", log);
            query.exec();

            QSqlRecord rec = query.record();
            const int passIndex = rec.indexOf("password");
            query.next();

            if(!rec.isEmpty() && query.isValid())
            {
                if(query.value(passIndex) != pass)
                   {
                       return "Invalid password.";
                   }
                   else
                   {
                       return "You are successfully authorized!";
                   }
            }
            else
            {
                return "Such user doesn't exist.";
            }
        }

        void closeDB()
        {
            dataBasePointer->db.close();
        }
};


#endif // DATABASE_H
