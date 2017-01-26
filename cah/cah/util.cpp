#include "util.h"
#include <QGlobal.h>
#include <QTime>

QVector<QString> readFile(QString fileName)
{
  QVector<QString> content;
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      
    } 
  QTextStream in(&file);
  while (!in.atEnd())
  {
    QString line = in.readLine();
    content.push_back(line);
  }  
  return content;
}

void writeToConsole(QString content, QTextStream* _cout)
{
  *_cout << content << endl;
  _cout->flush();
}

int generateRandomNumber(QVector<QString>& vector) {
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
  return qrand() % (vector.size() - 1);
}