#include "mainwindow.h"
#include <QApplication>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPushButton>

bool OpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("sjj");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("root");                               //登录用户
    db.setPassword("687099");                              //密码
    db.open();                                   //打开数据库
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString("驾校预约"));
    if(!OpenDatabase())
        return 1;

    w.show();
    return a.exec();
}

