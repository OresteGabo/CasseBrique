
#include "Cercle.h"

Cercle::Cercle(double r,const Position& p):_rayon{r},_position{p}
{}

Cercle::~Cercle()
{}

double Cercle::rayon()const{
    return _rayon;
}
void Cercle::rayon(double val){
    _rayon=val;
}
double Cercle::diametre()const{return 2*_rayon;}
double Cercle::topY()const{
    return _position.y()-_rayon;
}
double Cercle::rightX()const{
    return _position.x()+_rayon;
}
double Cercle::leftX()const{
    return _position.x()-_rayon;
}
double Cercle::bottomY()const{
    return _position.y()+_rayon;
}
