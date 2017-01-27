#include "gamegui.h"

GameGui::GameGui(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);

  answers = gamelogic.getAnswerCards();
  question = gamelogic.getQuestionCard();

  QPixmap pix_1("white_card.png");
  QPixmap pix_2("white_card.png");
  QPixmap pix_3("white_card.png");
  QPixmap pix_4("white_card.png");
  QPixmap pix_5("white_card.png");
  QPixmap pix_6("white_card.png");
  QPixmap pix_7("white_card.png");
  QPixmap pix_8("white_card.png");

  pixes.push_back(pix_1);
  pixes.push_back(pix_2);
  pixes.push_back(pix_3);
  pixes.push_back(pix_4);
  pixes.push_back(pix_5);
  pixes.push_back(pix_6);
  pixes.push_back(pix_7);
  pixes.push_back(pix_8);

  labelsOnPageOne.push_back(ui.label_pic_1);
  labelsOnPageOne.push_back(ui.label_pic_2);
  labelsOnPageOne.push_back(ui.label_pic_3);
  labelsOnPageOne.push_back(ui.label_pic_4);
  labelsOnPageOne.push_back(ui.label_pic_5);
  labelsOnPageOne.push_back(ui.label_pic_6);

  labelsOnPageTwo.push_back(ui.label_pic_19);
  labelsOnPageTwo.push_back(ui.label_pic_20);
  labelsOnPageTwo.push_back(ui.label_pic_21);
  labelsOnPageTwo.push_back(ui.label_pic_22);
  labelsOnPageTwo.push_back(ui.label_pic_23);
  labelsOnPageTwo.push_back(ui.label_pic_24);
  labelsOnPageTwo.push_back(ui.label_pic_25);
  labelsOnPageTwo.push_back(ui.label_pic_26);

  checkBoxes.push_back(ui.checkBox_19);
  checkBoxes.push_back(ui.checkBox_20);
  checkBoxes.push_back(ui.checkBox_21);
  checkBoxes.push_back(ui.checkBox_22);
  checkBoxes.push_back(ui.checkBox_23);
  checkBoxes.push_back(ui.checkBox_24);

  renderPageOne();

  connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onSubmitClicked()));
  connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(giveNewCard()));
  //connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(showSubmitPage()));
}

GameGui::~GameGui()
{

}

void GameGui::renderPageOne()
{
  /*QVector<QString> answers = gamelogic.getAnswerCards();*/
  /*QVector<QPixmap> pixes(6);
  QPixmap pix_1("white_card.png");
  QPixmap pix_2("white_card.png");
  QPixmap pix_3("white_card.png");
  QPixmap pix_4("white_card.png");
  QPixmap pix_5("white_card.png");
  QPixmap pix_6("white_card.png");

  pixes << pix_1 << pix_2 << pix_3 << pix_4 << pix_5 << pix_6;*/

  /*QVector<QLabel> labelsOnPageOne(6);
  labelsOnPageOne << ui.label_pic_1 << ui.label_pic_2 << ui.label_pic_3 << ui.label_pic_4 << ui.label_pic_5 << ui.label_pic_6;*/

  
  for (int i = 0; i < pixes.size()-2; ++i)
  {
    QPainter* painter = new QPainter(&pixes[i]);
    painter->setPen(Qt::darkCyan);
    painter->setFont(QFont("Times", 12, QFont::Bold));
    painter->drawText(QRect(10, 10, 120, 131), answers[i]);
    labelsOnPageOne[i]->setPixmap(pixes[i]);
    delete painter;
  }

 /* QPainter* painter_1 = new QPainter(&pix_1);
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
  ui.label_pic_6->setPixmap(pix_6);*/

  /*QString question = gamelogic.getQuestionCard();*/
  QPixmap blackPix("black_card.png");

  QPainter* painter_7 = new QPainter(&blackPix);
  painter_7->setPen(Qt::white);
  painter_7->setFont(QFont("Times", 12, QFont::Bold));
  painter_7->drawText(QRect(10, 10, 140, 185), question);
  ui.label_pic_black->setPixmap(blackPix);
  delete painter_7;

  /*delete painter_1;
  delete painter_2;
  delete painter_3;
  delete painter_4;
  delete painter_5;
  delete painter_6;*/
}

//void GameGui::renderPageTwo()
//{
//  QPainter* painter;
//  /*for (int i = 0; i < pixes.size(); ++i)
//  {
//    painter = new QPainter(&pixes[i]);
//    painter->setPen(Qt::darkCyan);
//    painter->setFont(QFont("Times", 12, QFont::Bold));
//    painter->drawText(QRect(10, 10, 120, 131), answers[0]);
//    labelsOnPageTwo[i]->setPixmap(pixes[i]);
//    delete painter;
//  }*/
//
//  QPixmap blackPix("black_card.png");
//
//  QPainter* painter_7 = new QPainter(&blackPix);
//  painter_7->setPen(Qt::white);
//  painter_7->setFont(QFont("Times", 12, QFont::Bold));
//  painter_7->drawText(QRect(10, 10, 140, 185), question);
//  ui.label_pic_black_3->setPixmap(blackPix);
//  delete painter_7;
//
//}

