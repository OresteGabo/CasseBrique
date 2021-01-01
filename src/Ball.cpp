#include "Ball.h"
Ball::Ball(double r):
    Cercle{r,Position(RESOLUTION_X_PAR_DEFAUT/2,RESOLUTION_Y_PAR_DEFAUT-20)},
    _vitesse{rand()%300,-300}
{
    _vitesse.x(100);
}

Ball::~Ball(){}

void Ball::avancer(double tempsMS){
	// Logic of the ball movement. If it hits the upper or lower walls it bounces back

    _position.x(_position.x()+_vitesse.x()*tempsMS);
	_position.y(_position.y()+_vitesse.y()*tempsMS);

	if (_position.x() > RESOLUTION_X_PAR_DEFAUT - _rayon)
		_vitesse.x( -abs(_vitesse.x()));
	if (_position.x() < 10)
		_vitesse.x( abs(_vitesse.x()));
	if (_position.y() < 10)
		_vitesse.y( abs(_vitesse.y()));
    if(_position.y() > RESOLUTION_Y_PAR_DEFAUT ){
        _position.y(_position.y()-20);
        _vitesse.xy(0,0);
    }

}

void Ball::CheckHitsRaquette(double RaquetteX){
	// Checks if the ball hits the Raquette. If it does, it bounces back
	if (_position.y() > RESOLUTION_Y_PAR_DEFAUT - 20 && _vitesse.y() > 0){
		if (_position.x() > RaquetteX - LARGEUR_RAQUETTE_PAR_DEFAUT / 2 &&
            _position.x() < RaquetteX + LARGEUR_RAQUETTE_PAR_DEFAUT/2 ){
			_vitesse.y( -_vitesse.y());
		}
	}
}

Position Ball::position()const{
    return _position;
}
void Ball::position(const Position& p){
    _position=p;
}
Position Ball::vitesse()const{
    return _vitesse;
}
void Ball::vitesse(const Position& p){
    _vitesse=p;
}
