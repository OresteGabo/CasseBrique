#include "BriquesIncassable.h"

BriquesIncassable::BriquesIncassable(double x,double y):
    Briques{x,y}
{
    //ctor
}

BriquesIncassable::~BriquesIncassable()
{
    //dtor
}

bool BriquesIncassable::vivant()const{
    return true;
}
double BriquesIncassable::solidite()const{
    return 1;
}
int BriquesIncassable::couleur()const{
    return 1;
}

int BriquesIncassable::style()const{
    return 2;
}
bool BriquesIncassable::collision(Balle& balle){

    // If it's a collision
    if (balle.topY() < bottomY() && balle.bottomY() > topY() && balle.rightX() > leftX() && balle.leftX() < rightX()){
        double distanceX1 = abs(balle.rightX() - leftX());
        double distanceX2 = abs(balle.leftX() - rightX());
        double distanceY1 = abs(balle.topY() - bottomY());
        double distanceY2 = abs(balle.bottomY() - topY());

        // bas
        if (balle.direction().y() < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
            balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
        // haut
        if (balle.direction().y() > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2){
            balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
        // gauche

        if (balle.direction().x() > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2){
            balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
        // droite
        if (balle.direction().x() < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
            balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
    }
    return false;
}
