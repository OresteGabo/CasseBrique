#pragma once
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
	bool BallCollision(Ball*);
    int couleur()const;
    int vie()const;
    int compteur()const;
    Position position()const;
    int largeurBrique()const;
    int hauteurBrique()const;


    double brickTop()const{return _brickTop;}// = _position.y() - HAUTEUR_BRIQUE / 2;
    double brickBottom()const{return _brickBottom;}// = _position.y() + HAUTEUR_BRIQUE / 2;
    double brickLeft()const{return _brickLeft;}// = _position.x() - LARGEUR_BRIQUE / 2;
    double brickRight()const{return _brickRight;}// = _position.x() + LARGEUR_BRIQUE / 2;

private:
    Position _position;
	int _vie;

    /******
    Le compteur pour facilité la suppression d'une brique dans un vecteur
    */
    int _compteur;
    static int _compteurStatique;
	/**Les variables calculable**/
	double _brickTop;// = _position.y() - HAUTEUR_BRIQUE / 2;
    double _brickBottom;// = _position.y() + HAUTEUR_BRIQUE / 2;
    double _brickLeft;// = _position.x() - LARGEUR_BRIQUE / 2;
    double _brickRight;// = _position.x() + LARGEUR_BRIQUE / 2;


    static const int LARGEUR_BRIQUE=40;
    static const int HAUTEUR_BRIQUE=20;
};



#endif // BRIQUES_H
