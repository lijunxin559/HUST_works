#include "order1.h"
#include "ui_order1.h"
#include <QApplication>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPushButton>
#include<QDateTime>
#include"global.h"

order1::order1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order1)
{
    ui->setupUi(this);
    QSqlQuery sql;
    QString s;
    //根据全局变量index来定位是选择哪一位教练并查询
    s = QString("select * from coach_time where c_id = '%1'").arg(index+1);
    sql.exec(s);
    sql.next();




    //根据教练的预约时间表信息设置button初始文本
    if(sql.value(1).toInt()==0)
        ui->pushButton_1_1->setText("预约");
    else if(sql.value(1).toInt()>0)
    {
        if(sql.value(1).toInt()==suid)
            ui->pushButton_1_1->setText("预约成功");
        else
            ui->pushButton_1_1->setText("已被预约");

    }
    else ui->pushButton_1_1->setText("没空");


    if(sql.value(2).toInt()==0)
        ui->pushButton_1_2->setText("预约");
    else if(sql.value(2).toInt()>0)
    {
        if(sql.value(2).toInt()==suid)
            ui->pushButton_1_2->setText("预约成功");
        else
            ui->pushButton_1_2->setText("已被预约");

    }
    else ui->pushButton_1_2->setText("没空");


    if(sql.value(3).toInt()==0)
        ui->pushButton_1_3->setText("预约");
    else if(sql.value(3).toInt()>0)
    {
        if(sql.value(3).toInt()==suid)
            ui->pushButton_1_3->setText("预约成功");
        else
            ui->pushButton_1_3->setText("已被预约");

    }
    else ui->pushButton_1_3->setText("没空");


    if(sql.value(4).toInt()==0)
        ui->pushButton_1_4->setText("预约");
    else if(sql.value(4).toInt()>0)
    {
        if(sql.value(4).toInt()==suid)
            ui->pushButton_1_4->setText("预约成功");
        else
            ui->pushButton_1_4->setText("已被预约");

    }
    else ui->pushButton_1_4->setText("没空");


    if(sql.value(5).toInt()==0)
        ui->pushButton_1_5->setText("预约");
    else if(sql.value(5).toInt()>0)
    {
        if(sql.value(5).toInt()==suid)
            ui->pushButton_1_5->setText("预约成功");
        else
            ui->pushButton_1_5->setText("已被预约");

    }
    else ui->pushButton_1_5->setText("没空");


    if(sql.value(6).toInt()==0)
        ui->pushButton_1_6->setText("预约");
    else if(sql.value(6).toInt()>0)
    {
        if(sql.value(6).toInt()==suid)
            ui->pushButton_1_6->setText("预约成功");
        else
            ui->pushButton_1_6->setText("已被预约");

    }
    else ui->pushButton_1_6->setText("没空");

    if(sql.value(7).toInt()==0)
        ui->pushButton_1_7->setText("预约");
    else if(sql.value(7).toInt()>0)
    {
        if(sql.value(7).toInt()==suid)
            ui->pushButton_1_7->setText("预约成功");
        else
            ui->pushButton_1_7->setText("已被预约");

    }
    else ui->pushButton_1_7->setText("没空");

    if(sql.value(8).toInt()==0)
        ui->pushButton_1_8->setText("预约");
    else if(sql.value(8).toInt()>0)
    {
        if(sql.value(8).toInt()==suid)
            ui->pushButton_1_8->setText("预约成功");
        else
            ui->pushButton_1_8->setText("已被预约");

    }
    else ui->pushButton_1_8->setText("没空");

    if(sql.value(9).toInt()==0)
        ui->pushButton_2_1->setText("预约");
    else if(sql.value(9).toInt()>0)
    {
        if(sql.value(9).toInt()==suid)
            ui->pushButton_2_1->setText("预约成功");
        else
            ui->pushButton_2_1->setText("已被预约");

    }
    else ui->pushButton_2_1->setText("没空");

    if(sql.value(10).toInt()==0)
        ui->pushButton_2_2->setText("预约");
    else if(sql.value(10).toInt()>0)
    {
        if(sql.value(10).toInt()==suid)
            ui->pushButton_2_2->setText("预约成功");
        else
            ui->pushButton_2_2->setText("已被预约");

    }
    else ui->pushButton_2_2->setText("没空");

    if(sql.value(11).toInt()==0)
        ui->pushButton_2_3->setText("预约");
    else if(sql.value(11).toInt()>0)
    {
        if(sql.value(11).toInt()==suid)
            ui->pushButton_2_3->setText("预约成功");
        else
            ui->pushButton_2_3->setText("已被预约");

    }
    else ui->pushButton_2_3->setText("没空");

    if(sql.value(12).toInt()==0)
        ui->pushButton_2_4->setText("预约");
    else if(sql.value(12).toInt()>0)
    {
        if(sql.value(12).toInt()==suid)
            ui->pushButton_2_4->setText("预约成功");
        else
            ui->pushButton_2_4->setText("已被预约");

    }
    else ui->pushButton_2_4->setText("没空");

    if(sql.value(13).toInt()==0)
        ui->pushButton_2_5->setText("预约");
    else if(sql.value(13).toInt()>0)
    {
        if(sql.value(13).toInt()==suid)
            ui->pushButton_2_5->setText("预约成功");
        else
            ui->pushButton_2_5->setText("已被预约");

    }
    else ui->pushButton_2_5->setText("没空");

    if(sql.value(14).toInt()==0)
        ui->pushButton_2_6->setText("预约");
    else if(sql.value(14).toInt()>0)
    {
        if(sql.value(14).toInt()==suid)
            ui->pushButton_2_6->setText("预约成功");
        else
            ui->pushButton_2_6->setText("已被预约");

    }
    else ui->pushButton_2_6->setText("没空");

    if(sql.value(15).toInt()==0)
        ui->pushButton_2_7->setText("预约");
    else if(sql.value(15).toInt()>0)
    {
        if(sql.value(15).toInt()==suid)
            ui->pushButton_2_7->setText("预约成功");
        else
            ui->pushButton_2_7->setText("已被预约");

    }
    else ui->pushButton_2_7->setText("没空");

    if(sql.value(16).toInt()==0)
        ui->pushButton_2_8->setText("预约");
    else if(sql.value(16).toInt()>0)
    {
        if(sql.value(16).toInt()==suid)
            ui->pushButton_2_8->setText("预约成功");
        else
            ui->pushButton_2_8->setText("已被预约");

    }
    else ui->pushButton_2_8->setText("没空");
    //
}

