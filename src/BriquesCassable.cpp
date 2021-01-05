#include "BriquesCassable.h"

BriquesCassable::BriquesCassable(double x,double y,int vie):
    Briques{x,y},_vie{vie}
{
    //ctor
}

BriquesCassable::~BriquesCassable()
{
    //dtor
}
void BriquesCassable::afficher(int couleur,int style)const{
    if (couleur!= 0){
		setcolor(couleur);
		double x1= _position.x() - largeur() / 2 + 1;
		double y1= _position.y() - hauteur() / 2 + 1;
		double x2= _position.x() + largeur() / 2 - 1;
		double y2= _position.y() + hauteur() / 2 - 1;
		rectangle(x1,y1,x2,y2);
		setfillstyle(style,couleur);
		floodfill(x1+2,y1+2,couleur);
	}
}
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
     return 1;
}
bool BriquesCassable::collision(Balle& balle){

    if (_vie > 0){

        double ballTop = balle.position().y() - 10;
        double ballBottom = balle.position().y() + 10;
        double ballLeft = balle.position().x() - 10;
        double ballRight = balle.position().x() + 10;

        // If it's a collision
        if (ballTop < brickBottom() && ballBottom > brickTop() && ballRight > brickLeft() && ballLeft < brickRight()){
            double distanceX1 = abs(ballRight - brickLeft());
            double distanceX2 = abs(ballLeft - brickRight());
            double distanceY1 = abs(ballTop - brickBottom());
            double distanceY2 = abs(ballBottom - brickTop());

            // bas
            if (balle.direction().y() < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
                balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
                balle.ajusterVitesse(*this);
                _vie--;
                return true;
            }
            // haut
            if (balle.direction().y() > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2){
                balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
                balle.ajusterVitesse(*this);
                _vie --;
                return true;
            }
            // gauche

            if (balle.direction().x() > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2){
                balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
                balle.ajusterVitesse(*this);
                _vie --;
                return true;
            }
            // droite
            if (balle.direction().x() < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
                balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
                balle.ajusterVitesse(*this);
                _vie --;
                return true;
            }
        }else{return false;}
    }
    return false;
}

