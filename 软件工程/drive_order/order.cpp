#include "order.h"
#include "ui_order.h"

order::order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
}

order::~order()
{
    delete ui;

}
