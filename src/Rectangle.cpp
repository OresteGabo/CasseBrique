#include "Rectangle.h"

Rectangle::Rectangle(double l,double h,const Position& p):
    _largeur{l},
    _hauteur{h},
    _position{p}
{}

Rectangle::~Rectangle()
{}
double Rectangle::hauteur()const{
    return _hauteur;
}
double Rectangle::largeur()const{
    return _largeur;
}

void Rectangle::hauteur(double h){
    _hauteur=h;
}
void Rectangle::largeur(double l){
    _largeur=l;
}
bool Rectangle::collision(const Rectangle& r,int& coteTouche)const{

}
bool Rectangle::collision(const Cercle& c,int& coteTouche)const{
    //if((c.rayon()+hauteur())/2 < c.position().distance(_position)){

        return true;
    //}
}
Position Rectangle::position()const{
    return _position;
}
void Rectangle::position(const Position& p){
    _position =p;
}
