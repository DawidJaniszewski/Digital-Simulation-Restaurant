#include "TimeMeter.h"
#include "./ui_TimeMeter.h"
#include "ProjectViev.h"
#include <QtWidgets>

TimeMeter::TimeMeter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeMeter)
{
    ui->setupUi(this);
    m_ProjectsBuffer = new ProjectsBuffer();
    m_ProjectsBuffer->AddProjektToList("Test Project1");
    m_ProjectsBuffer->AddProjektToList("Test Project2");
    m_ProjectsBuffer->AddProjektToList("Test Project3");
    m_ProjectsBuffer->AddTaskToProject("Test Project1", "task1");
    m_ProjectsBuffer->AddTaskToProject("Test Project1", "task2");
    m_ProjectsBuffer->AddTaskToProject("Test Project1", "task3");
    m_ProjectsBuffer->AddTaskToProject("Test Project2", "task3");
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



void TimeMeter::on_pushButtonStop_clicked()
{
    m_oEndTime=QDateTime::currentDateTime();
    QString tst=secondsToString(m_oStartTime.secsTo(m_oEndTime));
    ui->Time_controlTemporary->setText(tst);
}

void TimeMeter::on_pushButtonStart_clicked()
{
    m_oStartTime=QDateTime::currentDateTime();
    ui->Time_controlTemporary->setText(m_oStartTime.toString("yyyy.MM.dd//HH:mm"));
}

void TimeMeter::on_pushButtonAdd_clicked()
{
    ProjectViev ProjectViewWindow(m_ProjectsBuffer);
    ProjectViewWindow.setModal(true);
    ProjectViewWindow.exec();
}

