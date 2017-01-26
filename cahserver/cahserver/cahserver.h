#ifndef CAHSERVER_H
#define CAHSERVER_H

#include <QtWidgets/QMainWindow>
#include "ui_cahserver.h"

class cahserver : public QMainWindow
{
	Q_OBJECT

public:
	cahserver(QWidget *parent = 0);
	~cahserver();

private:
	Ui::cahserverClass ui;
};

#endif // CAHSERVER_H
