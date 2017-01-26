#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include "gamelogic.h"
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
    void render();

private:
    Ui::GameGui ui;
    QVector<QWidget*> m_Cards;
    QVector<QWidget*> m_CheckBox;
    GameLogic gamelogic;

private slots:
  void onSubmitClicked();
    //void showSubmitPage();
    void render();

private:
    Ui::GameGui ui;
    GameLogic gamelogic;
};

#endif // GAMEGUI_H
