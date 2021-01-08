#include "BriquesCassable.h"

BriquesCassable::BriquesCassable(double x,double y,int vie):
    Briques{x,y},_vie{vie}
{}
BriquesCassable::~BriquesCassable(){}
bool BriquesCassable::vivant()const{
    return _vie>0;
}
double BriquesCassable::solidite()const{
    if(_vie==1){
        return 0.75;
    }
    else if(_vie==2){
        return 1;
    }else if(_vie==3){
        return 1.25;
    }
    return 1;
}
int BriquesCassable::couleur()const{
     switch(_vie) {
      case 3 :
          return 2;//GREEN
         break;
      case 2 :
          return 6;//BROWN
         break;
      case 1 :
          return 4;//RED
         break;
      case 0 :
          return 0;//BLACK
         break;
      default :
          return 2;//GREEN
   }
}

int BriquesCassable::style()const{
     return 11;
}
bool BriquesCassable::collision(Balle& balle){
    if (_vie > 0){
        // si il y a la collision
        if (balle.topY() < bottomY() && balle.bottomY() > topY() && balle.rightX() > leftX() && balle.leftX() < rightX()){
            double distanceX1 = abs(balle.rightX() - leftX());
            double distanceX2 = abs(balle.leftX() - rightX());
            double distanceY1 = abs(balle.topY() - bottomY());
            double distanceY2 = abs(balle.bottomY() - topY());

            //haut
            if (balle.direction().y() > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2){
                balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
                balle.ajusterVitesse(*this);
                --_vie;
                return true;
            }

            // bas
            if (balle.direction().y() < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
                balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
                balle.ajusterVitesse(*this);
                --_vie;
                return true;
            }

            // gauche

            if (balle.direction().x() > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2){
                balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
                balle.ajusterVitesse(*this);
                --_vie;
                return true;
            }
            // droite
            if (balle.direction().x() < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
                balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
                balle.ajusterVitesse(*this);
                --_vie;
                return true;
            }
        }else{return false;}
    }
    return false;
}
