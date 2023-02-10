#include "TimeMeter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeMeter w;

    w.show();
    return a.exec();
}
