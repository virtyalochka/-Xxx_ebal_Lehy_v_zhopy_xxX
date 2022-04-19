#include "authorize.h"
#include "ui_authorize.h"

Authorize::Authorize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorize)
{
    ui->setupUi(this);
}

Authorize::~Authorize()
{
    delete ui;
}

void Authorize::on_pushButton_Auth_clicked()
{
    QString mylog = "";
    QString mypass = "";
    mylog = ui->lineEdit_Login->text();
    mypass = ui->lineEdit_Password->text();

    authorize(mylog, mypass);

    close();

    emit authCorrect();
}

