#pragma once
#ifndef RAQUETTE_H
#define RAQUETTE_H
#include"CasseBrique.h"
#include<graphics.h>
#include "Position.h"



class Raquette{
public:
	Raquette(double y);
	~Raquette();

	void repositionnerX(int xPos);
	void afficher()const;
	Position position()const;



private:
    Position _position;
};



#endif // RAQUETTE_H
