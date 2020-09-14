#include "student.h"
#include "ui_student.h"

student::student(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
}

student::~student()
{
    delete ui;
}
