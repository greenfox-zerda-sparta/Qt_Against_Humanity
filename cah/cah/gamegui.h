#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include "ui_gamegui.h"
#include "gamelogic.h" 

class GameGui : public QWidget
{
    Q_OBJECT

public:
    GameGui(QWidget *parent = 0);
    ~GameGui();

private slots:
    void paintEvent(QPaintEvent *e);
    //void showSubmitPage();
    void render();
    void onSubmitClicked();

private:
    Ui::GameGui ui;
    GameLogic gamelogic;
};

#endif // GAMEGUI_H
