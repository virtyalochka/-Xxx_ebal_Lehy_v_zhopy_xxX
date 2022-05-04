#ifndef TASK3_H
#define TASK3_H

#include <QWidget>

namespace Ui {
class task3;
}

class task3 : public QWidget
{
    Q_OBJECT

public:
    explicit task3(QWidget *parent = nullptr);
    ~task3();

signals:void authCorrect();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::task3 *ui;
};

#endif // TASK3_H