order1::~order1()
{
    delete ui;
}

void order1::on_pushButton_1_1_clicked()
{
    QTime time = QTime::currentTime();//获取系统时间
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_1->text()=="预约"){//显示为预约，则可预约
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);//查询学生预约信息表
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){//预约前判断您今天是否已预约
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){//今天可预约的话
            if(hour<8){//判断当前时间是否超出8点
                ui->pushButton_1_1->setText("预约成功");
                s= QString("update coach_time set [1_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [1_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_1->text()=="预约成功"){  //若显示已预约则可取消预约

        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_1->setText("预约");
            s = QString("update coach_time set [1_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [1_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }

}



void order1::on_pushButton_1_2_clicked()
{
    QSqlQuery sql;
    QString s;
    QTime time = QTime::currentTime();
    int hour = time.hour();
    if(ui->pushButton_1_2->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<9){
                ui->pushButton_1_2->setText("预约成功");
                s= QString("update coach_time set [2_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [2_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_2->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_2->setText("预约");
            s = QString("update coach_time set [2_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [2_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }

}




void order1::on_pushButton_1_3_clicked()
{
    QTime time = QTime::currentTime();
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_3->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<10){
                ui->pushButton_1_2->setText("预约成功");
                s= QString("update coach_time set [2_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [2_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_3->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_3->setText("预约");
            s = QString("update coach_time set [3_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [3_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_1_4_clicked()
{

    QTime time = QTime::currentTime();
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_4->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<11){
                ui->pushButton_1_4->setText("预约成功");
                s= QString("update coach_time set [4_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [4_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_4->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_4->setText("预约");
            s = QString("update coach_time set [4_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [4_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}



void order1::on_pushButton_1_5_clicked()
{
    QTime time = QTime::currentTime();
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_5->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<14){
                ui->pushButton_1_5->setText("预约成功");
                s= QString("update coach_time set [5_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [5_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_5->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_5->setText("预约");
            s = QString("update coach_time set [5_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [5_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}



void order1::on_pushButton_1_6_clicked()
{
    QTime time = QTime::currentTime();
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_6->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<15){
                ui->pushButton_1_6->setText("预约成功");
                s= QString("update coach_time set [6_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [6_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_6->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_6->setText("预约");
            s = QString("update coach_time set [6_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [6_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_1_7_clicked()
{
    QTime time = QTime::currentTime();
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_7->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<16){
                ui->pushButton_1_7->setText("预约成功");
                s= QString("update coach_time set [7_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [7_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_7->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_7->setText("预约");
            s = QString("update coach_time set [7_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [7_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_1_8_clicked()
{
    QTime time = QTime::currentTime();
    int hour = time.hour();
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_1_8->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=1;i<=8;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>8){
            if(hour<17){
                ui->pushButton_1_8->setText("预约成功");
                s= QString("update coach_time set [8_1] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
                sql.exec(s);
                s=QString("update student_time set [8_1] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
                sql.exec(s);
            }
            else QMessageBox::information(this,"提示","您已超出预约时间");
        }
    }
    else if(ui->pushButton_1_8->text()=="预约成功"){
        ui->pushButton_1_8->setText("预约");
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定清空所有配置？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_1_8->setText("预约");
            s = QString("update coach_time set [8_1] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [8_1] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_1_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_1->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_1->setText("预约成功");
            s= QString("update coach_time set [1_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [1_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_1->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_1->setText("预约");
            s = QString("update coach_time set [1_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [1_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_2_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_2->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_2->setText("预约成功");
            s= QString("update coach_time set [2_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [2_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_2->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_2->setText("预约");
            s = QString("update coach_time set [2_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [2_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_3_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_3->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_3->setText("预约成功");
            s= QString("update coach_time set [3_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [3_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_3->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_3->setText("预约");
            s = QString("update coach_time set [3_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [3_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_4_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_4->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_4->setText("预约成功");
            s= QString("update coach_time set [4_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [4_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_4->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_4->setText("预约");
            s = QString("update coach_time set [4_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [4_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_5_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_5->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_5->setText("预约成功");
            s= QString("update coach_time set [5_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [5_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_5->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_5->setText("预约");
            s = QString("update coach_time set [5_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [5_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_6_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_6->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_6->setText("预约成功");
            s= QString("update coach_time set [6_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [6_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_6->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_6->setText("预约");
            s = QString("update coach_time set [6_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [6_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_7_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_7->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_7->setText("预约成功");
            s= QString("update coach_time set [7_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [7_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_7->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_7->setText("预约");
            s = QString("update coach_time set [7_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [7_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}

void order1::on_pushButton_2_8_clicked()
{
    QSqlQuery sql;
    QString s;
    if(ui->pushButton_2_8->text()=="预约"){
        int i;
        s= QString("select *from student_time where s_id='%1'").arg(suid);
        sql.exec(s);
        sql.next();
        for(i=9;i<=16;i++){
            if(sql.value(i).toInt()>0){
                QMessageBox::information(this,"提示","您当天已预约");
                break;
            }
        }
        if(i>16){
            ui->pushButton_2_8->setText("预约成功");
            s= QString("update coach_time set [8_2] = '%1' where c_id = '%2'").arg(suid).arg(index+1);
            sql.exec(s);
            s=QString("update student_time set [8_2] = '%1' where s_id = '%2'").arg(index+1).arg(suid);
            sql.exec(s);
        }
    }
    else if(ui->pushButton_2_8->text()=="预约成功"){
        QMessageBox *messageBox = new QMessageBox(this);
        messageBox->setIcon(QMessageBox::Warning);
        messageBox->setWindowTitle("友情提示");
        messageBox->setText("确定取消预约？");
        messageBox->addButton("取消", QMessageBox::RejectRole); //自定义取消按钮
        messageBox->addButton("确定", QMessageBox::AcceptRole); //自定义确定按钮
        if(messageBox->exec() == QDialog::Accepted) { //如果按下确定按钮，则执行清空所有配置
            ui->pushButton_2_8->setText("预约");
            s = QString("update coach_time set [8_2] = 0 where c_id = '%1'").arg(index+1);
            sql.exec(s);
            s = QString("update student_time set [8_2] = 0 where s_id = '%1'").arg(suid);
            sql.exec(s);

        }
    }
}
