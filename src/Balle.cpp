#include "Balle.h"
#include "../variableGlobale.h"
Balle::Balle(double r,int c):
    Cercle{r,Position(FENETRE_X/2,FENETRE_Y-20)},
    _direction{rand()%300,-300},
    _vitesse{0.005},
    _couleur{c}
{
}
Balle::~Balle(){}
void Balle::avancer(){
	// Logic of the ball movement. If it hits the upper or lower walls it bounces back
    _position.x(_position.x()+_direction.x()*_vitesse);
	_position.y(_position.y()+_direction.y()*_vitesse);

	if (_position.x() > FENETRE_X-_rayon)
		_direction.x( -abs(_direction.x()));
	if (_position.x() < 10)
		_direction.x( abs(_direction.x()));
	if (_position.y() < 10)
		_direction.y( abs(_direction.y()));
    if(_position.y() > FENETRE_Y ){
        _direction.xy(0,0);
    }
}
void Balle::ajusterVitesse(const Briques& br){
    _vitesse*=br.solidite();
}
void Balle::collision(const Raquette&r){
    //detecter la collision avec la raquette, et faire le rebond
	if (_position.y() > FENETRE_Y - ((diametre())+r.hauteur()) && _direction.y() > 0){
		if (_position.x() > r.position().x() - r.largeur() / 2 &&
            _position.x() < r.position().x() + r.largeur()/2 ){
			_direction.y( -_direction.y());
		}
	}
}

Position Balle::position()const{
    return _position;
}
void Balle::position(const Position& p){
    _position=p;
}
Position Balle::direction()const{
    return _direction;
}
void Balle::direction(const Position& p){
    _direction=p;
}
void Balle::vitesse(double v){
    _vitesse=v;
}
double Balle::vitesse()const{
    return _vitesse;
}
int Balle::couleur()const{
    return _couleur;
}
void Balle::couleur(int c){
    _couleur=c;
}
