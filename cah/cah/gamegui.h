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
    void render(GameLogic&);
    Ui::GameGui ui;
    ~GameGui();

private slots:
    void paintEvent(QPaintEvent *e);
    //void showSubmitPage();
    
    void onSubmitClicked();

private:
    
    ////GameLogic gamelogic;
};

#endif // GAMEGUI_H
