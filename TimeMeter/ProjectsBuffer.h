#ifndef PROJEKTSBUFFER_H
#define PROJEKTSBUFFER_H
#include <QString>
#include <QList>
#include <QVector>


class ProjectsBuffer
{
public:
    ProjectsBuffer();
    bool CheckIfTheProjektIsListed(const QString& ProjectNameString);
    bool AddProjektToList(const QString& ProjectNameString);
    bool AddTaskToProject(const QString& ProjectNameString, const QString& TaskNameString);
    const QList<QString>& GetListOfProjects();
    const QVector<QString>& GetListOfTask(const QString& ProjectNameString);

private:





    QList<QString> m_ListOfProjects;
    QList<QVector<QString>> m_ListOfVectorOfTasks;


};

#endif // PROJEKTSBUFFER_H
