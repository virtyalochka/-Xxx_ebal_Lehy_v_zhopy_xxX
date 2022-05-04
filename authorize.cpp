#include "authorize.h"
#include "registration.h"
#include "ui_authorize.h"

Authorize::Authorize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorize)
{
    ui->setupUi(this);
    reg = new Registration();
    connect(reg,&Registration::authCorrect, this, &Authorize::show);

}
Authorize::~Authorize()
{
    delete ui;
}

void Authorize::on_pushButton_Auth_clicked() // Кнопка авторизации
{
    QString mylog = "";
    QString mypass = "";
    mylog = ui->lineEdit_Login->text();
    mypass = ui->lineEdit_Password->text();
    /*if (ui->lineEdit_email->isVisible())
                reg()... - авторизация
        else регистрация*/

    authorize(mylog, mypass);

    close();

    emit authCorrect();
}


void Authorize::on_pushButton_Reg_clicked() // Кнопка регистрации
{
    this->close();
    reg->show();
}

