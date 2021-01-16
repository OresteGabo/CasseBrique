#include "Rectangle.h"

Rectangle::Rectangle(double l,double h,const Position&p):
    _largeur{l},
    _hauteur{h},
    _position{p}
{
}

Rectangle::~Rectangle()
{
}
Position Rectangle::position()const{
    return _position;
}
void Rectangle::position(const Position& p){
    _position=p;
}
int Rectangle::largeur()const{
    return _largeur;
}
int Rectangle::hauteur()const{
    return _hauteur;
}
void Rectangle::largeur(int l){
    _largeur=l;
}
void Rectangle::hauteur(int h){
    _hauteur=h;
}
double Rectangle::topY()const{
    return _position.y() - _hauteur / 2;
}
double Rectangle::bottomY()const{
    return _position.y() + _hauteur / 2;
}
int Rectangle::couleur()const{
    return _couleur;
}
void Rectangle::couleur(int c){
    _couleur=c;
}
double Rectangle::leftX()const{
    return  _position.x() - _largeur / 2;
}
double Rectangle::rightX()const{
    return _position.x() + _largeur / 2;
}
void Rectangle::positionX(double xPos){
    _position.x( xPos);
	if (_position.x() < _largeur / 2){
		_position.x(_largeur / 2);
	}
	if (_position.x() > FENETRE_X - _largeur / 2){
		_position.x( FENETRE_X - _largeur / 2);
	}
}
bool Rectangle::collision(const Cercle&c)const{
    return c.topY() < bottomY() && c.bottomY() > topY() && c.rightX() > leftX() && c.leftX() < rightX();
}
