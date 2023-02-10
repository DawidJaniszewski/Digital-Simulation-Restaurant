#ifndef TIMEMETER_H
#define TIMEMETER_H

#include <QMainWindow>
#include <QDateTime>


QT_BEGIN_NAMESPACE
namespace Ui { class TimeMeter; }
QT_END_NAMESPACE

class TimeMeter : public QMainWindow
{
    Q_OBJECT

public:
    TimeMeter(QWidget *parent = nullptr);
    ~TimeMeter();

private slots:
    void on_start_clicked();

    void on_stop_clicked();

    //QString on_Time_control_textChanged(const QString &arg1);

private:
   QString secondsToString(qint64 seconds);
    //int test();
    Ui::TimeMeter *ui;
    QDateTime m_oStartTime;
    QDateTime m_oEndTime;
};
#endif // TIMEMETER_H
