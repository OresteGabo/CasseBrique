#pragma once
#ifndef RAQUETTE_H
#define RAQUETTE_H
#include"CasseBrique.h"
#include<graphics.h>
#include "Position.h"



class Raquette{
public:
	Raquette(double);
	~Raquette();

	void repositionnerX(int);
	Position position()const;
	int largeur()const;
	//int hauteur()const;



private:
    Position _position;
};



#endif // RAQUETTE_H
