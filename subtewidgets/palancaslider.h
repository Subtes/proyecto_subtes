#ifndef PALANCASLIDER_H
#define PALANCASLIDER_H

#include <QWidget>

namespace Ui {
class PalancaSlider;
}

class PalancaSlider : public QWidget
{
    Q_OBJECT

public:
    explicit PalancaSlider(QWidget *parent = 0);
    ~PalancaSlider();

private:
    Ui::PalancaSlider *ui;
};

#endif // PALANCASLIDER_H
