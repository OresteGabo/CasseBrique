#include "Application.h"

Application::Application():
    _cassebrique{new CasseBrique()},
    _raquette{new Raquette(600-10)},
    _resolutionX{800},
    _resolutionY{600}
{
    afficheMenu();
}
Application::~Application()
{
    delete _cassebrique;
    delete _raquette;
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
void Application::mvtRaquette(){
    POINT cursorPosition;
    GetCursorPos(&cursorPosition);
    double x=double(cursorPosition.x);
    if(x<_resolutionX && x>0){
        _raquette->repositionnerX(x);
    }
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
void Application::afficheMenuBalle(){
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
void Application::afficheMenuBrique(){
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


void Application::executer(){
    bool running = true,quit=false;

    while(!quit){
        if(running){
            initwindow( _resolutionX , _resolutionY , "WinBGIm Demo" );
        }
        while (running){
            cleardevice();
            afficher();
            mvtRaquette();

            // logique du jeux
            _cassebrique->logique();


            if(_cassebrique->tousLesBriquesCasses()){
                cleardevice();
                cout<<"## FELICITATION VOUS AVEZ GAGNE##"<<endl;
                afficheMenu();
            }
            if(!_cassebrique->balleTJREnJeux()){
                cleardevice();
                cout<<"## FELICITATION VOUS AVEZ PERDU##"<<endl;
                afficheMenu();
            }
        }
        std::cout<<"Hello gdebugger"<<std::endl;
        int x;cin>>x;
    }
}
void Application::afficher(const Balle& b)const{
    setcolor(LIGHTCYAN);
	circle(b.position().x(),b.position().y(),b.rayon());
    setfillstyle(SOLID_FILL,LIGHTCYAN);
	floodfill(b.position().x(),b.position().y(),LIGHTCYAN);
}
void Application::afficher(const vector<Briques*> br)const{
    for(unsigned int x=0;x<br.size();x++){
        if(br[x]->vivant()){
            setcolor(br[x]->couleur());
            double x1= br[x]->position().x() - br[x]->largeur() / 2 + 1;
            double y1= br[x]->position().y() - br[x]->hauteur() / 2 + 1;
            double x2= br[x]->position().x() + br[x]->largeur() / 2 - 1;
            double y2= br[x]->position().y() + br[x]->hauteur() / 2 - 1;
            rectangle(x1,y1,x2,y2);
            setfillstyle(br[x]->style(),br[x]->couleur());
            floodfill(x1+2,y1+2,br[x]->couleur());
        }
    }
}
void Application::afficher(const Raquette &r)const{
    double x1= r.position().x() - r.largeur() / 2;
    double y1= r.position().y() - 5;
    double x2= r.position().x() + r.largeur() / 2;
    double y2= r.position().y() + 5;
    rectangle(x1,y1,x2,y2);
}
void Application::afficher()const{
    afficher(_cassebrique->balle());
    afficher(_cassebrique->raquette());
    afficher(_cassebrique->briques());
}
