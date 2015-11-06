#ifndef DRIVINGMODESELECTOR_H
#define DRIVINGMODESELECTOR_H

#include <QWidget>
#include <QQuickItem>

namespace Ui {
class DrivingModeSelector;
}

class DrivingModeSelector : public QWidget
{
    Q_OBJECT

public:
    explicit DrivingModeSelector(QWidget *parent = 0);
    ~DrivingModeSelector();

signals:
    selectedOption(int op);

private:
    Ui::DrivingModeSelector *ui;
    QQuickItem *m_qmlView;    
};

#endif // DRIVINGMODESELECTOR_H
