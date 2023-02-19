#ifndef PROJEKTSBUFFER_H
#define PROJEKTSBUFFER_H
#include <QString>
#include <QList>
#include <QVector>

enum class ProjectIndex{
    eIncrement,
    eDecrement
};

class ProjectsBuffer
{
public:
    ProjectsBuffer();

    bool AddProjektToList(const QString& ProjectNameString);
    bool AddTaskToProject(const QString& ProjectNameString, const QString& TaskNameString);
    const QList<QString>& GetListOfProjects();
    const QVector<QString>& GetListOfTask(const QString& ProjectNameString);
    bool ChangePositionOfProject(const QString& ProjectNameString, ProjectIndex Operation);


private:
    int GetIdOfProject(const QString& ProjectNameString);
    bool CheckIfTheProjektIsListed(const QString& ProjectNameString);



    QList<QString> m_ListOfProjects;
    QList<QVector<QString>> m_ListOfVectorOfTasks;


};

#endif // PROJEKTSBUFFER_H
