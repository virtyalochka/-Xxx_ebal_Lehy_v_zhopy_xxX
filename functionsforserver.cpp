#include "functionsforserver.h"
#include "database.h"
#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>
//! \brief Функция регистрации пользователя
//! \param log - логин пользователя
//! \param pass - пароль пользователя
//! \return Возвращает сообщение об успешной регистрации

QByteArray reg(QString log, QString pass)
{
    return "You have registered";
}

//! \brief Функция авторизации пользователя
//! \param log - логин пользователя
//! \param pass - пароль пользователя
//! \return Возвращает сообщение об успешной авторизации
//!
QByteArray auth(QString log, QString pass)
{
    return DataBase::test();
}

//! \brief Функция парсинга
//! \details Функция анализа вводимого пользователем текста
//! \param data_from_client - переменная для хранения пользовательского ввода
//! \return Возвращает статус вызова функции
//!
QByteArray parsing (QString data_from_client)
{

    if(data_from_client.contains('&'))
    {
        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        QString log, pass;

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return reg(log, pass);
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(log, pass);
        }
    } else
    {
        return data_from_client.toUtf8();
    }

}




