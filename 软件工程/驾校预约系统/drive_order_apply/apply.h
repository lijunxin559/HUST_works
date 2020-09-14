#ifndef APPLY_H
#define APPLY_H

#include <QMainWindow>

namespace Ui {
class apply;
}

class apply : public QMainWindow
{
    Q_OBJECT

public:
    explicit apply(QWidget *parent = nullptr);
    ~apply();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

signals:
    void ApplyReturnmainform();

private:
    Ui::apply *ui;

};

#endif // APPLY_H
