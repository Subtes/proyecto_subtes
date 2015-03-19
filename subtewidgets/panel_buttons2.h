#ifndef PANEL_BUTTONS2_H
#define PANEL_BUTTONS2_H

#include <QWidget>

namespace Ui {
class Panel_Buttons2;
}

class Panel_Buttons2 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_Buttons2(QWidget *parent = 0);
    ~Panel_Buttons2();

private:
    Ui::Panel_Buttons2 *ui;
};

#endif // PANEL_BUTTONS2_H
