#include "Cercle.h"

Cercle::Cercle(double r,const Position& p):_rayon{r},_position{p}
{}

Cercle::~Cercle()
{}

double Cercle::rayon()const{
    return _rayon;
}
double Cercle::diametre()const{
    return _rayon*2;
}
double Cercle::circonference()const{
    return _rayon*2*3.14;
}
double Cercle::surface()const{
    return _rayon*_rayon*2*3.14;
}
/*bool Cercle::collidedRectangle(const Rectangle&r,SIDE&)const{

}
*/
