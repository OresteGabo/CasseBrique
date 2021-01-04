
#include "CasseBrique.h"
#include<iostream>
CasseBrique::CasseBrique():
    _balle{new Ball(10)},
    _raquette{new Raquette(RESOLUTION_Y_PAR_DEFAUT - 5)}
{

    for (int i = 2; i <4; i++){
        for (int j = 0; j < 10; j++){
            int posX = RESOLUTION_X_PAR_DEFAUT / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(Briques(posX, posY,2));
        }
    }
    for (int i = 4; i < 5; i++){
        for (int j = 0; j < 10; j++){
            int posX = RESOLUTION_X_PAR_DEFAUT / 3 + j  * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(Briques(posX, posY,1));
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 10; j++){
            int posX = RESOLUTION_X_PAR_DEFAUT / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(Briques(posX, posY,3));
        }
    }
}

CasseBrique::~CasseBrique(){
    delete _balle;
    delete _raquette;
}

double CasseBrique::positionSourie()const{
    // receives the mouse position, to be used on the right paddle(raquette)
    POINT cursorPosition;
    GetCursorPos(&cursorPosition);
    return double(cursorPosition.x);
}

void CasseBrique::logique(){
    // Avancer la balle
    _balle->avancer();

    // bouger la raquette a partir de la position du souri
    _raquette->repositionnerX(positionSourie());

    //chercher si la balle touche la raquette, puis changer sa speed en negative
    _balle->collision(*_raquette);

    // Si la balle touche l'un des briques
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 15; j++){
            _briques[i * 15 + j].BallCollision(_balle);
        }
    }

}
bool CasseBrique::tousLesBriquesCasses()const{
    for(unsigned int x=0;x<_briques.size();x++){
        if(_briques[x].vie()>0)
            return false;
    }
    return true;
}
bool CasseBrique::balleTJREnJeux()const{
    return _balle->position().y() < RESOLUTION_Y_PAR_DEFAUT;
}

Ball* CasseBrique::balle()const{
    return _balle;
}
Raquette* CasseBrique::raquette()const{
    return _raquette;
}
vector<Briques> CasseBrique::briques()const{
    return _briques;
}
