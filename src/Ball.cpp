#include "Ball.h"
Ball::Ball(double r):
    Cercle{r,Position(RESOLUTION_X_PAR_DEFAUT/2,RESOLUTION_Y_PAR_DEFAUT-20)},
    _direction{rand()%300,-300},
    _vitesse{0.006}
{
    _direction.x(100);
}

Ball::~Ball(){}

void Ball::avancer(){
	// Logic of the ball movement. If it hits the upper or lower walls it bounces back
    _position.x(_position.x()+_direction.x()*_vitesse);
	_position.y(_position.y()+_direction.y()*_vitesse);

	if (_position.x() > RESOLUTION_X_PAR_DEFAUT -_rayon)
		_direction.x( -abs(_direction.x()));
	if (_position.x() < 10)
		_direction.x( abs(_direction.x()));
	if (_position.y() < 10)
		_direction.y( abs(_direction.y()));
    if(_position.y() > RESOLUTION_Y_PAR_DEFAUT ){
        _position.y(_position.y()-20);
        _direction.xy(0,0);
    }
}
void Ball::ajusterVitesse(int soliditeBrique){
    if(soliditeBrique==2){
        _vitesse*=1.1;
    }else if(soliditeBrique==3){
        _vitesse*=1.5;
    }
}
void Ball::collision(const Raquette&r){
    //detecter la collision avec la raquette, et faire le rebond
	if (_position.y() > RESOLUTION_Y_PAR_DEFAUT - 20 && _direction.y() > 0){
		if (_position.x() > r.position().x() - r.largeur() / 2 &&
            _position.x() < r.position().x() + r.largeur()/2 ){
			_direction.y( -_direction.y());
		}
	}
}

Position Ball::position()const{
    return _position;
}
void Ball::position(const Position& p){
    _position=p;
}
Position Ball::direction()const{
    return _direction;
}
void Ball::direction(const Position& p){
    _direction=p;
}
void Ball::vitesse(double v){
    _vitesse=v;
}
double Ball::vitesse()const{
    return _vitesse;
}
