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
	void CheckHitsRaquette(double paddleX);
	bool IsOutside();
	Position position()const;
	void position(const Position&);
	Position speed()const;
	void speed(const Position&);
	inline int rayon()const{return _rayon;}




private:
    //Position _position;
	Position _speed;
    //double _rayon;



};

#endif // BALL_H
