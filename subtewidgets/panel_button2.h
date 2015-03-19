#ifndef PANEL_BUTTON_2_H
#define PANEL_BUTTON_2_H

#include <QWidget>

namespace Ui {
class Panel_Button2;
}

class Panel_Button2 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_Button2(QWidget *parent = 0);
    ~Panel_Button2();

private:
    Ui::Panel_Button2 *ui;
};

#endif // PANEL_BUTTON_2
