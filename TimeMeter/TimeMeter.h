#ifndef TIMEMETER_H
#define TIMEMETER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TimeMeter; }
QT_END_NAMESPACE

class TimeMeter : public QMainWindow
{
    Q_OBJECT

public:
    TimeMeter(QWidget *parent = nullptr);
    ~TimeMeter();

private:
    Ui::TimeMeter *ui;
};
#endif // TIMEMETER_H
