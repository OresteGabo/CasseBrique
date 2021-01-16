#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Cercle.h"
class Rectangle
{
    public:
        Rectangle(double l,double h,const Position&);
        virtual ~Rectangle();
        virtual double solidite()const =0;

        virtual int style()const=0;
        bool collision(const Cercle&)const;

        Position position()const;
        void position(const Position&);
        void positionX(double);
        void positionY(double);
        int largeur()const;
        int hauteur()const;
        void largeur(int);
        void hauteur(int);
        int couleur()const;
        void couleur(int);

        double topY()const;//{return _position.y() - _hauteur / 2;}
        double bottomY()const;//{return _position.y() + _hauteur / 2;}
        double leftX()const;//{return  _position.x() - _largeur / 2;}
        double rightX()const;//{return _position.x() + _largeur / 2;}

    protected:
        Position _position;
        int _largeur;
        int _hauteur;
        int _couleur;

    private:
};

#endif // RECTANGLE_H
