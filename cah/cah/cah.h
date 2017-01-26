#ifndef CAH_H
#define CAH_H

#include <QtWidgets/QMainWindow>
#include "gamegui.h"
#include "ui_cah.h"

class cah : public QMainWindow
{
    Q_OBJECT

public:
    cah(QWidget *parent = 0);
    ~cah();

private:
    Ui::cahClass ui;
};

#endif // CAH_H
