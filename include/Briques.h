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
    Position position()const;
    int largeur()const;
    int hauteur()const;
	void afficher()const;


    double brickTop()const{return _position.y() - HAUTEUR_BRIQUE / 2;}
    double brickBottom()const{return _position.y() + HAUTEUR_BRIQUE / 2;}
    double brickLeft()const{return  _position.x() - LARGEUR_BRIQUE / 2;}
    double brickRight()const{return _position.x() + LARGEUR_BRIQUE / 2;}

private:
    Position _position;
	int _vie;
    static const int LARGEUR_BRIQUE=40;
    static const int HAUTEUR_BRIQUE=20;
};



#endif // BRIQUES_H
