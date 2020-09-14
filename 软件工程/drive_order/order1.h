#ifndef ORDER1_H
#define ORDER1_H

#include <QDialog>

namespace Ui {
class order1;
}

class order1 : public QDialog
{
    Q_OBJECT

public:
    explicit order1(QWidget *parent = nullptr);
    ~order1();

private slots:
    void on_pushButton_1_1_clicked();


    void on_pushButton_1_2_clicked();

    void on_pushButton_1_3_clicked();

    void on_pushButton_1_4_clicked();

    void on_pushButton_1_5_clicked();

    void on_pushButton_1_6_clicked();

    void on_pushButton_1_7_clicked();

    void on_pushButton_1_8_clicked();

    void on_pushButton_2_1_clicked();

    void on_pushButton_2_2_clicked();

    void on_pushButton_2_3_clicked();

    void on_pushButton_2_4_clicked();

    void on_pushButton_2_5_clicked();

    void on_pushButton_2_6_clicked();

    void on_pushButton_2_7_clicked();

    void on_pushButton_2_8_clicked();

private:
    Ui::order1 *ui;
};

#endif // ORDER1_H
