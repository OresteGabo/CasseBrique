#include "BriquesSansRobond.h"

BriquesSansRobond::BriquesSansRobond(double x,double y,int v):
    BriquesCassable{x,y,v}
{}
BriquesSansRobond::~BriquesSansRobond()
{}

int BriquesSansRobond::style()const{
    return 8;
}
bool BriquesSansRobond::collision(Balle& balle){
    if (_vie > 0){
        // si il y a la collision
        if (balle.topY() < bottomY() && balle.bottomY() > topY() && balle.rightX() > leftX() && balle.leftX() < rightX()){
            balle.direction(Position(-1*balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            _vie --;
            return true;
        }
    }
    return false;
}
