#ifndef SPLASHTEST_H
#define SPLASHTEST_H

#include <QMainWindow>
#include "src/controllers/dispatcher.h"
namespace Ui {
class splashTest;
}

class splashTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit splashTest(QWidget *parent = 0, Dispatcher *dispatcher = 0);
    ~splashTest();

private:
    Ui::splashTest *ui;
};

#endif // SPLASHTEST_H
