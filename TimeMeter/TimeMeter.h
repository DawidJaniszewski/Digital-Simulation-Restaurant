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

    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
   QString secondsToString(qint64 seconds);
    Ui::TimeMeter *ui;
    QDateTime m_oStartTime;
    QDateTime m_oEndTime;
};
#endif // TIMEMETER_H
