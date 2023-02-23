#include "TimeMeter.h"
#include "./ui_TimeMeter.h"
#include "ProjectViev.h"
#include <QtWidgets>
#include <QThread>
const QString DATE_FORMAT="yyyy.MM.dd HH:mm";
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
    ui->comboBoxProject->addItems(m_ProjectsBuffer->GetListOfProjects());
    ui->comboBoxTask->addItems(m_ProjectsBuffer->GetListOfTask(ui->comboBoxProject->currentText()));
    m_iColumnMax=5;
    m_iRowMax=0;
    ui->tableWidgetSummary->horizontalScrollBar()->hide();
}


QString TimeMeter::secondsToString(qint64 seconds)
{
  const qint64 DAY = 86400;
  QTime time = QTime(0,0).addSecs(seconds % DAY);
  return QString("%2:%3:%4").arg(time.hour()).arg(time.minute()).arg(time.second());
}


TimeMeter::~TimeMeter()
{
    delete ui;
}



void TimeMeter::on_pushButtonStop_clicked()
{
    m_EndTime=QDateTime::currentDateTime();
    RefreshTableWiewOnEndTask();
        m_iRowMax++;
}

void TimeMeter::on_pushButtonStart_clicked()
{
    m_StartTime=QDateTime::currentDateTime();
    ui->Time_controlTemporary->setText(m_StartTime.toString(DATE_FORMAT));


    RefreshTableWiewOnStartTask();

}

void TimeMeter::on_pushButtonAdd_clicked()
{
    ProjectViev ProjectViewWindow(m_ProjectsBuffer);
    ProjectViewWindow.setModal(true);
    ProjectViewWindow.exec();
}


void TimeMeter::on_comboBoxProject_currentTextChanged(const QString &arg1)
{
    ui->comboBoxTask->clear();
    ui->comboBoxTask->addItems(m_ProjectsBuffer->GetListOfTask(arg1));
}

void TimeMeter::RefreshTableWiewOnStartTask()
{
    ui->tableWidgetSummary->insertRow(ui->tableWidgetSummary->rowCount());
    QVector<QTableWidgetItem*> TableVectorWithColumn;
    TableVectorWithColumn.push_back( new QTableWidgetItem(ui->comboBoxProject->currentText()));
    TableVectorWithColumn.push_back( new QTableWidgetItem(ui->comboBoxTask->currentText()));
    TableVectorWithColumn.push_back( new QTableWidgetItem(m_StartTime.toString(DATE_FORMAT)));
   for(int i=0;i<TableVectorWithColumn.size();i++)
   {
       ui->tableWidgetSummary->setItem(m_iRowMax, i, TableVectorWithColumn[i]);
   }
}

void TimeMeter::RefreshTableWiewOnEndTask()
{
    int test=ui->tableWidgetSummary->columnCount();
    ui->tableWidgetSummary->setItem(m_iRowMax, ui->tableWidgetSummary->columnCount()-2,new QTableWidgetItem( m_EndTime.toString(DATE_FORMAT)));
    QString TimeLength=secondsToString(m_StartTime.secsTo(m_EndTime));
    ui->tableWidgetSummary->setItem(m_iRowMax, ui->tableWidgetSummary->columnCount()-1,new QTableWidgetItem(TimeLength));
}

