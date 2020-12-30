#include "Raquette.h"


Raquette::Raquette(double y):_position{Position(RESOLUTION_X_PAR_DEFAUT /2,RESOLUTION_Y_PAR_DEFAUT-20)}{}
Raquette::~Raquette(){
}
void Raquette::repositionnerX(int xPos){
	// Moves the paddle to a specified position, also making sure it doesn't go outside the screen
	_position.x( xPos);
	if (_position.x() < LARGEUR_RAQUETTE_PAR_DEFAUT / 2){
		_position.x(LARGEUR_RAQUETTE_PAR_DEFAUT / 2);
	}
	if (_position.x() > RESOLUTION_X_PAR_DEFAUT - LARGEUR_RAQUETTE_PAR_DEFAUT / 2){
		_position.x( RESOLUTION_X_PAR_DEFAUT - LARGEUR_RAQUETTE_PAR_DEFAUT / 2);
	}
}


Position Raquette::position()const{
    return _position;
}
int Raquette::largeur()const{
    return LARGEUR_RAQUETTE_PAR_DEFAUT;
}

