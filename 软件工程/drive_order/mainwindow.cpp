#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new apply;
    l = new login;
    //连接两子页面的发送的返回请求信号
    connect(a,SIGNAL(ApplyReturnmainform()),this,SLOT(showRequest()));
    connect(l,SIGNAL(loginReturnmainform()),this,SLOT(showRequest()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_apply_clicked()//跳转至注册界面
{

    a->setWindowTitle("注册");
    this->hide();
    a->show();
}
void MainWindow::showRequest()//处理子页面的返回信号，显示父页面
{
    this->show();
}

void MainWindow::on_pushButton_login_clicked()//跳转至登录界面
{
    l->setWindowTitle("登录");
    this->hide();
    l->show();
}
