#include "ProjectViev.h"
#include "qlistwidget.h"
#include "ui_ProjectViev.h"

ProjectViev::ProjectViev(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectViev)
{
    ui->setupUi(this);
      //  ui->listViewProjects->addAction("test");
      //  ui->listViewProjects->Add
}

ProjectViev::~ProjectViev()
{
    delete ui;
}


void ProjectViev::on_pushButtonAdd_clicked()
{
    //Create Our QListWidge
    //Add Our Item To Our List
    ui->listWidgetProjects->addItem("itm");
    //ui->listWidgetProjects->
}

