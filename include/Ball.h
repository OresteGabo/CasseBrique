#ifndef BALL_H
#define BALL_H
#include"Position.h"
#include <ctime>
#include<graphics.h>
#include "Raquette.h"
#include "CasseBrique.h"
#include"constVariables.h"
class Ball{
public:
	Ball();
	~Ball();

	void avancer(double);
	void CheckHitsRaquette(double paddleX);
	bool IsOutside();
	Position position()const;
	void position(const Position&);
	Position speed()const;
	void speed(const Position&);
	void afficher()const;
	inline int rayon()const{return _rayon;}




private:
    Position _position;
	Position _speed;
    int _rayon;



};

#endif // BALL_H
