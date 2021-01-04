#include "BriquesCassable.h"

BriquesCassable::BriquesCassable(double xPos, double yPos,int vie):
    Briques{xPos,yPos},
    _vie{vie}
{
}

BriquesCassable::~BriquesCassable()
{
}
bool BriquesCassable::collision(Ball* balle){
    if (_vie > 0){

		double ballTop = balle->position().y() - 10;
		double ballBottom = balle->position().y() + 10;
		double ballLeft = balle->position().x() - 10;
		double ballRight = balle->position().x() + 10;

		// If it's a collision
		if (ballTop < brickBottom() && ballBottom > brickTop() && ballRight > brickLeft() && ballLeft < brickRight()){
			double distanceX1 = abs(ballRight - brickLeft());
			double distanceX2 = abs(ballLeft - brickRight());
			double distanceY1 = abs(ballTop - brickBottom());
			double distanceY2 = abs(ballBottom - brickTop());

            // bas
			if (balle->direction().y() < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
				balle->direction(Position(balle->direction().x(),-1*balle->direction().y()));
				balle->ajusterVitesse(_vie);
				_vie--;
				return true;
			}
			// haut
			if (balle->direction().y() > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2){
				balle->direction(Position(balle->direction().x(),-1*balle->direction().y()));
				balle->ajusterVitesse(_vie);
				_vie --;
				return true;
			}
			// gauche

			if (balle->direction().x() > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2){
				balle->direction(Position(-1*balle->direction().x(),balle->direction().y()));
				balle->ajusterVitesse(_vie);
				_vie --;
				return true;
			}
			// droite
			if (balle->direction().x() < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
				balle->direction(Position(-1*balle->direction().x(),balle->direction().y()));
				balle->ajusterVitesse(_vie);
				_vie --;
				return true;
			}
		}else{return false;}
	}
    return false;
}
int BriquesCassable::couleur()const{
    switch(_vie) {
      case 3 :
          return GREEN;
         break;
      case 2 :
          return BROWN;
         break;
      case 1 :
          return RED;
         break;
      case 0 :
          return BLACK;
         break;
      default :
          return GREEN;
   }
}
int BriquesCassable::vie()const{
    return _vie;
}
void BriquesCassable::afficher()const{

	if (_vie > 0){
		setcolor(couleur());
		double x1= _position.x() - largeur() / 2 + 1;
		double y1= _position.y() - hauteur() / 2 + 1;
		double x2= _position.x() + largeur() / 2 - 1;
		double y2= _position.y() + hauteur() / 2 - 1;
		rectangle(x1,y1,x2,y2);
		setfillstyle(SOLID_FILL,couleur());
		floodfill(x1+2,y1+2,couleur());
	}
}

