#include "Balle.h"

Balle::Balle(double r,int c):
    Cercle{r,Position(FENETRE_X/2,FENETRE_Y-20),c},
    _direction{rand()%300,-300},
    _vitesse{0.005}
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

