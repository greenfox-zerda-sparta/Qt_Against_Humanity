#include "util.h"

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