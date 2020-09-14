#include "login.h"
#include "ui_login.h"
#include <QApplication>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPushButton>
#include "global.h"


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

    QSqlQuery sql;
    QString user,user_pwd;
    QString s;
    user =ui->lineEdit->text();
    user_pwd = ui->lineEdit_2->text();
    if(user==nullptr||user_pwd==nullptr)
            QMessageBox::warning(nullptr, "warning", "手机号与密码不能为空");
    if(ui->radioButton->isChecked()==true)//判断登录用户是学员还是教练
         s = QString("select Cid,c_phone,c_pwd from coach_info  where c_phone = '%1' AND c_pwd = '%2'").arg(user).arg(user_pwd);
    else
        s = QString("select sid,s_phone,s_pwd from student_info  where s_phone = '%1' AND s_pwd = '%2'").arg(user).arg(user_pwd);
    sql.exec(s);
    if(sql.next())
    {
        QMessageBox::information(this,"登录情况","登录成功");
        if(ui->radioButton->isChecked()==true)
        {
            cuid = sql.value(0).toInt();//全局变量定位此教练在数据库表格中的位置
            c_d = new coach_deal;
            c_d->show();
            this->hide();

        }
        else {
             suid = sql.value(0).toInt();//全局变量定位此学员在数据库表格中的位置
             s_d = new student_deal;
             s_d->show();
             this->hide();
        }
        this->close();
    }
    else
        QMessageBox::information(this,"登录情况","登录失败");

}

void login::on_pushButton_2_clicked()
{
     emit loginReturnmainform();//发送返回父页面的请求信号

    //清空界面信息
     ui->lineEdit->setText("");
     ui->lineEdit_2->setText("");
     this->close();
}
