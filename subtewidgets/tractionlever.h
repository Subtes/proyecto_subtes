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
    void setValue(int v);
    ~TractionLever();

private:
    Ui::TractionLever *ui;

private slots:
    void processValueChanged(int value);

signals:
    zero();
    traction(int);
    positionChanged(int);
    //brake(int);
    emergencyBrake();

    hvPressed();
    hvReleased();

};

#endif // TRACTIONLEVER_H
