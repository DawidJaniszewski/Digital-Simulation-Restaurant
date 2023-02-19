#include "ProjectsBuffer.h"

ProjectsBuffer::ProjectsBuffer()
{
}

bool ProjectsBuffer::AddProjektToList(const QString &ProjektNameString)
{
        m_ListOfProjects.push_back(ProjektNameString);
        m_ListOfVectorOfTasks.push_back(QVector<QString>());
        return true;
}

bool ProjectsBuffer::AddTaskToProject(const QString &ProjectNameString, const QString &TaskNameString)
{
    int iLengthOfList=m_ListOfProjects.length();
    bool bFindOfProject=false;

    for(int i=0;i<iLengthOfList;i++)
    {
        if(m_ListOfProjects.at(i) == ProjectNameString)
        {
            m_ListOfVectorOfTasks[i].push_back(TaskNameString);
            bFindOfProject=true;
            break;
        }
    }
    return bFindOfProject;
}

const QList<QString> &ProjectsBuffer::GetListOfProjects()
{
    return m_ListOfProjects;
}

const QVector<QString> &ProjectsBuffer::GetListOfTask(const QString &ProjectNameString)
{
    int iLengthOfList=m_ListOfProjects.length();
    bool bFindOfProject=false;
    for(int i=0;i<iLengthOfList;i++)
    {
        if(m_ListOfProjects.at(i) == ProjectNameString)
        {
            return m_ListOfVectorOfTasks[i];
        }
    }
}
