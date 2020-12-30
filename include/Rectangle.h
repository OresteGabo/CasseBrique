
#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Position.h"
#include"Cercle.h"
class Cercle;
class Rectangle
{
    public:
        /** Default constructor */
        Rectangle(double l,double h,const Position& p);
        /** Default destructor */
        virtual ~Rectangle();
        double hauteur()const;
        double largeur()const;

        void hauteur(double);
        void largeur(double);
        bool collision(const Rectangle& r,int&)const;
        bool collision(const Cercle& r,int&)const;
        Position position()const;
        void position(const Position&);

    protected:
        double _hauteur,_largeur;
        Position _position;

    private:
};

#endif // RECTANGLE_H
