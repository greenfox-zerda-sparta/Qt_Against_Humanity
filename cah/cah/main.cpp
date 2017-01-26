#include <QtWidgets/QApplication>
#include <iostream>
#include "gamegui.h"
#include "Client.h"
#include "gamelogic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //cah w;
    //w.show();
    //Client client;
    GameGui game;
    game.show();
    return a.exec();
}
