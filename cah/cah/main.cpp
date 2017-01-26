#include "cah.h"
#include "gamelogic.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*cah w;
    w.show();*/
    GameGui game;
    game.show();
//<<<<<<< HEAD
//    Client client;
//    std::cout << "kiscicák";
//=======
//    GameLogic gamelogic;
//>>>>>>> master
    return a.exec();
}
