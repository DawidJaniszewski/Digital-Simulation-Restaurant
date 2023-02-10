#include "TimeMeter.h"
#include "./ui_TimeMeter.h"

TimeMeter::TimeMeter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeMeter)
{
    ui->setupUi(this);
}

TimeMeter::~TimeMeter()
{
    delete ui;
}