void GameGui::onSubmitClicked()
{
  ui.stackedWidget->setCurrentWidget(ui.page_2);

  QPixmap blackPix("black_card.png");

  QPainter* painter_7 = new QPainter(&blackPix);
  painter_7->setPen(Qt::white);
  painter_7->setFont(QFont("Times", 12, QFont::Bold));
  painter_7->drawText(QRect(10, 10, 140, 185), question);
  ui.label_pic_black_3->setPixmap(blackPix);
  delete painter_7;

  for (int i = 0; i < pixes.size()-2; ++i)
  {
      QPainter* painter = new QPainter(&pixes[i]);
      painter->setPen(Qt::darkCyan);
      painter->setFont(QFont("Times", 12, QFont::Bold));
      /*painter->drawText(QRect(10, 10, 120, 131), answers[i]);*/
      if (checkBoxes[i]->isChecked())
      {
        gamelogic.run(i);
        painter->drawText(QRect(10, 10, 120, 131), answers[i]);
      }
      labelsOnPageTwo[i]->setPixmap(pixes[i]);
      delete painter;
  }

    QPainter* painter = new QPainter(&pixes[6]);
    painter->setPen(Qt::darkCyan);
    painter->setFont(QFont("Times", 12, QFont::Bold));
    if (ui.checkBox_1->isChecked())
    {
      /*gamelogic.run(0);*/
      painter->drawText(QRect(10, 10, 120, 131), answers[0]);
    }
    if (ui.checkBox_2->isChecked())
    {
      /*gamelogic.run(1);*/
      painter->drawText(QRect(10, 10, 120, 131), answers[1]);
    }
    if (ui.checkBox_3->isChecked())
    {
      /*gamelogic.run(2);*/
      painter->drawText(QRect(10, 10, 120, 131), answers[2]);
    }
    if (ui.checkBox_4->isChecked())
    {
      /*gamelogic.run(3);*/
      painter->drawText(QRect(10, 10, 120, 131), answers[3]);
    }
    if (ui.checkBox_5->isChecked())
    {
      /*gamelogic.run(4);*/
      painter->drawText(QRect(10, 10, 120, 131), answers[4]);
    }
    if (ui.checkBox_6->isChecked())
    {
      /*gamelogic.run(5);*/
      painter->drawText(QRect(10, 10, 120, 131), answers[5]);
    }
    labelsOnPageTwo[6]->setPixmap(pixes[6]);
    delete painter;



    //if (ui.checkBox_1->isChecked())
    //{
    //  gamelogic.run(0);
    //  /*ui.checkBox_1->setCheckState(Qt::Unchecked);*/
    //}
    //if (ui.checkBox_2->isChecked())
    //{
    //  gamelogic.run(1);
    //  /*ui.checkBox_2->setCheckState(Qt::Unchecked);*/
    //}
    //if (ui.checkBox_3->isChecked())
    //{
    //  gamelogic.run(2);
    //  /*ui.checkBox_3->setCheckState(Qt::Unchecked);*/
    //}
    //if (ui.checkBox_4->isChecked())
    //{
    //  gamelogic.run(3);
    //  /*ui.checkBox_4->setCheckState(Qt::Unchecked);*/
    //}
    //if (ui.checkBox_5->isChecked())
    //{
    //  gamelogic.run(4);
    //  /*ui.checkBox_5->setCheckState(Qt::Unchecked);*/
    //}
    //if (ui.checkBox_6->isChecked())
    //{
    //  gamelogic.run(5);
    //  /*ui.checkBox_6->setCheckState(Qt::Unchecked);*/
    //}
  /*renderPageTwo();*/
}

void GameGui::giveNewCard()
{
  if (ui.checkBox_1->isChecked())
  {
    gamelogic.run(0);
    ui.checkBox_1->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_2->isChecked())
  {
    gamelogic.run(1);
    ui.checkBox_2->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_3->isChecked())
  {
    gamelogic.run(2);
    ui.checkBox_3->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_4->isChecked())
  {
    gamelogic.run(3);
    ui.checkBox_4->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_5->isChecked())
  {
    gamelogic.run(4);
    ui.checkBox_5->setCheckState(Qt::Unchecked);
  } else if (ui.checkBox_6->isChecked())
  {
    gamelogic.run(5);
    ui.checkBox_6->setCheckState(Qt::Unchecked);
  }
  renderPageOne();
}

//void GameGui::paintEvent(QPaintEvent *e)
//{
//  QPainter painter(this);
//  painter.setPen(Qt::blue);
//  painter.setFont(QFont("Arial", 30));
//  painter.drawText(rect(), Qt::AlignTop, "Juli");
//  
//}
