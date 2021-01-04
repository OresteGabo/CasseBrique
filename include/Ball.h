#pragma once
#ifndef BALL_H
#define BALL_H
#include"Position.h"
#include <ctime>
#include<graphics.h>
#include "Raquette.h"
#include "CasseBrique.h"
#include"constVariables.h"
#include"Cercle.h"
#include"Briques.h"
class Raquette;
class Ball:public Cercle{
public:
	Ball(double);
	~Ball();

	void avancer();
	void collision(const Raquette&r);

	Position position()const;
	void position(const Position&);
	Position direction()const;
	void direction(const Position&);
	inline int rayon()const{return _rayon;}
	void vitesse(double);
	double vitesse()const;
	void ajusterVitesse(int);

private:
	Position _direction;
	double _vitesse;
};

#endif // BALL_H
