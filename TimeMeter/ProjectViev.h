#ifndef PROJECTVIEV_H
#define PROJECTVIEV_H

#include "ProjectsBuffer.h"
#include "qlistwidget.h"
#include <QDialog>

namespace Ui {
class ProjectViev;
}

class ProjectViev : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectViev(ProjectsBuffer* ProjectsBuffer,QWidget *parent = nullptr);
    ~ProjectViev();

private slots:

    void on_pushButtonAdd_clicked();

    void on_listWidgetProjects_itemPressed(QListWidgetItem *item);

    void on_pushButtonUp_clicked();

    void on_pushButtonDelete_2_clicked();

private:
    Ui::ProjectViev *ui;
    ProjectsBuffer* m_ProjectsBuffer;
};

#endif // PROJECTVIEV_H
