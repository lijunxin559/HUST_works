#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new apply;
    connect(a,SIGNAL(ApplyReturnmainform()),this,SLOT(showRequest()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_apply_clicked()
{

    a->setWindowTitle("注册");
    this->hide();
    a->show();
}
void MainWindow::showRequest()
{
    this->show();
}

