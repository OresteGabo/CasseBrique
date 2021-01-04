#pragma once
#ifndef CASSEBRIQUE_H
#define CASSEBRIQUE_H
#include<memory>
#include "Ball.h"
#include "Raquette.h"
#include "Briques.h"
#include<vector>
using std::vector;
using std::unique_ptr;
class Briques;
class Ball;
class Raquette;
class CasseBrique
{
public:
	CasseBrique();
	~CasseBrique();

	double positionSourie()const;
	void logique();

    Ball* balle()const;
    Raquette* raquette()const;
    vector<Briques> briques()const;
    bool tousLesBriquesCasses()const;
    bool balleTJREnJeux()const;

private:
	Ball* _balle;
	Raquette* _raquette;
	vector<Briques> _briques;
};


#endif // CASSEBRIQUE_H
