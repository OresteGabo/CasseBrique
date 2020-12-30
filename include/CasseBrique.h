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
	void logique(double tempsMS);
    void supprimerBrique(int);
    void MAJ();
    Ball* balle()const;
    Raquette* raquette()const;
    vector<Briques> briques()const;
private:
	Ball* _ball;
	Raquette* _raquette;
	vector<Briques> _briques;
	bool _playing;
};


#endif // CASSEBRIQUE_H
