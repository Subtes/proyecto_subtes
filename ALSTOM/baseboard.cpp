#include "baseboard.h"

BaseBoard::BaseBoard(QWidget *parent, SubteState * subte, EventHandler *eventHandler) :
    QMainWindow(parent)
{
    m_subte = subte;
    m_eventHandler = eventHandler;
}

BaseBoard::~BaseBoard()
{

}

