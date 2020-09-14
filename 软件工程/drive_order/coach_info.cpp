#include "coach_info.h"
#include "ui_coach_info.h"

coach_info::coach_info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::coach_info)
{
    ui->setupUi(this);
}

coach_info::~coach_info()
{
    delete ui;
}
