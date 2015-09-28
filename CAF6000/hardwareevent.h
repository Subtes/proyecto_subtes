#ifndef HARDWAREEVENT_H
#define HARDWAREEVENT_H

#include <QWidget>
#include <QTimer>
#include "../SDL/include/SDL.h"
#include "../SDL/include/SDL_keyboard.h"
#include "../SDL/include/SDL_keycode.h"
#undef main

class HardwareEvent : public QWidget{
    Q_OBJECT
public:
    explicit HardwareEvent(SDL_Event e, QWidget *parent = 0);

//    int OnExecute();

    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnExit();

    void OnKeyDown( SDL_Keycode sym, Uint16 mod, Uint16 scancode );

    void OnKeyUp( SDL_Keycode sym, Uint16 mod, Uint16 scancode );

    void OnMouseMove( int mx, int my, int relx, int rely, bool Left, bool Right, bool Middle );

    void OnLButtonDown ( int mx, int my );

    void OnLButtonUp ( int mx, int my );

    void OnRButtonDown ( int mx, int my );

    void OnRButtonUp ( int mx, int my );

    void OnMButtonDown ( int mx, int my );

    void OnMButtonUp ( int mx, int my );

    void OnMouseFocus();

    void OnMouseBlur();

    void OnInputFocus();

    void OnInputBlur();

    void OnWindowResized( int data1, int data2 );

    void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

    void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);

    void OnJoyHat(Uint8 which, Uint8 hat, Uint8 button);

    void OnJoyButtonDown(Uint8 which, Uint8 button);

    void OnJoyButtonUp(Uint8 which, Uint8 button);

    void OnUser(Uint8 type, int code, void* data1, void* data2);

signals:

public slots:
    int OnExecute();

private:
    QTimer *m_doSomething = NULL;
    SDL_Event *m_events;
};

#endif // HARDWAREEVENT_H
