#include "ProjectViev.h"
#include "qlistwidget.h"
#include "ui_ProjectViev.h"

ProjectViev::ProjectViev(ProjectsBuffer* ProjectsBuffer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectViev)
{
    ui->setupUi(this);
    m_ProjectsBuffer=ProjectsBuffer;
    QList<QString> listOfProject =m_ProjectsBuffer->GetListOfProjects();
    for(int i=0;i<listOfProject.count();i++)
    {
        ui->listWidgetProjects->addItem(listOfProject[i]);
    }
}

ProjectViev::~ProjectViev()
{
    delete ui;
}


void ProjectViev::on_pushButtonAdd_clicked()
{

}


void ProjectViev::on_listWidgetProjects_itemPressed(QListWidgetItem *item)
{
    ui->listWidgetTasks->clear();
    QVector<QString> vectorOfTasks =m_ProjectsBuffer->GetListOfTask(item->text());
    int iLengthOfVector=vectorOfTasks.length();
    if(iLengthOfVector>0)
    {
        for(int i=0;i<iLengthOfVector;i++)
        {
           ui->listWidgetTasks->addItem(vectorOfTasks[i]);
        }
    }
}


void ProjectViev::on_pushButtonUp_clicked()
{
    m_ProjectsBuffer->ChangePositionOfProject(ui->listWidgetProjects->selectedItems().at(0)->text(), ProjectIndex::eDecrement);
    QList<QString> listOfProject =m_ProjectsBuffer->GetListOfProjects();
     ui->listWidgetProjects->clear();
    for(int i=0;i<listOfProject.count();i++)
    {
        ui->listWidgetProjects->addItem(listOfProject[i]);
    }
}


void ProjectViev::on_pushButtonDelete_2_clicked()
{
    m_ProjectsBuffer->ChangePositionOfProject(ui->listWidgetProjects->selectedItems().at(0)->text(), ProjectIndex::eIncrement);
    QList<QString> listOfProject =m_ProjectsBuffer->GetListOfProjects();
     ui->listWidgetProjects->clear();
    for(int i=0;i<listOfProject.count();i++)
    {
        ui->listWidgetProjects->addItem(listOfProject[i]);
    }
}

