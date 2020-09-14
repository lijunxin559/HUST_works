#include "apply.h"
#include "ui_apply.h"
#include <QApplication>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPushButton>

apply::apply(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::apply)
{
    ui->setupUi(this);
    ui->radioButton_coach->setChecked(true);
}

apply::~apply()
{
    delete ui;
}

void apply::on_pushButton_2_clicked()
{
    emit ApplyReturnmainform();
    ui->lineEdit_phone->setText("");
    ui->lineEdit_pwd->setText("");
    ui->lineEdit_pwd1->setText("");


    this->close();
}

void apply::on_pushButton_clicked()
{

    QSqlQuery sql;
    QString user,user_pwd,user_pwd1;

    QString s,t;
    user =ui->lineEdit_phone->text();
    user_pwd = ui->lineEdit_pwd->text();
    user_pwd1 = ui->lineEdit_pwd1->text();
    if(ui->radioButton_coach->isChecked()==true){
         s = QString("insert into coach_info(c_phone,c_pwd,c_name) values('%1','%2','%3')").arg(user).arg(user_pwd).arg(user);
         t = QString("insert into coach_time(c_phone) values('%1')").arg(user);
    }
    else{
         s = QString("insert into student_info(s_phone,s_pwd,s_name) values('%1','%2','%3')").arg(user).arg(user_pwd).arg(user);
         t = QString("insert into student_time(s_phone) values('%1')").arg(user);
    }

if(user.length()<3||user_pwd.length()<=3)//判断密码、账号是否小于3位
{
        QMessageBox::critical(this,"注册情况","登录账号不小于3位，密码不能小于3位！");
        return;
    }
    if(user.length()==0)
    {
        QMessageBox::critical(this,"注册情况","用户名不能为空");
        return;
    }
    if(user_pwd!=user_pwd1)
    {
        QMessageBox::critical(this,"提示","两次密码不同");
        return ;
    }
    if(sql.exec(s))
    {
        sql.exec(t);
        QMessageBox::information(this,"注册情况","注册成功！请后续完善信息！");
        ui->lineEdit_phone->setText("");
        ui->lineEdit_pwd->setText("");
        ui->lineEdit_pwd1->setText("");
        emit ApplyReturnmainform();
        this->close();
    }
    else
        QMessageBox::critical(this,"注册情况","注册失败！");
}

