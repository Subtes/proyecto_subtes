#ifndef SPEEDGAUGE_H
#define SPEEDGAUGE_H

#include <QWidget>

namespace Ui {
class SpeedGauge;
}

class SpeedGauge : public QWidget
{
    Q_OBJECT

public:
    explicit SpeedGauge(QWidget *parent = 0);
    ~SpeedGauge();

private:
    Ui::SpeedGauge *ui;
};

#endif // SPEEDGAUGE_H
