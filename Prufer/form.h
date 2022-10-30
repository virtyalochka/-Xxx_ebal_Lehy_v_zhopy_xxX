#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QMainWindow>
#include "tree.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    Tree tree;
};

#endif // FORM_H
