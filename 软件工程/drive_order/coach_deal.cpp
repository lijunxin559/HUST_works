#include "coach_deal.h"
#include "ui_coach_deal.h"
#include <QApplication>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPushButton>
#include"global.h"
extern int cuid;
extern int suid;

coach_deal::coach_deal(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::coach_deal)
{
    ui->setupUi(this);
    //时间设定







    //
    QSqlQuery sql,sql2;
    QString s;
    s=QString("select * from coach_info where cid='%1'").arg(cuid);//根据之前的登录时全局变量定位
    sql.exec(s);
    sql.next();
    //显示教练信息
    ui->lineEdit_name->setText(sql.value(5).toString());
    ui->lineEdit_email->setText(sql.value(6).toString());
    ui->spinBox->setValue(sql.value(4).toInt());
    if(sql.value(3).toBool()==true)
      ui->radioButton->setChecked(true);
    else
      ui->radioButton_2->setChecked(true);
    setWindowTitle(ui->lineEdit_name->text()+"教练 Welcome!");

    //设置表格显示教练的被预约信息
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"今天"<<"明天");
    ui->tableWidget->setVerticalHeaderLabels(QStringList()<<"[8:00-9:00]"<<"[9:00-10:00]"<<"[10:00-11:00]"<<"[11:00-12:00]"
                                             <<"[14:00-15:00]"<<"[15:00-16:00]"<<"[16:00-17:00]"<<"[17:00-18:00]");

    s = QString("select * from coach_time where c_id='%1'").arg(cuid);
    //查询数据库
    sql.exec(s);
    sql.next();
    for(int i = 0;i < 2;i++)//循环得出此教练的所有预约信息，并显示
        for(int j = 0; j < 8;j++)
        {

            int code;
            code = sql.value(i*8+j+1).toInt();
            if(code>=1){
                s = QString("select s_name from student_info where sid = '%1'").arg(code);
                sql2.exec(s);
                sql2.next();
                ui->tableWidget->setItem(j,i,new QTableWidgetItem(sql2.value(0).toString()));
            }
        }




    //根据数据库查询内容设置button初始文本
    if(sql.value(1).toInt()==0)
        ui->pushButton_1_1->setText("有空");
    else if(sql.value(1).toInt()>0)
        ui->pushButton_1_1->setText("已被预约");
    else ui->pushButton_1_1->setText("没空");

    if(sql.value(2).toInt()==0)
        ui->pushButton_1_2->setText("有空");
    else if(sql.value(2).toInt()>0)
        ui->pushButton_1_2->setText("已被预约");
    else ui->pushButton_1_2->setText("没空");

    if(sql.value(3).toInt()==0)
        ui->pushButton_1_3->setText("有空");
    else if(sql.value(3).toInt()>0)
        ui->pushButton_1_3->setText("已被预约");
    else ui->pushButton_1_3->setText("没空");

    if(sql.value(4).toInt()==0)
        ui->pushButton_1_4->setText("有空");
    else if(sql.value(4).toInt()>0)
        ui->pushButton_1_4->setText("已被预约");
    else ui->pushButton_1_4->setText("没空");

    if(sql.value(5).toInt()==0)
        ui->pushButton_1_5->setText("有空");
    else if(sql.value(5).toInt()>0)
        ui->pushButton_1_5->setText("已被预约");
    else ui->pushButton_1_5->setText("没空");

    if(sql.value(6).toInt()==0)
        ui->pushButton_1_6->setText("有空");
    else if(sql.value(6).toInt()>0)
        ui->pushButton_1_6->setText("已被预约");
    else ui->pushButton_1_6->setText("没空");

    if(sql.value(7).toInt()==0)
        ui->pushButton_1_7->setText("有空");
    else if(sql.value(7).toInt()>0)
        ui->pushButton_1_7->setText("已被预约");
    else ui->pushButton_1_7->setText("没空");

    if(sql.value(8).toInt()==0)
        ui->pushButton_1_8->setText("有空");
    else if(sql.value(8).toInt()>0)
        ui->pushButton_1_8->setText("已被预约");
    else ui->pushButton_1_8->setText("没空");

    if(sql.value(9).toInt()==0)
        ui->pushButton_2_1->setText("有空");
    else if(sql.value(9).toInt()>0)
        ui->pushButton_2_1->setText("已被预约");
    else ui->pushButton_2_1->setText("没空");

    if(sql.value(10).toInt()==0)
        ui->pushButton_2_2->setText("有空");
    else if(sql.value(10).toInt()>0)
        ui->pushButton_2_2->setText("已被预约");
    else ui->pushButton_2_2->setText("没空");

    if(sql.value(11).toInt()==0)
        ui->pushButton_2_3->setText("有空");
    else if(sql.value(11).toInt()>0)
        ui->pushButton_2_3->setText("已被预约");
    else ui->pushButton_2_3->setText("没空");

    if(sql.value(12).toInt()==0)
        ui->pushButton_2_4->setText("有空");
    else if(sql.value(12).toInt()>0)
        ui->pushButton_2_4->setText("已被预约");
    else ui->pushButton_2_4->setText("没空");

    if(sql.value(13).toInt()==0)
        ui->pushButton_2_5->setText("有空");
    else if(sql.value(13).toInt()>0)
        ui->pushButton_2_5->setText("已被预约");
    else ui->pushButton_2_5->setText("没空");

    if(sql.value(14).toInt()==0)
        ui->pushButton_2_6->setText("有空");
    else if(sql.value(14).toInt()>0)
        ui->pushButton_2_6->setText("已被预约");
    else ui->pushButton_2_6->setText("没空");

    if(sql.value(15).toInt()==0)
        ui->pushButton_2_7->setText("有空");
    else if(sql.value(15).toInt()>0)
        ui->pushButton_2_7->setText("已被预约");
    else ui->pushButton_2_7->setText("没空");

    if(sql.value(16).toInt()==0)
        ui->pushButton_2_8->setText("有空");
    else if(sql.value(16).toInt()>0)
        ui->pushButton_2_8->setText("已被预约");
    else ui->pushButton_2_8->setText("没空");

}

