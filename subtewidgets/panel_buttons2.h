#ifndef PANEL_BUTTONS2_H
#define PANEL_BUTTONS2_H

#include <QWidget>
#include <QQuickItem>
#include <QVariant>

namespace Ui {
class Panel_Buttons2;
}

class Panel_Buttons2 : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_Buttons2(QWidget *parent = 0);
    ~Panel_Buttons2();
    /**
     * @brief enable_Button1
     * @param e: it's boolean parameter, true if you wish enable click area button.
     */
    void enable_Button1(QVariant e);
    void enable_Button2(QVariant e);

signals:
    on_ClickButton1();
    on_ClickButton2();

public slots:
    void on_Button1();
    void on_Button2();
    void off_Button1();
    void off_Button2();
    void trigger_Alarm(QVariant enable);

private:
    Ui::Panel_Buttons2 *ui = NULL;
    QQuickItem *qmlView = NULL;
};

#endif // PANEL_BUTTONS2_H
