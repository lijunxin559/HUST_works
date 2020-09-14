#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include"coach_deal.h"
#include"student_deal.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
    void loginReturnmainform();
private:
    Ui::login *ui;
    coach_deal *c_d;
    student_deal *s_d;
};

#endif // LOGIN_H
