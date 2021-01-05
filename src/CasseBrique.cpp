#include "CasseBrique.h"
#include<iostream>
CasseBrique::CasseBrique():
    _balle{Balle(10)},
    _raquette{Raquette(600 - 5)}
{
    int counter=0;
    for (int i = 2; i <4; i++){
        for (int j = 0; j < 10; j++){
            int posX = 800 / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(new BriquesCassable(posX, posY,2));
        }
    }

    for (int i = 4; i < 5; i++){
        for (int j = 0; j < 10; j++){
            int posX = 800 / 3 + j  * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(new BriquesCassable(posX, posY,1));
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 10; j++){
            int posX = 800 / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(new BriquesCassable(posX, posY,3));
        }
    }

}
CasseBrique::~CasseBrique(){
    detruireBriques();
}
double CasseBrique::positionSourie()const{
    // receives the mouse position, to be used on the right paddle(raquette)
    POINT cursorPosition;
    GetCursorPos(&cursorPosition);
    return double(cursorPosition.x);
}
void CasseBrique::logique(){
    // Avancer la balle
    _balle.avancer();

    // bouger la raquette a partir de la position du souri
    _raquette.repositionnerX(positionSourie());

    //chercher si la balle touche la raquette, puis changer sa speed en negative
    _balle.collision(_raquette);

    // Si la balle touche l'un des briques
    for(int x=0;x<_briques.size();x++){
        _briques[x]->collision(_balle);
    }
}
bool CasseBrique::balleTJREnJeux()const{
    return _balle.position().y() < 600;
}
const Balle& CasseBrique::balle()const{
    return _balle;
}
const Raquette& CasseBrique::raquette()const{
    return _raquette;
}
bool CasseBrique::tousLesBriquesCasses()const{
    for(unsigned int x=0;x<_briques.size();x++){
        if(_briques[x]->vivant())
            return false;
    }
    return true;
}
void CasseBrique::detruireBriques(){
    for(unsigned int x=0;x<_briques.size();x++)
        delete _briques[x];
}
vector<Briques*> CasseBrique::briques()const{
    return _briques;
}

