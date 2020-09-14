#ifndef COACH_INFO_H
#define COACH_INFO_H

#include <QMainWindow>

namespace Ui {
class coach_info;
}

class coach_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit coach_info(QWidget *parent = nullptr);
    ~coach_info();

private:
    Ui::coach_info *ui;
};

#endif // COACH_INFO_H
