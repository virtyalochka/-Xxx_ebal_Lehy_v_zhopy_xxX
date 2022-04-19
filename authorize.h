#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <QDialog>
#include <functionsforclient.h>

namespace Ui {
class Authorize;
}

class Authorize : public QDialog
{
    Q_OBJECT

public:
    explicit Authorize(QWidget *parent = nullptr);
    ~Authorize();

private slots:
    void on_pushButton_Auth_clicked();

signals:
    void authCorrect();

private:
    Ui::Authorize *ui;
};

#endif // AUTHORIZE_H
