#include "student_deal.h"
#include "ui_student_deal.h"
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
static int c_today = 0;
static int c_tomorrow = 0;

student_deal::student_deal(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::student_deal)
{
    ui->setupUi(this);
    QSqlQuery sql,sql1,sql2;
    QString s,t;
    QString str[8]={
        "[8:00-9:00]",
        "[9:00-10:00]",
        "[10:00-11:00]",
        "[11:00-12:00]",
        "[14:00-15:00]",
        "[15:00-16:00]",
        "[16:00-17:00]",
        "[17:00-18:00]"
    };
    s=QString("select * from student_info where sid='%1'").arg(suid);//通过全局变量定位该学生的位置
    sql.exec(s);
    sql.next();
    //初始化信息界面
    ui->lineEdit_name->setText(sql.value(3).toString());
    ui->lineEdit_email->setText(sql.value(6).toString());
    ui->spinBox->setValue(sql.value(5).toInt());
    if(sql.value(4).toBool()==true)
      ui->radioButton->setChecked(true);
    else
      ui->radioButton_2->setChecked(true);

    setWindowTitle(ui->lineEdit_name->text()+"同学 Welcome!");


    //查询数据库，找学生的相关信息
    s = QString("select * from student_time where s_id='%1'").arg(suid);
    sql.exec(s);
    sql.next();

    int i;
    for(i=1;i<=8;i++){//循环查找判断今天的预约信息
        if(sql.value(i).toInt()){
            ui->label_8->setText(str[i-1]);
            t = QString("select c_name from coach_info where cid = '%1'").arg(sql.value(i).toInt());
            sql1.exec(t);
            sql1.next();
            ui->label_12->setText(sql1.value(0).toString());

            c_today = sql.value(i).toInt();//
            break;
        }
    }
    if(i > 8){//今天无预约
        ui->label_8->setText("无");
        ui->label_12->setText("无");
    }

    for(i=9;i<=16;i++){//循环查找判断明天的预约信息
        if(sql.value(i).toInt()){
            ui->label_15->setText(str[i-9]);
            t = QString("select c_name from coach_info where cid = '%1'").arg(sql.value(i).toInt());
            sql1.exec(t);
            sql1.next();
            ui->label_13->setText(sql1.value(0).toString());

            c_tomorrow = sql.value(i).toInt();
            break;
        }
    }

    if(i > 16){//明天无预约
        ui->label_15->setText("无");
        ui->label_13->setText("无");
    }




    //table2初始化
    s = QString("select c_name from coach_info");
    sql2.exec(s);
    while (sql2.next()) {
            ui->comboBox->addItem(sql2.value(0).toString());

    }



}

student_deal::~student_deal()
{
    delete ui;
}

void student_deal::on_pushButton_clicked()
{
    QSqlQuery sql1;
    QString user,user_pwd,user_pwd1,email;
    QString t;


    //完善个人信息
    user =ui->lineEdit_name->text();
    email=ui->lineEdit_email->text();
    user_pwd = ui->lineEdit_pwd->text();
    user_pwd1 = ui->lineEdit_pwd1->text();

    //更新至数据库中
    t=QString("update student_info set s_name='%1',s_email = '%2' where sid ='%3' ").arg(user).arg(email).arg(suid);
    sql1.exec(t);
    t=QString("update student_info set s_gender = '%1', s_age = '%2' where sid ='%3'").arg(ui->radioButton->isChecked()).arg(ui->horizontalSlider->value()).arg(suid);
    sql1.exec(t);

    if(user_pwd==user_pwd1)//两次密码不同
    {
        if(user_pwd!=nullptr){
             if(user_pwd.length()<=3)//判断密码是否小于3位
             {
                 QMessageBox::critical(this,"修改信息","登录密码不能小于3位！");
                 return;
             }
             t=QString("update student_info set s_pwd='%1' where sid ='%2' ").arg(user_pwd).arg(suid);
             sql1.exec(t);//更新数据库
        }

    }
    else{
         QMessageBox::critical(this,"提示","两次密码不同");
         return ;
    }
      setWindowTitle(ui->lineEdit_name->text()+"同学 Welcome!");
      QMessageBox::information(this,"提示","修改成功");
      return;
}

void student_deal::on_horizontalSlider_valueChanged(int value)
{
     ui->spinBox->setValue(value);
}

void student_deal::on_spinBox_valueChanged(int arg1)
{
     ui->horizontalSlider->setValue(arg1);
}


