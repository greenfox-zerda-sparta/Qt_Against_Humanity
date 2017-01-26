#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include "ui_gamegui.h"

class GameGui : public QWidget
{
    Q_OBJECT

public:
    GameGui(QWidget *parent = 0);
    ~GameGui();

private slots:
    void paintEvent(QPaintEvent *e);

private:
    Ui::GameGui ui;
    QVector<QWidget> m_Cards;
    QVector<QWidget> m_CheckBox;
    
};

#endif // GAMEGUI_H
