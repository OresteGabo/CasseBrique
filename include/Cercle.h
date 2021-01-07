#pragma once
#ifndef CERCLE_H
#define CERCLE_H
#include<cmath>
#include<iostream>
#include"Position.h"
class Cercle{
    public:
        Cercle(double,const Position&);
        virtual ~Cercle();
        double rayon()const;
        double surface()const;
        Position position()const;
        void rayon(double val);
        double diametre()const;

        double topY()const;
        double bottomY()const;
        double leftX()const;
        double rightX()const;

    protected:
        double _rayon;
        Position _position;

};

#endif // CERCLE_H
