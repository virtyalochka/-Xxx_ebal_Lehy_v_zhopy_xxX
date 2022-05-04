#include "mainwindow.h"
#include "registration.h"
#include "task1.h"
#include "task3.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth = new Authorize();
    auth->show();
    task11 = new task1();
    task22 = new task2();
    task33 = new task3();
    task44 = new task4();
    connect(task44,&task4::authCorrect, this, &Authorize::show);
    connect(task33,&task3::authCorrect, this, &Authorize::show);
    connect(task22,&task2::authCorrect, this, &Authorize::show);
    connect(task11,&task1::authCorrect, this, &Authorize::show);
    connect(auth, &Authorize::authCorrect, this, &MainWindow::show_window);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_window()
{
    show();
}

void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}


void MainWindow::on_pushButton_Task1_clicked()
{
    this->close();
    task11->show();
}


void MainWindow::on_pushButton_Task2_clicked()
{
    this->close();
    task22->show();
}


void MainWindow::on_pushButton_Task4_clicked()
{
    this->close();
    task33->show();
}


void MainWindow::on_pushButton_Task3_clicked()
{
    this->close();
    task44->show();
}

