#include "cah.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cah w;
    w.show();
    return a.exec();
}
