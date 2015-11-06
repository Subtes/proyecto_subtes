#ifndef BOARDAUXILIARYPANEL_H
#define BOARDAUXILIARYPANEL_H

#include "baseboard.h"
#include "auxiliarypanel.h"

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

    void setSubte(QString s);
    void processSelection(QString s);

private:
    Ui::BoardAuxiliaryPanel *ui;
    AuxiliaryPanel *m_view;

    int m_ready;
    QString m_modelSubway;
};

#endif // BOARDAUXILIARYPANEL_H
