#pragma once
#ifndef RAQUETTE_H
#define RAQUETTE_H
#include<graphics.h>
#include "Position.h"
#include"Rectangle.h"
class Raquette:public Rectangle
{
public:
	Raquette(double x=100,double y=10,const Position&p=Position(0,0));
	~Raquette();
	virtual double solidite()const override;
    virtual int style()const override;
    void collision(Cercle&);

};

#endif // RAQUETTE_H
