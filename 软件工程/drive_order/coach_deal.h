#ifndef COACH_DEAL_H
#define COACH_DEAL_H

#include <QTabWidget>

namespace Ui {
class coach_deal;
}

class coach_deal : public QTabWidget
{
    Q_OBJECT

public:
    explicit coach_deal(QWidget *parent = nullptr);
    ~coach_deal();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

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

    void on_pushButton_2_clicked();

private:
    Ui::coach_deal *ui;
};

#endif // COACH_DEAL_H
