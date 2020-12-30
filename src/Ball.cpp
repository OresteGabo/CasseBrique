#include "Ball.h"
Ball::Ball(double r):
    Cercle{r,Position(RESOLUTION_X_PAR_DEFAUT/2,RESOLUTION_Y_PAR_DEFAUT-20)},
    _speed{rand()%300,-300}
{
    _speed.x(100);
}

Ball::~Ball(){}

void Ball::avancer(double tempsMS){
	// Logic of the ball movement. If it hits the upper or lower walls it bounces back

    _position.x(_position.x()+_speed.x()*tempsMS);
	_position.y(_position.y()+_speed.y()*tempsMS);

	if (_position.x() > RESOLUTION_X_PAR_DEFAUT - _rayon)
		_speed.x( -abs(_speed.x()));
	if (_position.x() < 10)
		_speed.x( abs(_speed.x()));
	if (_position.y() < 10)
		_speed.y( abs(_speed.y()));
    if(_position.y() > RESOLUTION_Y_PAR_DEFAUT ){
        _position.y(_position.y()-20);
        _speed.xy(0,0);
    }

}

void Ball::CheckHitsRaquette(double RaquetteX){
	// Checks if the ball hits the Raquette. If it does, it bounces back
	if (_position.y() > RESOLUTION_Y_PAR_DEFAUT - 20 && _speed.y() > 0){
		if (_position.x() > RaquetteX - LARGEUR_RAQUETTE_PAR_DEFAUT / 2 &&
            _position.x() < RaquetteX + LARGEUR_RAQUETTE_PAR_DEFAUT/2 ){
			_speed.y( -_speed.y());
		}
	}
}

bool Ball::IsOutside(){
	// Returns true if the ball is outside the play area on the right side
	return _position.y() > RESOLUTION_Y_PAR_DEFAUT;
}


Position Ball::position()const{
    return _position;
}
void Ball::position(const Position& p){
    _position=p;
}
Position Ball::speed()const{
    return _speed;
}
void Ball::speed(const Position& p){
    _speed=p;
}
