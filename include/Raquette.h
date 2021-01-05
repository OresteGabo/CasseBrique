#pragma once
#ifndef RAQUETTE_H
#define RAQUETTE_H
#include<graphics.h>
#include "Position.h"

class Raquette{
public:
	Raquette(double);
	~Raquette();

	void repositionnerX(int);
	Position position()const;
	int largeur()const;
	int hauteur()const;



private:
    int _largeur= 100;
    int _hauteur=10;
    Position _position;

};



#endif // RAQUETTE_H
