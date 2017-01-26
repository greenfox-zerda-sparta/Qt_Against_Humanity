#include "gamegui.h"

GameGui::GameGui(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  QPixmap pix("white_card.png");
  QLabel *label = new QLabel(this);
  label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
  //label->setPixmap(pix);
  //m_Cards << ui.card_1 << ui.card_2 << ui.card_3 << ui.card_3 << ui.card_4 << ui.card_5 << ui.card_6;
  ui.card_1->setStyleSheet("background-image: ./white_card.png");
  ui.label_pic_1->setPixmap(pix);
  ui.label_pic_2->setPixmap(pix);
  ui.label_pic_3->setPixmap(pix);
  ui.label_pic_4->setPixmap(pix);
  ui.label_pic_5->setPixmap(pix);
  ui.label_pic_6->setPixmap(pix);

  QPixmap blackPix("black_card.png");
  ui.label_pic_black->setPixmap(blackPix);
}

GameGui::~GameGui()
{

}

void GameGui::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(rect(), Qt::AlignTop, "Juli");
  
}