coach_deal::~coach_deal()
{
    delete ui;
}

void coach_deal::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

void coach_deal::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void coach_deal::on_pushButton_clicked()
{

    QSqlQuery sql1;
    QString user,user_pwd,user_pwd1,email;
    QString t;
    //完善个人信息并更新至数据库中
    user =ui->lineEdit_name->text();
    email=ui->lineEdit_email->text();
    user_pwd = ui->lineEdit_pwd->text();
    user_pwd1 = ui->lineEdit_pwd1->text();
    t=QString("update coach_info set c_name='%1',c_email = '%2' where cid ='%3' ").arg(user).arg(email).arg(cuid);
    sql1.exec(t);


    t=QString("update coach_info set c_gender = '%1', c_age = '%2' where cid ='%3'").arg(ui->radioButton->isChecked()).arg(ui->horizontalSlider->value()).arg(cuid);
    sql1.exec(t);

    if(user_pwd==user_pwd1)
    {
        if(user_pwd!=nullptr){
             if(user_pwd.length()<=3)//判断密码是否小于3位
             {
                 QMessageBox::critical(this,"修改情况","登录密码不能小于3位！");
                 return;
             }
             t=QString("update coach_info set c_pwd='%1' where cid ='%2' ").arg(user_pwd).arg(cuid);
             sql1.exec(t);
        }

    }
    else{
         QMessageBox::critical(this,"提示","两次密码不同");
         return ;
    }
      setWindowTitle(ui->lineEdit_name->text()+"教练 Welcome!");
      QMessageBox::information(this,"提示","修改成功");
      return;

}

