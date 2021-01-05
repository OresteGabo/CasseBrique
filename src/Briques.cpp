#include "Briques.h"

Briques::Briques(double x,double y):
    _position{x,y},
    _largeur{40},
    _hauteur{20}
{
}

Briques::~Briques()
{
}
Position Briques::position()const{
    return _position;
}
void Briques::position(const Position& p){
    _position=p;
}
int Briques::largeur()const{
    return _largeur;
}
int Briques::hauteur()const{
    return _hauteur;
}
void Briques::largeur(int l){
    _largeur=l;
}
void Briques::hauteur(int h){
    _hauteur=h;
}
