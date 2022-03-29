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
    return "You have authorized";
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
        QString NoF = data_from_client_list.at(0);

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return reg(data_from_client_list.at(0), data_from_client_list.at(1));
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(data_from_client_list.at(0), data_from_client_list.at(1));
        }
    } else
    {
        return data_from_client.toUtf8();
    }

}




