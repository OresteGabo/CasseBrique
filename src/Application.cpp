#include "Application.h"

Application::Application(int resolutionX,int resolutionY):
    _resolutionX{resolutionX},
    _resolutionY{resolutionY},
    _cassebrique{new CasseBrique(_resolutionX,_resolutionY)}
{
    afficheMenu();
}

Application::~Application()
{
    finirLeJeux();
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
    bool jeuxEnCours=true;
    while(jeuxEnCours){
        cout<<"     _____JEUX CASSEBRIQUES____"<<endl;
        cout<<"     1. Lancer le jeux"<<endl;
        cout<<"     2. Charger les autre briques"<<endl;
        cout<<"     3. Quitter"<<endl;

        int input;
        cin>>input;
        if(input==1){
            executer();
            delete _cassebrique;
            _cassebrique=new CasseBrique(_resolutionX,_resolutionY);
        }else if(input==2){
            chargerAutreBrique();
        }else if(input ==3 ){
            jeuxEnCours=false;
        }
    }
}

void Application::chargerAutreBrique(){
    _cassebrique->decharger();
    cout<<"_____tapez entre 1_4____"<<endl;
    int input;
    cin>>input;
    _cassebrique->charger(input);
}
void Application::executer(){
    bool running = true;
    bool initNedded=true;
    if(initNedded){
        initwindow( _resolutionX , _resolutionY , "WinBGIm Demo" );
        initNedded=false;
    }
    while (running){
        cleardevice();
        afficher();
        // logique du jeux
        _cassebrique->logique();
        if(_cassebrique->tousLesBriquesCasses()){
            cleardevice();
            closegraph();
            system("cls");
            cout<<"## FELICITATION VOUS AVEZ GAGNE##"<<endl;
            running=false;
        }
        if(!_cassebrique->balleTJREnJeux()){
            cleardevice();
            closegraph();
            system("cls");
            cout<<endl<<endl<<endl<<"           ## VOUS AVEZ PERDU##\n\n"<<endl;
            running=false;
        }
    }
}
void Application::afficher(const Balle& b)const{
    setcolor(b.couleur());
	circle(b.position().x(),b.position().y(),b.rayon());
    setfillstyle(SOLID_FILL,b.couleur());
	floodfill(b.position().x(),b.position().y(),b.couleur());
}
void Application::afficher(const vector<Briques*> br)const{
    for(unsigned int x=0;x<br.size();x++){
        if(br[x]->utilisable()){
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
void Application::finirLeJeux(){
    ///La liberation de la memoire alloué
    if (_cassebrique)
        delete _cassebrique;
    system("cls");
    cout<<" MERCI D'AVOIR JOUER NOTRE JEUX "<<endl;
    cout<<"les sources codes sont disponible sur :"<<endl<<endl;
    cout<<"         https://github.com/OresteGabo/CasseBrique"<<endl;
    cout<<endl<<endl<<"         ________FIN________     "<<endl;
}
