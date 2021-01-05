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
void BriquesSansRobond::afficher(int couleur,int style)const{
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

int BriquesSansRobond::style()const{
    return 3;
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
