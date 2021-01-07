#pragma once
#ifndef BALLE_H
#define BALLE_H
#include"Position.h"
#include <ctime>
#include<graphics.h>
#include "Raquette.h"
//#include "CasseBrique.h"
//#include"constVariables.h"
#include"Cercle.h"
#include"Briques.h"
//class Raquette;
class Briques;
class Balle:public Cercle{
public:
	Balle(double);
	~Balle();

	void avancer();
	void collision(const Raquette&r);

	Position position()const;
	void position(const Position&);
	Position direction()const;
	void direction(const Position&);
	void vitesse(double);
	double vitesse()const;
	void ajusterVitesse(const Briques& br);
	int couleur()const;
	void couleur(int);


private:
	Position _direction;
	double _vitesse;
	int _couleur;
};

#endif // BALLE_H
