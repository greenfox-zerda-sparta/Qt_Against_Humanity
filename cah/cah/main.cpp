#include "gamegui.h"
#include "gamelogic.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Client client;
    GameGui game;
    game.show();
    //Client client;

    return a.exec();
}
