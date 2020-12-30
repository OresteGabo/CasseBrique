#include "Briques.h"

Briques::Briques(double xPos, double yPos,int vie=2):_position{Position(xPos,yPos)},_vie{vie},
_brickTop { _position.y() - HAUTEUR_BRIQUE / 2},
_brickBottom { _position.y() + HAUTEUR_BRIQUE / 2},
_brickLeft { _position.x() - LARGEUR_BRIQUE / 2},
_brickRight { _position.x() + LARGEUR_BRIQUE / 2}
{
    _compteur=_compteurStatique++;
}


Briques::~Briques(){}
int Briques::_compteurStatique=0;
bool Briques::BallCollision(Ball*ball){
	if (_vie > 0){

		double ballTop = ball->position().y() - 10;
		double ballBottom = ball->position().y() + 10;
		double ballLeft = ball->position().x() - 10;
		double ballRight = ball->position().x() + 10;

		// If it's a collision
		if (ballTop < brickBottom() && ballBottom > brickTop() && ballRight > brickLeft() && ballLeft < brickRight()){
			double distanceX1 = abs(ballRight - brickLeft());
			double distanceX2 = abs(ballLeft - brickRight());
			double distanceY1 = abs(ballTop - brickBottom());
			double distanceY2 = abs(ballBottom - brickTop());

            // From bottom
			if (ball->speed().y() < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
				ball->speed().y( abs(ball->speed().y()));
				_vie--;
				return true;
			}
			// From top
			if (ball->speed().y() > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2)
			{
				ball->speed().y( -abs(ball->speed().y()));
				_vie --;
				return true;
			}
			// From left
			if (ball->speed().x() > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2)
			{
				ball->speed().x(-abs(ball->speed().x()));
				_vie --;
				return true;
			}
			// From right
			if (ball->speed().x() < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
				ball->speed().x(abs(ball->speed().x()));
				_vie --;
				return true;
			}
		}else{return false;}
	}
    return false;

}


int Briques::couleur()const{
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
int Briques::vie()const{return _vie;}
int Briques::compteur()const{return _compteur;}
Position Briques::position()const{return _position;}
int Briques::largeurBrique()const{
    return LARGEUR_BRIQUE;
}
int Briques::hauteurBrique()const{
    return HAUTEUR_BRIQUE;
}
