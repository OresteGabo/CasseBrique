#pragma once
#ifndef BRIQUES_H
#define BRIQUES_H
#include"Position.h"
#include"Balle.h"
#include <graphics.h>
#include<iostream>
#include"Rectangle.h"
using namespace std;

class Briques:public Rectangle
{
    public:
        /** Default constructor */
        Briques(double,double);
        /** Default destructor */
        virtual ~Briques();

        virtual bool vivant()const=0;
        virtual bool utilisable()const=0;

        virtual double solidite()const =0;
        virtual int style()const=0;
        virtual void agirCollision(Cercle&)=0;


};

#endif // BRIQUES_H
