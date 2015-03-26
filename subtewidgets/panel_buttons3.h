#ifndef PANEL_BUTTONS3_H
#define PANEL_BUTTONS3_H

#include <QWidget>
#include <QQuickItem>

namespace Ui {
class Panel_Buttons3;
}

class Panel_Buttons3 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_Buttons3(QWidget *parent = 0);
    ~Panel_Buttons3();

    bool stateFirst();
    bool stateSecond();
    bool stateThird();

    bool firstClickeable();
    bool secondClickeable();
    bool thirdClickeable();

    void setFirstButtonImage(QUrl on,QUrl off);
    void setSecondButtonImage(QUrl on,QUrl off);
    void setThirdButtonImage(QUrl on,QUrl off);

private:
    Ui::Panel_Buttons3 *ui;
    QQuickItem *m_qmlView;

signals:
     void firstClicked();
     void secondClicked();
     void thirdClicked();

public slots:
     void firstOn();
     void firstOff();
     void secondOn();
     void secondOff();
     void thirdOn();
     void thirdOff();
     void setFirstClickeable(bool clickeable);
     void setSecondClickeable(bool clickeable);
     void setThirdClickeable(bool clickeable);
};

#endif // PANEL_BUTTONS3_H
