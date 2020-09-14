#ifndef WATING_H
#define WATING_H

#include <QWidget>

namespace Ui {
class wating;
}

class wating : public QWidget
{
    Q_OBJECT

public:
    explicit wating(QWidget *parent = nullptr);
    ~wating();

private:
    Ui::wating *ui;
};

#endif // WATING_H
