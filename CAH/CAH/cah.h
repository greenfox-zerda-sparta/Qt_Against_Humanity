#ifndef CAH_H
#define CAH_H

#include <QtWidgets/QMainWindow>
#include "ui_cah.h"

class CAH : public QMainWindow
{
    Q_OBJECT

public:
    CAH(QWidget *parent = 0);
    ~CAH();

private:
    Ui::CAHClass ui;
};

#endif // CAH_H
