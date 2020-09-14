#include "wating.h"
#include "ui_wating.h"



wating::wating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wating)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setFixedSize(200,200);
    background = new QFrame(this);
    background->setStyleSheet("background-color:#fff;border-radius:10px;");
    background->setGeometry(0, 50, 200, 150);
    label = new QLabel(background);
    label->setGeometry(0, 0, 200, 150);
    movie = new QMovie(":/Img/loding.gif");
    movie->setScaledSize(QSize(200,150));
    label->setScaledContents(true);
    label->setMovie(movie);
    movie->start();
    qDebug()<<"loading";
    connect(this,SIGNAL(loading()),this,SLOT(close()));

}

wating::~wating()
{
    delete ui;
}
