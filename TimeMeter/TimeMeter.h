#ifndef TIMEMETER_H
#define TIMEMETER_H

#include "ProjectsBuffer.h"
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

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonAdd_clicked();

    void on_comboBoxProject_currentTextChanged(const QString &arg1);

private:
    void RefreshTableWiewOnStartTask();
    void RefreshTableWiewOnEndTask();
   QString secondsToString(qint64 seconds);
    Ui::TimeMeter *ui;
    QDateTime m_StartTime;
    QDateTime m_EndTime;
    ProjectsBuffer* m_ProjectsBuffer;
    int m_iColumnMax;
    int m_iRowMax;
};
#endif // TIMEMETER_H
