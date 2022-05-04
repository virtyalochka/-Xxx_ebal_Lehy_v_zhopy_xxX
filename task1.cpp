#include "task1.h"
#include "ui_task1.h"

task1::task1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task1)
{
    ui->setupUi(this);

}

task1::~task1()
{
    delete ui;
}

void task1::on_pushButton_clicked()
{
    this->close();
    emit authCorrect();
}


void task1::on_pushButton_2_clicked()
{
    this->close();
}

