#include "CasseBrique.h"
#include<iostream>
#include"../variableGlobale.h"
CasseBrique::CasseBrique(int resolutionX,int resolutionY):
    _balle{Balle(10)},
    _resolutionX{resolutionX},
    _raquette{Raquette(resolutionY)}
{
    charger();
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
    _raquette.positionnerX(positionSourie());

    //chercher si la balle touche la raquette, puis changer sa speed en negative
    _balle.collision(_raquette);

    // Si la balle touche l'un des briques
    for(unsigned int x=0;x<_briques.size();x++){
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

void CasseBrique::avancer(){
    // Logic of the ball movement. If it hits the upper or lower walls it bounces back
    _balle.position().x(_balle.position().x()+_balle.direction().x()*_balle.vitesse());
	_balle.position().y(_balle.position().y()+_balle.direction().y()*_balle.vitesse());

	if (_balle.position().x() > _resolutionX -_balle.rayon())
		_balle.direction().x( -abs(_balle.direction().x()));
	if (_balle.position().x() < 10)
		_balle.direction().x( abs(_balle.direction().x()));
	if (_balle.position().y() < 10)
		_balle.direction().y( abs(_balle.direction().y()));
    if(_balle.position().y() > _resolutionY ){
        _balle.direction().xy(0,0);

    }
}

void CasseBrique::charger(int charge){
    switch(charge) {
      case 1 :
         charger1();
         break;
      case 2 :
          charger2();
         break;
      case 3 :
         charger3();
         break;
      case 4 :
         charger4();
         break;
      case 5 :
         charger5();
         break;
      default :
         cout << "charge inexistant!!    La charge par defaut est utilis�" << endl;
         charger1();

   }
}
void CasseBrique::charger1(){
    for (int i = 2; i <4; i++){
        for (int j = 0; j < 10; j++){
            int posX = FENETRE_X / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(new BriquesCassable(posX, posY,2));
            j++;
        }
    }

    for (int i = 4; i < 5; i++){
        for (int j = 0; j < 10; j++){
            //j++;
            int posX = FENETRE_X / 3 + j  * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(new BriquesCassable(posX, posY,3));
        }
    }

    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 10; j++){
            int posX = FENETRE_X / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            _briques.push_back(new BriquesCassable(posX, posY,3));
        }
    }

    for (int i = 7; i < 8; i++){
        for (int j = 0; j < 10; j+=2){

            int posX = FENETRE_X / 3 + j * 40;//40 represente la largeur des briques
            int posY = 100 + i * 20;//20 represente la hauteur des briques
            //_briques.push_back(new BriquesIncassable(266, 306.66));
            //j++;j++;
        }
    }
    _briques.push_back(new BriquesIncassable(266.66, 300));
    _briques.push_back(new BriquesIncassable(600, 240));

    _briques.push_back(new BriquesSansRobond(50, 50,1));
    _briques.push_back(new BriquesSansRobond(150, 50,3));
    _briques.push_back(new BriquesSansRobond(250, 50,3));


}
void CasseBrique::charger2(){
    charger1();
}
void CasseBrique::charger3(){
    charger1();
}
void CasseBrique::charger4(){
    charger1();
}
void CasseBrique::charger5(){
    charger1();
}
void CasseBrique::decharger(){
    detruireBriques();
}
void CasseBrique::initialiser(){
    decharger();
    charger();
    _balle.vitesse(0.005);
    _raquette.position().x(FENETRE_X /2);

}
