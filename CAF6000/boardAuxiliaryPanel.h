#ifndef BOARDAUXILIARYPANEL_H
#define BOARDAUXILIARYPANEL_H

#include "baseboard.h"

namespace Ui {
class BoardAuxiliaryPanel;
}

class BoardAuxiliaryPanel : public BaseBoard
{
    Q_OBJECT

public:
    explicit BoardAuxiliaryPanel(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardAuxiliaryPanel();

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();
    void loadState(int state);

private:
    Ui::BoardAuxiliaryPanel *ui;  
};

#endif // BOARDAUXILIARYPANEL_H
