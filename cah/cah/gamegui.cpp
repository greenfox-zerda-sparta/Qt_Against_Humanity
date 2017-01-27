#include "gamegui.h"

GameGui::GameGui(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  
  //render();

  connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onSubmitClicked()));

  //connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(showSubmitPage()));
}

GameGui::~GameGui()
{

}

void GameGui::render(GameLogic& logic)
{
  QVector<QString> answers = logic.getAnswerCards();
  QPixmap pix_1("white_card.png");
  QPixmap pix_2("white_card.png");
  QPixmap pix_3("white_card.png");
  QPixmap pix_4("white_card.png");
  QPixmap pix_5("white_card.png");
  QPixmap pix_6("white_card.png");

  QPainter* painter_1 = new QPainter(&pix_1);
  painter_1->setPen(Qt::darkCyan);
  painter_1->setFont(QFont("Times", 12, QFont::Bold));
  painter_1->drawText(QRect(10, 10, 120, 131), answers[0]);
  ui.label_pic_1->setPixmap(pix_1);

  QPainter* painter_2 = new QPainter(&pix_2);
  painter_2->setPen(Qt::darkCyan);
  painter_2->setFont(QFont("Times", 12, QFont::Bold));
  painter_2->drawText(QRect(10, 10, 120, 131), answers[1]);
  ui.label_pic_2->setPixmap(pix_2);

  QPainter* painter_3 = new QPainter(&pix_3);
  painter_3->setPen(Qt::darkCyan);
  painter_3->setFont(QFont("Times", 12, QFont::Bold));
  painter_3->drawText(QRect(10, 10, 120, 131), answers[2]);
  ui.label_pic_3->setPixmap(pix_3);

  QPainter* painter_4 = new QPainter(&pix_4);
  painter_4->setPen(Qt::darkCyan);
  painter_4->setFont(QFont("Times", 12, QFont::Bold));
  painter_4->drawText(QRect(10, 10, 120, 131), answers[3]);
  ui.label_pic_4->setPixmap(pix_4);

  QPainter* painter_5 = new QPainter(&pix_5);
  painter_5->setPen(Qt::darkCyan);
  painter_5->setFont(QFont("Times", 12, QFont::Bold));
  painter_5->drawText(QRect(10, 10, 120, 131), answers[4]);
  ui.label_pic_5->setPixmap(pix_5);

  QPainter* painter_6 = new QPainter(&pix_6);
  painter_6->setPen(Qt::darkCyan);
  painter_6->setFont(QFont("Times", 12, QFont::Bold));
  painter_6->drawText(QRect(10, 10, 120, 131), answers[5]);
  ui.label_pic_6->setPixmap(pix_6);

  QString question = logic.getQuestionCard();
  QPixmap blackPix("black_card.png");

  QPainter* painter_7 = new QPainter(&blackPix);
  painter_7->setPen(Qt::white);
  painter_7->setFont(QFont("Times", 12, QFont::Bold));
  painter_7->drawText(QRect(10, 10, 140, 185), question);
  ui.label_pic_black->setPixmap(blackPix);

  delete painter_1;
  delete painter_2;
  delete painter_3;
  delete painter_4;
  delete painter_5;
  delete painter_6;
  delete painter_7;
}

void GameGui::onSubmitClicked()
{
  if (ui.checkBox_1->isChecked())
  {
    //logic.run(0);
    ui.checkBox_1->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_2->isChecked())
  {
    //logic.run(1);
    ui.checkBox_2->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_3->isChecked())
  {
    //logic.run(2);
    ui.checkBox_3->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_4->isChecked())
  {
    //logic.run(3);
    ui.checkBox_4->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_5->isChecked())
  {
    //logic.run(4);
    ui.checkBox_5->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_6->isChecked())
  {
    //logic.run(5);
    ui.checkBox_6->setCheckState(Qt::Unchecked);
  }
  //render();
}

//void GameGui::showSubmitPage()
//{
//  ui.stackedWidget->setCurrentWidget(ui.submitPage);
//}

void GameGui::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setFont(QFont("Arial", 30));
  painter.drawText(rect(), Qt::AlignTop, "Juli");
  
}
