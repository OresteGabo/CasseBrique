#pragma once
#ifndef BRIQUES_H
#define BRIQUES_H
#include "Position.h"
#include "Ball.h"
class Ball;
class Briques
{
public:
	Briques(double xPos, double yPos);
	~Briques();
	virtual bool collision(Ball*);
	virtual void afficher()const;
    int couleur()const;
    int vie()const;
    Position position()const;
    int largeur()const;
    int hauteur()const;



    double brickTop()const{return _position.y() - HAUTEUR_BRIQUE / 2;}
    double brickBottom()const{return _position.y() + HAUTEUR_BRIQUE / 2;}
    double brickLeft()const{return  _position.x() - LARGEUR_BRIQUE / 2;}
    double brickRight()const{return _position.x() + LARGEUR_BRIQUE / 2;}
protected:
    Position _position;
private:

	//int _vie;
    static const int LARGEUR_BRIQUE=40;
    static const int HAUTEUR_BRIQUE=20;
};



#endif // BRIQUES_H
