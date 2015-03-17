#include "mytest.h"
#include "QDebug"

MyTest::MyTest()
{

}

MyTest::~MyTest()
{

}

void MyTest::print(QString msg){
    qDebug() << msg;
}
