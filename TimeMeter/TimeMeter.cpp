#include "TimeMeter.h"
#include "./ui_TimeMeter.h"
#include <QtWidgets>

TimeMeter::TimeMeter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeMeter)
{
    ui->setupUi(this);
}


QString TimeMeter::secondsToString(qint64 seconds)
{
  const qint64 DAY = 86400;
  QTime time = QTime(0,0).addSecs(seconds % DAY);
  return QString("%2 hours, %3 minutes, %4 seconds").arg(time.hour()).arg(time.minute()).arg(time.second());
}


TimeMeter::~TimeMeter()
{
    delete ui;
}

void TimeMeter::on_startButton_clicked()
{
    m_oStartTime=QDateTime::currentDateTime();
    ui->Time_controlTemporary->setText(m_oStartTime.toString("yyyy.MM.dd//HH:mm"));
}


void TimeMeter::on_stopButton_clicked()
{
    m_oEndTime=QDateTime::currentDateTime();
    QString tst=secondsToString(m_oStartTime.secsTo(m_oEndTime));
    ui->Time_controlTemporary->setText(tst);

}

