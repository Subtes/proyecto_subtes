#ifndef BOARDMAC_H
#define BOARDMAC_H

#include <QMainWindow>

namespace Ui {
class BoardMac;
}

class BoardMac : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardMac(QWidget *parent = 0);
    ~BoardMac();

private:
    Ui::BoardMac *ui;
};

#endif // BOARDMAC_H