//界面三的操作
void student_deal::on_pushButton_2_clicked()//界面三的操作
{
    QSqlQuery sql;
    QString str,s,gender="";

    s = QString("select * from coach_info where cid = '%1'").arg(c_today);//全局变量获取今天预约教练的位置
    sql.exec(s);
    if(sql.next()){//今天有预约
        if(sql.value(3).toInt()) gender = "男";
        else gender = "女";
        str = "姓名: " + sql.value(5).toString() + '\n' +
              "性别: " + gender + '\n' +
              "年龄: " + sql.value(4).toString() + '\n' +
              "电话: " + sql.value(1).toString() + '\n' +
              "邮箱: " + sql.value(6).toString();
    }
    else{//无预约
        str = "姓名: " + sql.value(5).toString() + '\n' +
              "性别: " + gender + '\n' +
              "年龄: " + sql.value(4).toString() + '\n' +
              "电话: " + sql.value(1).toString() + '\n' +
              "邮箱: " + sql.value(6).toString();
    }
    QMessageBox::information(this,"教练信息",str);
}

void student_deal::on_pushButton_3_clicked()
{
    QSqlQuery sql;
    QString str,s,gender="";

    s = QString("select * from coach_info where cid = '%1'").arg(c_tomorrow);//全局变量获取明天预约教练的位置
    sql.exec(s);
    if(sql.next()){
        if(sql.value(3).toInt()) gender = "男";
        else gender = "女";
        str = "姓名: " + sql.value(5).toString() + '\n' +
              "性别: " + gender + '\n' +
              "年龄: " + sql.value(4).toString() + '\n' +
              "电话: " + sql.value(1).toString() + '\n' +
              "邮箱: " + sql.value(6).toString();
    }
    else{
        str = "姓名: " + sql.value(5).toString() + '\n' +
              "性别: " + gender + '\n' +
              "年龄: " + sql.value(4).toString() + '\n' +
              "电话: " + sql.value(1).toString() + '\n' +
              "邮箱: " + sql.value(6).toString();
    }
    QMessageBox::information(this,"教练信息",str);
}




//界面2的操作
void student_deal::on_comboBox_currentIndexChanged(int index)//获取下拉框中教练信息
{
    QSqlQuery sql;
    QString s,gender,str;
    s=QString("select * from coach_info where cid = '%1'").arg(index+1);//根据位置来找到教练
    sql.exec(s);
    sql.next();
    if(sql.value(3).toInt()) gender = "男";
    else gender = "女";
    str = "姓名: " + sql.value(5).toString() + '\n' +
          "性别: " + gender + '\n' +
          "年龄: " + sql.value(4).toString() + '\n' +
          "电话: " + sql.value(1).toString() + '\n' +
          "邮箱: " + sql.value(6).toString();

    ui->textEdit->setText(str);//显示教练信息




}

void student_deal::on_pushButton_4_clicked()//选教练后跳至相关的预约界面
{
    if(ui->comboBox->currentIndex()>=0){
        index = ui->comboBox->currentIndex();
        dlg = new order1(this);
        qDebug()<<ui->comboBox->currentIndex() << "aaaa";
        dlg->exec();
    }
    else QMessageBox::warning(this,"警告","请选择教练！！！");


}


void student_deal::on_student_deal_currentChanged(int _index)//根据最新的预约来修改界面3的信息
{
    if(_index==2){
        QSqlQuery sql,sql1;
        QString s,t;
        QString str[8]={
            "[8:00-9:00]",
            "[9:00-10:00]",
            "[10:00-11:00]",
            "[11:00-12:00]",
            "[14:00-15:00]",
            "[15:00-16:00]",
            "[16:00-17:00]",
            "[17:00-18:00]"
        };

        s = QString("select * from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();

        int i;
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()){
                ui->label_8->setText(str[i-1]);
                t = QString("select c_name from coach_info where cid = '%1'").arg(sql.value(i).toInt());
                sql1.exec(t);
                sql1.next();
                ui->label_12->setText(sql1.value(0).toString());

                c_today = sql.value(i).toInt();
                break;
            }
        }
        if(i > 8){
            ui->label_8->setText("无");
            ui->label_12->setText("无");
        }

        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()){
                ui->label_15->setText(str[i-9]);
                t = QString("select c_name from coach_info where cid = '%1'").arg(sql.value(i).toInt());
                sql1.exec(t);
                sql1.next();
                ui->label_13->setText(sql1.value(0).toString());

                c_tomorrow = sql.value(i).toInt();
                break;
            }
        }

        if(i > 16){
            ui->label_15->setText("无");
            ui->label_13->setText("无");
        }

    }
}
