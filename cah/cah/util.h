#pragma once
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <iostream>
#include <fstream>
#include <string>

QVector<QString> readFile(QString);
void writeToConsole(QString, QTextStream*);