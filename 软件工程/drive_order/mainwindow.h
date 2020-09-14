#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <apply.h>
#include <login.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_apply_clicked();

    void showRequest();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    apply *a;
    login *l;
};
#endif // MAINWINDOW_H
