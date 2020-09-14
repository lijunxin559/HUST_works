#ifndef STUDENT_DEAL_H
#define STUDENT_DEAL_H

#include <QTabWidget>
#include"order1.h"

namespace Ui {
class student_deal;
}

class student_deal : public QTabWidget
{
    Q_OBJECT

public:
    explicit student_deal(QWidget *parent = nullptr);
    ~student_deal();


private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_student_deal_currentChanged(int index);

private:
    Ui::student_deal *ui;
    order1 *dlg;
};

#endif // STUDENT_DEAL_H
