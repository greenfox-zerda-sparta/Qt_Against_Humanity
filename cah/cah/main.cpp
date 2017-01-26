#include "gamegui.h"
#include "gamelogic.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Client.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Client client;
    GameGui game;
    game.show();
    QObject* object = 0;
    ServerConnection* serverConnection = new ServerConnection(object, "127.0.0.1", 1234);
    UiAdapter* uiAdapter = new UiAdapter;
    Game newGame(serverConnection, uiAdapter);
    //Client client;

    return a.exec();
}
