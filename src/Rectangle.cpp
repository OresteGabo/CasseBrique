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
int Rectangle::collisionSide(const Cercle& c)const{
    /**
    *   0 pour le NORD du rectaangle
    *   1 EST
    *   2 SUD
    *   3 OUEST
    */
    double distanceX1 = abs(c.rightX() - leftX());
    double distanceX2 = abs(c.leftX() - rightX());
    double distanceY1 = abs(c.topY() - bottomY());
    double distanceY2 = abs(c.bottomY() - topY());

    if(/*c.direction().y() > 0 &&*/ distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2){
        return 0;
    }else if(/*c.direction().x() < 0 &&*/ distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
        return 1;
    }else if(/*c.direction().y() < 0 &&*/ distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
        return 2;
    }
    return 3;
}
