#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include "database.h"

#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>

//! \brief Файл с функциями сервера
//! \details Здесь объявлены функции авторизации, регистрации пользователей, а также функция парсинга для обработки ввода клиентов

QByteArray parsing (QString data_from_client);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass);

#endif // FUNCTIONSFORSERVER_H
