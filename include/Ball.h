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
//#include"Application.h"
//class Application;
class Ball:public Cercle{
public:
	Ball(double);
	~Ball();

	void avancer(double);
	void CheckHitsRaquette(double);
	Position position()const;
	void position(const Position&);
	Position vitesse()const;
	void vitesse(const Position&);
	inline int rayon()const{return _rayon;}




private:
	Position _vitesse;
};

#endif // BALL_H
