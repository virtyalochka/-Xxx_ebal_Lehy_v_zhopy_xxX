#include "authorize.h"
#include "ui_authorize.h"

Authorize::Authorize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorize)
{
    ui->setupUi(this);
}

Authorize::~Authorize()
{
    delete ui;
}
