#pragma once
#ifndef CASSEBRIQUE_H
#define CASSEBRIQUE_H
#include<memory>
#include "Balle.h"
#include "Raquette.h"
#include "Briques.h"
#include "BriquesIncassable.h"
#include "BriquesSansRobond.h"
#include "BriquesCassable.h"
#include<vector>
using std::vector;
using std::unique_ptr;
using namespace std;
class Briques;
class Balle;
class Raquette;
class CasseBrique
{
public:
	CasseBrique();
	~CasseBrique();

	double positionSourie()const;
	void logique();

    const Balle& balle()const;
    const Raquette& raquette()const;
    vector<Briques*> briques()const;
    bool tousLesBriquesCasses()const;
    bool balleTJREnJeux()const;

private:
	Balle _balle;
	Raquette _raquette;
	vector<Briques*> _briques;
	void detruireBriques();
};


#endif // CASSEBRIQUE_H
