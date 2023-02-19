#ifndef PROJECTVIEV_H
#define PROJECTVIEV_H

#include <QDialog>

namespace Ui {
class ProjectViev;
}

class ProjectViev : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectViev(QWidget *parent = nullptr);
    ~ProjectViev();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonAdd_clicked();

private:
    Ui::ProjectViev *ui;
};

#endif // PROJECTVIEV_H
