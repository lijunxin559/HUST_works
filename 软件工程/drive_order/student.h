#ifndef STUDENT_H
#define STUDENT_H

#include <QTabWidget>

namespace Ui {
class student;
}

class student : public QTabWidget
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    ~student();

private:
    Ui::student *ui;
};

#endif // STUDENT_H
