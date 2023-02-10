#include "TimeMeter.h"
#include "./ui_TimeMeter.h"

TimeMeter::TimeMeter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeMeter)
{
    ui->setupUi(this);
}


QString TimeMeter::secondsToString(qint64 seconds)
{
  const qint64 DAY = 86400;
  qint64 days = seconds / DAY;
  QTime t = QTime(0,0).addSecs(seconds % DAY);
  return QString("%1 days, %2 hours, %3 minutes, %4 seconds")
    .arg(days).arg(t.hour()).arg(t.minute()).arg(t.second());
}


TimeMeter::~TimeMeter()
{
    delete ui;
}


void TimeMeter::on_start_clicked()
{
    m_oStartTime=QDateTime::currentDateTime();
    ui->textEdit->setText(m_oStartTime.toString("yyyy.MM.dd//HH:mm"));
}


void TimeMeter::on_stop_clicked()
{
    qint64 tst1=5;
//   secondsToString(tst1);
    m_oEndTime=QDateTime::currentDateTime();
    //on_Time_control_textChanged(secondsToString(m_oStartTime.secsTo(m_oEndTime)));
    QString tst=secondsToString(m_oStartTime.secsTo(m_oEndTime));
    ui->Time_control->setText(tst);
}


//void TimeMeter::on_Time_control_textChanged(const QString &arg1)
//{
  //ui->Time_control->setText(arg1);
//}

