#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QStackedWidget>
#include "ui_gamegui.h"
#include "gamelogic.h" 

class GameGui : public QWidget
{
    Q_OBJECT

public:
    GameGui(QWidget *parent = 0);
    ~GameGui();
    void renderPageOne();
    /*void renderPageTwo();*/

private slots:
    /*void paintEvent(QPaintEvent *e);*/
    void onSubmitClicked();
    void giveNewCard();

private:
    Ui::GameGui ui;
    GameLogic gamelogic;
    QVector<QString> answers;
    QString question;
    QVector<QPixmap> pixes;
    QVector<QLabel*> labelsOnPageOne;
    QVector<QLabel*> labelsOnPageTwo;
    QVector<QCheckBox*> checkBoxes;
};

#endif // GAMEGUI_H
