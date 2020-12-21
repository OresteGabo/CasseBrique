#include "Raquette.h"


Raquette::Raquette(double y):_position{Position(RESOLUTION_X /2,RESOLUTION_Y-20)}{}
Raquette::~Raquette(){
}
void Raquette::repositionnerX(int xPos){
	// Moves the paddle to a specified position, also making sure it doesn't go outside the screen
	_position.x( xPos);
	if (_position.x() < LARGEUR_RAQUETTE / 2){
		_position.x(LARGEUR_RAQUETTE / 2);
	}
	if (_position.x() > RESOLUTION_X - LARGEUR_RAQUETTE / 2){
		_position.x( RESOLUTION_X - LARGEUR_RAQUETTE / 2);
	}
}
void Raquette::afficher()const{
    setcolor(GREEN);
    double x1=_position.x() - LARGEUR_RAQUETTE / 2;
    double y1= _position.y() - 5;
    double x2=_position.x() + LARGEUR_RAQUETTE / 2;
    double y2= _position.y() + 5;
    rectangle(x1,y1,x2,y2);

}
Position Raquette::position()const{
    return _position;
}

