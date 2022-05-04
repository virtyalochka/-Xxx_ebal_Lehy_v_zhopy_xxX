#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registration.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include <QMainWindow>
#include <authorize.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void show_window();
    void on_pushButton_Exit_clicked();

    void on_pushButton_Task1_clicked();

    void on_pushButton_Task2_clicked();

    void on_pushButton_Task4_clicked();

    void on_pushButton_Task3_clicked();

private:
    Ui::MainWindow *ui;
    Authorize *auth;
    task1 *task11;
    task2 *task22;
    task3 *task33;
    task4 *task44;

};
#endif // MAINWINDOW_H
