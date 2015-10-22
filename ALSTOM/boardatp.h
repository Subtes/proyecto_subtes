#ifndef BOARDATP_H
#define BOARDATP_H

#include <QMainWindow>

namespace Ui {
class BoardAtp;
}

class BoardAtp : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardAtp(QWidget *parent = 0);
    ~BoardAtp();

private:
    Ui::BoardAtp *ui;
};

#endif // BOARDATP_H
