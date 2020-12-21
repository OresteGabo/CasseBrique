#include "Application.h"


Application::Application():
    _cassebrique{CasseBrique()},
    _raquette{Raquette(RESOLUTION_Y-10)}
{
    execute();
}

Application::~Application()
{
    //dtor
}


void Application::execute(){
    bool running = true;
    while (running){

        cleardevice();
        mvtRaquette();

        // logique du jeux
        _cassebrique.logique(ELAPSED_TIME_IN_MS);
        // affichage

        _cassebrique.afficher();
        _raquette.afficher();
    }
}

void Application::mvtRaquette(){
    POINT cursorPosition;
    GetCursorPos(&cursorPosition);
    double x=double(cursorPosition.x);
    if(x<RESOLUTION_X && x>0){
            _raquette.repositionnerX(x);
    }
}
