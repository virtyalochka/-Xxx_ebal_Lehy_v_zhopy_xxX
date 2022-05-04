#include "task2.h"
#include "ui_task2.h"

task2::task2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
}

task2::~task2()
{
    delete ui;
}

void task2::on_pushButton_clicked()
{
    this->close();
    emit authCorrect();
}


void task2::on_pushButton_2_clicked()
{
    this->close();
}

