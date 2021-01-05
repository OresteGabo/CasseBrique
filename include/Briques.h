#ifndef BRIQUES_H
#define BRIQUES_H
#include"Position.h"
#include"Balle.h"
#include <graphics.h>
class Balle;
class Briques
{
    public:
        /** Default constructor */
        Briques(double,double);
        /** Default destructor */
        virtual ~Briques();

        virtual bool vivant()const=0;
        virtual double solidite()const =0;
        virtual int couleur()const=0;
        virtual int style()const=0;
        virtual bool collision(Balle&)=0;


        Position position()const;
        void position(const Position&);
        int largeur()const;
        int hauteur()const;
        void largeur(int);
        void hauteur(int);



    protected:
        double brickTop()const{return _position.y() - _hauteur / 2;}
        double brickBottom()const{return _position.y() + _hauteur / 2;}
        double brickLeft()const{return  _position.x() - _largeur / 2;}
        double brickRight()const{return _position.x() + _largeur / 2;}
        Position _position;
    private:
        int _largeur=40;
        int _hauteur=20;

};

#endif // BRIQUES_H
