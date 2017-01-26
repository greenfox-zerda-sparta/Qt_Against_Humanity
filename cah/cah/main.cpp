#include "cah.h"
#include "gamelogic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cah w;
    w.show();
    GameLogic gamelogic;
    return a.exec();
}
