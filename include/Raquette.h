#pragma once
#ifndef RAQUETTE_H
#define RAQUETTE_H
#include<graphics.h>
#include "Position.h"

class Raquette{
public:
	Raquette(double);
	~Raquette();

	void positionnerX(int);
	Position position()const;
	int largeur()const;
	int hauteur()const;



private:
    int _largeur;
    int _hauteur;
    Position _position;

};



#endif // RAQUETTE_H
