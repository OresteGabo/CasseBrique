#pragma once
#ifndef CERCLE_H
#define CERCLE_H
#include"Rectangle.h"
#include<cmath>
#include<iostream>

enum SIDE{NORD,EST,SUD,OUEST};
//class Rectangle;
class Cercle{
    public:
        /** Default constructor */
        Cercle(double,const Position&);
        /** Default destructor */
        virtual ~Cercle();
        double rayon()const;
        double diametre()const;
        double circonference()const;
        double surface()const;
        Position position()const;
        //bool collidedRectangle(const Rectangle&r,SIDE&)const;

    protected:
        double _rayon;
        Position _position;
    private:
        void rayon(double);

};

#endif // CERCLE_H
