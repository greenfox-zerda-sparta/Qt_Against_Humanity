#include "cah.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cah w;
    w.show();
    std::cout << "kiscic�k";
    return a.exec();
}
