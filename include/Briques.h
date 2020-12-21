#ifndef BRIQUES_H
#define BRIQUES_H
#include "Position.h"
#include "Ball.h"
class Ball;
class Briques
{
public:
	Briques(double xPos, double yPos,int);
	~Briques();
	void afficher()const;
	bool BallCollision(Ball*ball);
    int couleur()const;
    int vie()const;
    int compteur()const;


    double brickTop()const{return _brickTop;}// = _position.y() - HAUTEUR_BRIQUE / 2;
    double brickBottom()const{return _brickBottom;}// = _position.y() + HAUTEUR_BRIQUE / 2;
    double brickLeft()const{return _brickLeft;}// = _position.x() - LARGEUR_BRIQUE / 2;
    double brickRight()const{return _brickRight;}// = _position.x() + LARGEUR_BRIQUE / 2;

private:
    Position _position;
	int _vie;

    /******
    Le compteur pour facilit� la suppression d'une brique dans un vecteur
    */
    int _compteur;
    static int _compteurStatique;
	/**Les variables calculable**/
	double _brickTop;// = _position.y() - HAUTEUR_BRIQUE / 2;
    double _brickBottom;// = _position.y() + HAUTEUR_BRIQUE / 2;
    double _brickLeft;// = _position.x() - LARGEUR_BRIQUE / 2;
    double _brickRight;// = _position.x() + LARGEUR_BRIQUE / 2;
};



#endif // BRIQUES_H
