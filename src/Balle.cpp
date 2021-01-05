#include "Balle.h"
Balle::Balle(double r):
    Cercle{r,Position(800/2,600-20)},
    _direction{rand()%300,-300},
    _vitesse{0.006}
{
    _direction.x(100);
}

Balle::~Balle(){}

void Balle::avancer(){
	// Logic of the ball movement. If it hits the upper or lower walls it bounces back
    _position.x(_position.x()+_direction.x()*_vitesse);
	_position.y(_position.y()+_direction.y()*_vitesse);

	if (_position.x() > 800/*RESOLUTION_X_PAR_DEFAUT*/ -_rayon)
		_direction.x( -abs(_direction.x()));
	if (_position.x() < 10)
		_direction.x( abs(_direction.x()));
	if (_position.y() < 10)
		_direction.y( abs(_direction.y()));
    if(_position.y() > 600/*RESOLUTION_Y_PAR_DEFAUT*/ ){
        _position.y(_position.y()-20);
        _direction.xy(0,0);
    }
}
void Balle::ajusterVitesse(const Briques& br){
    /*On utilise la fonction solidite qui est dans la classe Brique qui renvoie le double, et
     on le multiplie ^par la vitesse de notre balle*/
    _vitesse*=br.solidite();
}
void Balle::collision(const Raquette&r){
    //detecter la collision avec la raquette, et faire le rebond
	if (_position.y() > 600 - 20 && _direction.y() > 0){
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
