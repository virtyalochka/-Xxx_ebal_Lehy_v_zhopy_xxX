#include "form.h"
#include "ui_form.h"
#include <QDebug> // Распечатать консоль
#include <iostream>

using namespace std;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    vector <vector <int>> prufer_der;
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text(); //Получаем строку
    qDebug() << s;
    QStringList w=s.split(",");
    qDebug() << w;
    QVector<QString> vs=w.toVector();
    qDebug() << vs;
    vector <int> v_new;
    for (int i = 0; i<vs.size();i++){
        v_new.push_back(vs[i].toInt());

    }
    qDebug() << v_new.size();
    for (int i = 0; i<v_new.size();i++){
        qDebug() << v_new[i];
    }
}

