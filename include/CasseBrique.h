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
    void supprimerBrique(int);
    void MAJ();
    Ball* balle()const;
    Raquette* raquette()const;
    vector<Briques> briques()const;
    bool tousLesBriquesCasses()const;
    bool balleTJREnJeux()const;
    void collisionBalleRaquette();
private:
	Ball* _balle;
	Raquette* _raquette;
	vector<Briques> _briques;
	//bool _playing;
};


#endif // CASSEBRIQUE_H
