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
