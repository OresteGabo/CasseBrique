#include "BriquesSansRobond.h"

BriquesSansRobond::BriquesSansRobond(double x,double y,int v):
    BriquesCassable{x,y,v}
{
    //ctor
}

BriquesSansRobond::~BriquesSansRobond()
{
    //dtor
}

int BriquesSansRobond::style()const{
    return 8;
}
bool BriquesSansRobond::collision(Balle& balle){
    if (_vie > 0){

        double ballTop = balle.position().y() - 10;
        double ballBottom = balle.position().y() + 10;
        double ballLeft = balle.position().x() - 10;
        double ballRight = balle.position().x() + 10;

        // If it's a collision
        if (ballTop < brickBottom() && ballBottom > brickTop() && ballRight > brickLeft() && ballLeft < brickRight()){
            balle.direction(Position(-1*balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            _vie --;
            return true;
        }
    }
    return false;
}
