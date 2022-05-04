#ifndef TASK4_H
#define TASK4_H

#include <QWidget>

namespace Ui {
class task4;
}

class task4 : public QWidget
{
    Q_OBJECT

public:
    explicit task4(QWidget *parent = nullptr);
    ~task4();

signals:void authCorrect();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::task4 *ui;
};

#endif // TASK4_H
