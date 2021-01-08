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
	CasseBrique(int resolutionX,int resolutionY);
	~CasseBrique();

	double positionSourie()const;
	void logique();

    const Balle& balle()const;
    const Raquette& raquette()const;
    vector<Briques*> briques()const;
    bool tousLesBriquesCasses()const;
    bool balleTJREnJeux()const;
    void avancer();
    void initialiser();
    void decharger();
    void charger(int c=1);

private:
	Balle _balle;
	Raquette _raquette;
	vector<Briques*> _briques;
	void detruireBriques();
	int _resolutionX;
	int _resolutionY;

	void charger1();
	void charger2();
	void charger3();
};

#endif // CASSEBRIQUE_H
