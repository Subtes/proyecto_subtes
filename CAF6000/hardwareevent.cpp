#include "hardwareevent.h"
#include <QDebug>

HardwareEvent::HardwareEvent(SDL_Event e, QWidget *parent) : QWidget(parent){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
//    if(OnInit()){
//        m_doSomething = new QTimer;
//        m_doSomething->setInterval(50);
//        m_doSomething->start();
//        qDebug()<<"Iniciando SDL...";
//        connect(m_doSomething,SIGNAL(timeout()),this,SLOT(OnExecute()));
//    }else{
//        qDebug()<<"NO!!! Inicio SDL...";
//    }
    //SDL_INIT_EVERYTHING
    SDL_Init(SDL_INIT_EVERYTHING);
}

void HardwareEvent::OnEvent(SDL_Event* Event)
{
    switch(Event->type)
    {
        case SDL_WINDOWEVENT:
            {
                switch(Event->window.event)
                {
                    case SDL_WINDOWEVENT_ENTER:
                        {
                            OnMouseFocus();
                            break;
                        }
                    case SDL_WINDOWEVENT_LEAVE:
                        {
                            OnMouseBlur();
                            break;
                        }
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        {
                            OnInputFocus();
                            break;
                        }
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        {
                            OnInputBlur();
                            break;
                        }
                    case SDL_WINDOWEVENT_SHOWN:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_HIDDEN:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_EXPOSED:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_MOVED:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_RESIZED:
                        {
                            OnWindowResized( Event->window.data1, Event->window.data2 );
                            break;
                        }
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_MINIMIZED:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_MAXIMIZED:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_RESTORED:
                        {
                            break;
                        }
                    case SDL_WINDOWEVENT_CLOSE:
                        {
                            break;
                        }
                }
                break;
            }
        case SDL_QUIT:
            {
                OnExit();
                break;
            }
        case SDL_KEYDOWN:
            {
                OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
                break;
            }
        case SDL_KEYUP:
            {
                OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
                break;
            }
        case SDL_MOUSEMOTION:
            {
                OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
                break;
            }
        case SDL_MOUSEBUTTONDOWN:
            {
                switch(Event->button.button)
                {
                    case SDL_BUTTON_LEFT:
                        {
                            OnLButtonDown(Event->button.x, Event->button.y);
                            break;
                        }
                    case SDL_BUTTON_RIGHT:
                        {
                            OnRButtonDown(Event->button.x, Event->button.y);
                            break;
                        }
                    case SDL_BUTTON_MIDDLE:
                        {
                            OnMButtonDown(Event->button.x, Event->button.y);
                            break;
                        }
                }
                break;
            }
        case SDL_MOUSEBUTTONUP:
            {
                switch(Event->button.button)
                {
                    case SDL_BUTTON_LEFT:
                        {
                            OnLButtonUp(Event->button.x, Event->button.y);
                            break;
                        }
                    case SDL_BUTTON_RIGHT:
                        {
                            OnRButtonUp(Event->button.x, Event->button.y);
                            break;
                        }
                    case SDL_BUTTON_MIDDLE:
                        {
                            OnMButtonUp(Event->button.x, Event->button.y);
                            break;
                        }
                }
                break;
            }

            //Star getting things from here man!
        case SDL_JOYAXISMOTION:
            {
                OnJoyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
                break;
            }
        case SDL_JOYBALLMOTION:
            {
                OnJoyBall(Event->jball.which, Event->jball.ball, Event->jball.xrel, Event->jball.yrel);
                break;
            }
        case SDL_JOYHATMOTION:
            {
                OnJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
                break;
            }
        case SDL_JOYBUTTONDOWN:
            {
                OnJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
                break;
            }
        case SDL_JOYBUTTONUP:
            {
                OnJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
                break;
            }
        default:
            {
                OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
                break;
            }
    }
}

void HardwareEvent::OnExit() {}

