#ifndef PROJEKTSBUFFER_H
#define PROJEKTSBUFFER_H
#include <QString>
#include <QList>
#include <QVector>


class ProjektsBuffer
{
public:
    ProjektsBuffer();
    bool CheckIfTheProjektIsListed(QString ProjectNameString);
    bool AddProjektToList(QString ProjektNameString);
    QList<QString> GetListOfProjects();
    QList<QString> GetListOfTask(QString ProjectNameString);

private:





    QList<QString> m_ListOfProjects;
    QVector<QString> m_VectorOfTasks;


};

#endif // PROJEKTSBUFFER_H
