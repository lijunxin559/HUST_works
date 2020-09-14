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
    if(ui->radioButton->isChecked()==true)
         s = QString("select Cid,c_phone,c_pwd from coach_info  where c_phone = '%1' AND c_pwd = '%2'").arg(user).arg(user_pwd);
    else
        s = QString("select sid,s_phone,s_pwd from student_info  where s_phone = '%1' AND s_pwd = '%2'").arg(user).arg(user_pwd);
    sql.exec(s);
    if(sql.next())
    {
        QMessageBox::information(this,"登录情况","登录成功");
    }
    else
        QMessageBox::information(this,"登录情况","登录失败");

}

void login::on_pushButton_2_clicked()
{
     emit loginReturnmainform();
     ui->lineEdit->setText("");
     ui->lineEdit_2->setText("");
     this->close();
}
