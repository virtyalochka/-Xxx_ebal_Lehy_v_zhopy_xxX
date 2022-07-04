#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth = new Authorize();
    auth->show();
    connect(auth,SIGNAL(authCorrect),this,SLOT(show_window));
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

