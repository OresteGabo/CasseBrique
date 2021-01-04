#include "Application.h"
#include"AfficheurWinbgi.h"

Application::Application():
    _cassebrique{CasseBrique()},
    _raquette{Raquette(RESOLUTION_Y_PAR_DEFAUT-10)},
    _resolutionX{800},
    _resolutionY{600}
{
    afficheMenu();
}

Application::~Application()
{}

void Application::executer(){
    AfficheurWinbgi afficheur=AfficheurWinbgi();
    bool running = true,quit=false;
    while(!quit){
        if(running){
            initwindow( _resolutionX , _resolutionY , "WinBGIm Demo" );
        }
        while (running){
            cleardevice();
            mvtRaquette();

            // logique du jeux
            _cassebrique.logique();
            afficheur.afficher(&_cassebrique);
            if(_cassebrique.tousLesBriquesCasses()){
                cleardevice();
                cout<<"## FELICITATION VOUS AVEZ GAGNE##"<<endl;
                afficheMenu();
            }
            if(!_cassebrique.balleTJREnJeux()){
                cleardevice();
                cout<<"## FELICITATION VOUS AVEZ PERDU##"<<endl;
                afficheMenu();
            }
        }
    }
}

int Application::resolutionX()const{
    return _resolutionX;
}
int Application::resolutionY()const{
    return _resolutionY;
}

void Application::resolutionX(int x){
    _resolutionX=x;
}
void Application::resolutionY(int y){
    _resolutionY=y;
}

void Application::afficheMenu(){
    cout<<"_____JEUX CASSEBRIQUES____"<<endl;
    cout<<"1. Lancer le jeux"<<endl;
    cout<<"2. Parametres"<<endl;

    int input;
    cin>>input;
    if(input==1){
        executer();
    }else if(input==2){
        afficherParametres();
    }else{
        afficheMenu();
    }
}
void Application::afficherParametres(){
    cout<<"_____LES PARAMETRES____"<<endl;
    cout<<"1. Balle"<<endl;
    cout<<"2. Briques"<<endl;
    cout<<"3. Application"<<endl;
    cout<<"4. Menu principale"<<endl<<endl<<endl;

    int input;
    cin>>input;
    if(input==1){
        executer();
    }else if(input==2){
        afficherParametres();
    }else{
        afficheMenu();
    }
}
void Application::afficheBalle(){
    cout<<"_____LA BELLE DU JEUX____"<<endl;
    cout<<"1. Changer la taille"<<endl;
    cout<<"2. Changer la couleur"<<endl;
    cout<<"3. Menu principale"<<endl<<endl<<endl<<endl;

    int input;
    cin>>input;
    if(input==1){
        executer();
    }else if(input==2){
        afficherParametres();
    }else{
        afficheMenu();
    }
}
void Application::afficheBrique(){
    cout<<"_____LES BRIQUES DU JEUX____"<<endl;
    cout<<"1. Changer les couleur"<<endl;
    cout<<"2. Changer les vies des briques"<<endl;
    cout<<"3. Menu principale"<<endl<<endl<<endl<<endl;

    int input;
    cin>>input;
    if(input==1){
        executer();
    }else if(input==2){
        afficherParametres();
    }else{
        afficheMenu();
    }
}
void Application::mvtRaquette(){
    POINT cursorPosition;
    GetCursorPos(&cursorPosition);
    double x=double(cursorPosition.x);
    if(x<_resolutionX && x>0){
        _raquette.repositionnerX(x);
    }
}
