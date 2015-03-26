#ifndef TRACTIONLEVER_H
#define TRACTIONLEVER_H

#include <QWidget>

namespace Ui {
class TractionLever;
}

class TractionLever : public QWidget
{
    Q_OBJECT

public:
    explicit TractionLever(QWidget *parent = 0);
    ~TractionLever();

private:
    Ui::TractionLever *ui;

signals:
    valueChanged(int);
};

#endif // TRACTIONLEVER_H
