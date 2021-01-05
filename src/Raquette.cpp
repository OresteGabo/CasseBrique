#include "Raquette.h"


Raquette::Raquette(double y):
    _largeur{100},
    _hauteur{10},
    _position{
    Position(800 /2,600-_hauteur*2)}{}
Raquette::~Raquette(){
}
void Raquette::repositionnerX(int xPos){
	// Moves the paddle to a specified position, also making sure it doesn't go outside the screen
	_position.x( xPos);
	if (_position.x() < _largeur / 2){
		_position.x(_largeur / 2);
	}
	if (_position.x() > 800 - _largeur / 2){
		_position.x( 800 - _largeur / 2);
	}
}
Position Raquette::position()const{
    return _position;
}
int Raquette::largeur()const{
    return _largeur;
}
int Raquette::hauteur()const{
    return _hauteur;
}
