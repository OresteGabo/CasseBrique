
#include "CasseBrique.h"
#include<iostream>
CasseBrique::CasseBrique():
    _ball{new Ball()},
    _raquette{new Raquette(RESOLUTION_Y - 5)},
    _playing{true}
{

    for (int i = 2; i <4; i++){
        for (int j = 0; j < 15; j++){
            int posX = RESOLUTION_X / 2 + (j - 7) * LARGEUR_BRIQUE;
            int posY = 100 + i * HAUTEUR_BRIQUE;
            _briques.push_back(Briques(posX, posY,2));
        }
    }
    for (int i = 4; i < 5; i++){
        for (int j = 0; j < 15; j++){
            int posX = RESOLUTION_X / 2 + (j - 7) * LARGEUR_BRIQUE;
            int posY = 100 + i * HAUTEUR_BRIQUE;
            _briques.push_back(Briques(posX, posY,1));
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 15; j++){
            int posX = RESOLUTION_X / 2 + (j - 7) * LARGEUR_BRIQUE;
            int posY = 100 + i * HAUTEUR_BRIQUE;
            _briques.push_back(Briques(posX, posY,3));
        }
    }


    /*std::cout<<"Cassebrique constructor"<<std::endl;
    int debugger;
    std::cin>>debugger;*/
}
void CasseBrique::MAJ(){

    for(unsigned int x=0;x<_briques.size();x++){
        if(_briques[x].vie()==0){
            std::cout<<"N_"<<x<<" :is deleted:  N�"<<_briques[x].compteur()<<std::endl;
            supprimerBrique(_briques[x].compteur());

        }
    }
}
CasseBrique::~CasseBrique(){
    delete _ball;
    delete _raquette;
}
void CasseBrique::supprimerBrique(int val){
     _briques.erase(_briques.begin()+val);
}
double CasseBrique::positionSourie()const{
    // receives the mouse position, to be used on the right paddle(raquette)
    POINT cursorPosition;
    GetCursorPos(&cursorPosition);
    return double(cursorPosition.x);
}

void CasseBrique::logique(double tempsMS){

    if (_playing){

        // Avancer la balle
        _ball->avancer(tempsMS);

        // bouger la raquette a partir de la position du souri
        _raquette->repositionnerX(positionSourie());

        //chercher si la balle touche la raquette, puis changer sa speed en negative
        _ball->CheckHitsRaquette(_raquette->position().x());

        // Si la balle touche l'un des briques
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 15; j++){
                _briques[i * 15 + j].BallCollision(_ball);
            }
        }

        // si la balle va dans l'espace en dehors du jeux, le jeux sarrete
        if (_ball->IsOutside()){
            _playing = false;
        }
    }
}

void CasseBrique::afficher()const{

    _ball->afficher();
    _raquette->afficher();
    for(int x=_briques.size()-1;x>=0;x--){
        _briques[x].afficher();
    }
}
