#include "cah.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cah w;
    w.show();
    Client client;
    std::cout << "kiscicák";
    return a.exec();
}