//教练修改自己的空闲时间
void coach_deal::on_pushButton_1_1_clicked()
{
    QString s;
    if(ui->pushButton_1_1->text() == "有空"){
        ui->pushButton_1_1->setText("没空");
        s= QString("update coach_time set [1_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_1->text() == "没空"){
        ui->pushButton_1_1->setText("有空");
        s= QString("update coach_time set [1_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);

}



void coach_deal::on_pushButton_1_2_clicked()
{
    QString s;
    if(ui->pushButton_1_2->text() == "有空"){
        ui->pushButton_1_2->setText("没空");
        s= QString("update coach_time set [2_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_2->text() == "没空"){
        ui->pushButton_1_2->setText("有空");
        s= QString("update coach_time set [2_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}

void coach_deal::on_pushButton_1_3_clicked()
{
    QString s;
    if(ui->pushButton_1_3->text() == "有空"){
        ui->pushButton_1_3->setText("没空");
        s= QString("update coach_time set [3_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_3->text() == "没空"){
        ui->pushButton_1_3->setText("有空");
        s= QString("update coach_time set [3_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}



void coach_deal::on_pushButton_1_4_clicked()
{
    QString s;
    if(ui->pushButton_1_4->text() == "有空"){
        ui->pushButton_1_4->setText("没空");
        s= QString("update coach_time set [4_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_4->text() == "没空"){
        ui->pushButton_1_4->setText("有空");
        s= QString("update coach_time set [4_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}

void coach_deal::on_pushButton_1_5_clicked()
{
    QString s;
    if(ui->pushButton_1_5->text() == "有空"){
        ui->pushButton_1_5->setText("没空");
        s= QString("update coach_time set [5_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_5->text() == "没空"){
        ui->pushButton_1_5->setText("有空");
        s= QString("update coach_time set [5_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}

void coach_deal::on_pushButton_1_6_clicked()
{
    QString s;
    if(ui->pushButton_1_6->text() == "有空"){
        ui->pushButton_1_6->setText("没空");
        s= QString("update coach_time set [6_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_6->text() == "没空"){
        ui->pushButton_1_6->setText("有空");
        s= QString("update coach_time set [6_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}



void coach_deal::on_pushButton_1_7_clicked()
{
    QString s;
    if(ui->pushButton_1_7->text() == "有空"){
        ui->pushButton_1_7->setText("没空");
        s= QString("update coach_time set [7_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_7->text() == "没空"){
        ui->pushButton_1_7->setText("有空");
        s= QString("update coach_time set [7_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}


void coach_deal::on_pushButton_1_8_clicked()
{
    QString s;
    if(ui->pushButton_1_8->text() == "有空"){
        ui->pushButton_1_8->setText("没空");
        s= QString("update coach_time set [8_1] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_1_8->text() == "没空"){
        ui->pushButton_1_8->setText("有空");
        s= QString("update coach_time set [8_1] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}



void coach_deal::on_pushButton_2_1_clicked()
{
    QString s;
    if(ui->pushButton_2_1->text() == "有空"){
        ui->pushButton_2_1->setText("没空");
        s= QString("update coach_time set [1_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_1->text() == "没空"){
        ui->pushButton_2_1->setText("有空");
        s= QString("update coach_time set [1_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}


void coach_deal::on_pushButton_2_2_clicked()
{
    QString s;
    if(ui->pushButton_2_2->text() == "有空"){
        ui->pushButton_2_2->setText("没空");
        s= QString("update coach_time set [2_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_2->text() == "没空"){
        ui->pushButton_2_2->setText("有空");
        s= QString("update coach_time set [2_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}


void coach_deal::on_pushButton_2_3_clicked()
{
    QString s;
    if(ui->pushButton_2_3->text() == "有空"){
        ui->pushButton_2_3->setText("没空");
        s= QString("update coach_time set [3_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_3->text() == "没空"){
        ui->pushButton_2_3->setText("有空");
        s= QString("update coach_time set [3_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}

void coach_deal::on_pushButton_2_4_clicked()
{
    QString s;
    if(ui->pushButton_2_4->text() == "有空"){
        ui->pushButton_2_4->setText("没空");
        s= QString("update coach_time set [4_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_4->text() == "没空"){
        ui->pushButton_2_4->setText("有空");
        s= QString("update coach_time set [4_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}



void coach_deal::on_pushButton_2_5_clicked()
{
    QString s;
    if(ui->pushButton_2_5->text() == "有空"){
        ui->pushButton_2_5->setText("没空");
        s= QString("update coach_time set [5_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_5->text() == "没空"){
        ui->pushButton_2_5->setText("有空");
        s= QString("update coach_time set [5_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}


void coach_deal::on_pushButton_2_6_clicked()
{
    QString s;
    if(ui->pushButton_2_6->text() == "有空"){
        ui->pushButton_2_6->setText("没空");
        s= QString("update coach_time set [6_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_6->text() == "没空"){
        ui->pushButton_2_6->setText("有空");
        s= QString("update coach_time set [6_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}




void coach_deal::on_pushButton_2_7_clicked()
{
    QString s;
    if(ui->pushButton_2_7->text() == "有空"){
        ui->pushButton_2_7->setText("没空");
        s= QString("update coach_time set [7_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_7->text() == "没空"){
        ui->pushButton_2_7->setText("有空");
        s= QString("update coach_time set [7_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}



void coach_deal::on_pushButton_2_8_clicked()
{
    QString s;
    if(ui->pushButton_2_8->text() == "有空"){
        ui->pushButton_2_8->setText("没空");
        s= QString("update coach_time set [8_2] = -1 where c_id = '%1'").arg(cuid);
        }
    else if(ui->pushButton_2_8->text() == "没空"){
        ui->pushButton_2_8->setText("有空");
        s= QString("update coach_time set [8_2] = 0 where c_id = '%1'").arg(cuid);
        }
   QSqlQuery sql;
   sql.exec(s);
}




