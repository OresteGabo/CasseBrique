#pragma once
#ifndef CERCLE_H
#define CERCLE_H
#include<cmath>
#include<iostream>
#include"Position.h"
#include"../variableGlobale.h"

class Cercle{
    public:
        Cercle(double,const Position&,int);
        virtual ~Cercle();
        double rayon()const;
        double surface()const;
        Position position()const;
        void position(const Position&);
        void rayon(double val);
        double diametre()const;
        int couleur()const;
        void couleur(int);



        double topY()const;
        double bottomY()const;
        double leftX()const;
        double rightX()const;

    protected:
        double _rayon;
        Position _position;
        int _couleur;

};

#endif // CERCLE_H
