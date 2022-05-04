#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "functionsforclient.h"

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT


public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

signals:

    void authCorrect();
/*
private slots:
    void on_pushButton_Auth_clicked();
*/

private:
    Ui::Registration *ui;
};

#endif // Registration_H
