#include "gamegui.h"
#include "gamelogic.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameGui w;
    w.show();
    Client client;
    std::cout << "kiscicák";
    //GameLogic gamelogic;
    return a.exec();
}
