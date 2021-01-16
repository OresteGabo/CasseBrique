#include "Raquette.h"


Raquette::Raquette(double x,double y,const Position& p):
    Rectangle{x,y,p}
{
    if(p==Position(0,0)){
        //p=Position(FENETRE_X /2,FENETRE_Y-_hauteur*2);
    }

}
Raquette::~Raquette(){
}

double Raquette::solidite()const{
    return 1;
}

int Raquette::style()const{
    return 1;
}
void Raquette::collision(Cercle& balle){
    /*if (_position.y() > FENETRE_Y - ((diametre())+r.hauteur()) && _direction.y() > 0){
		if (_position.x() > r.position().x() - r.largeur() / 2 &&
            _position.x() < r.position().x() + r.largeur()/2 ){
			_direction.y( -_direction.y());
		}
	}*/
}
