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
	int hauteur()const;



private:
    Position _position;
    static const int LARGEUR_RAQUETTE_PAR_DEFAUT= 100;
    static const int HAUTEUR_RAQUETTE_PAR_DEFAUT=10;
};



#endif // RAQUETTE_H
