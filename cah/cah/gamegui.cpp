#include "gamegui.h"

GameGui::GameGui(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  //m_Cards << ui.card_1 << ui.card_2 << ui.card_3 << ui.card_3 << ui.card_4 << ui.card_5 << ui.card_6;
  ui.card_1->setStyleSheet("background-image: ./white_card.png");
}

GameGui::~GameGui()
{

}

void GameGui::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(rect(), Qt::AlignCenter, "Qt");
  
}