void HardwareEvent::OnKeyDown( SDL_Keycode sym, Uint16 mod, Uint16 scancode )
{
    qDebug()<< "Entro en UN EXENTO XXXX -->";
    printf("keycode:%d\tmod:%d\tscancode:%d pressed!\n", sym, mod, scancode );
}

void HardwareEvent::OnKeyUp( SDL_Keycode sym, Uint16 mod, Uint16 scancode )
{
    qDebug()<< "Entro en UN EXENTO XXXX -->";
    printf("keycode:%d\tmod:%d\tscancode:%d unpressed!\n", sym, mod, scancode );
}

void HardwareEvent::OnMouseMove( int mx, int my, int relx, int rely, bool Left, bool Right, bool Middle )
{
    qDebug()<< "Entro en UN EXENTO XXXX -->";
    printf("x:%d\ty:%d\n", mx, my );
}

void HardwareEvent::OnLButtonDown ( int mx, int my )
{
    qDebug()<< "Entro en UN EXENTO XXXX -->";
    printf("Left Click pressed in x:%d\ty:%d\n", mx, my);
}

void HardwareEvent::OnLButtonUp ( int mx, int my )
{
    printf("Left Click unpressed in x:%d\ty:%d\n", mx, my);
}

void HardwareEvent::OnRButtonDown ( int mx, int my )
{
    printf("Right Click pressed in x:%d\ty:%d\n", mx, my);
}

void HardwareEvent::OnRButtonUp ( int mx, int my )
{
    printf("Right Click unpressed in x:%d\ty:%d\n", mx, my);
}

void HardwareEvent::OnMButtonDown ( int mx, int my )
{
    printf("Middle Click pressed in x:%d\ty:%d\n", mx, my);
}

void HardwareEvent::OnMButtonUp ( int mx, int my )
{
    printf("Middle Click unpressed in x:%d\ty:%d\n", mx, my);
}

void HardwareEvent::OnMouseFocus()
{
    printf("Mouse entered the window!\n");
}

void HardwareEvent::OnMouseBlur()
{
    printf("Mouse leaved the window!\n");
}

void HardwareEvent::OnInputFocus()
{
    printf("Keyboard Focus the window!\n");
}

void HardwareEvent::OnInputBlur()
{
    printf("Keyboard losed focus on the window!\n");
}

void HardwareEvent::OnWindowResized( int data1, int data2 )
{
    printf( "Window Resized to: width:%d\theight:%d\n", data1, data2 );
}

void HardwareEvent::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value){}

void HardwareEvent::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel){}

void HardwareEvent::OnJoyHat(Uint8 which, Uint8 hat, Uint8 button){}

void HardwareEvent::OnJoyButtonDown(Uint8 which, Uint8 button){}

void HardwareEvent::OnJoyButtonUp(Uint8 which, Uint8 button){}

void HardwareEvent::OnUser(Uint8 type, int code, void* data1, void* data2){}

int HardwareEvent::OnExecute(){

    if(OnInit() == false) {
        return -1;
    }

    qDebug()<< "Entro en OnExecute -->";

    SDL_Event Event;

//    SDL_PollEvent(&Event);

//    qDebug()<< "Event TYPE" << Event.type;

//        qDebug()<< "Event TYPE" << Event.type;
//        if (Event.type == SDL_MOUSEMOTION){
//                qDebug()<< "SDL_MOUSEMOTION Event TYPE" << Event.type;
//        }
//        if (Event.type == SDL_KEYDOWN)
//            {
//                qDebug()<< "SDL_KEYDOWN Event TYPE" << Event.type;
//                //OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
//            }
//        if (Event.type == SDL_KEYUP)
//            {
//                qDebug()<< "SDL_KEYUP Event TYPE" << Event.type;
//                //OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
//            }
         while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
            qDebug()<<"HAY EVENTOSSSS --->";
        }
 //       qDebug()<< "while...";
    return 0;
}

bool HardwareEvent::OnInit() {
    //SDL_INIT_EVERYTHING
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        return false;
    }

    return true;
}
