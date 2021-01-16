#pragma once
#ifndef BRIQUESINCASSABLES_H
#define BRIQUESINCASSABLES_H
#include"Briques.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
class BriquesCassable:public Briques
{
    public:
        /** Default constructor */
        BriquesCassable(double,double,int);
        /** Default destructor */
        virtual ~BriquesCassable();
        virtual bool vivant()const override;
        virtual bool utilisable()const override;
        virtual double solidite()const override;
        virtual int style()const override;
        virtual bool collision(Cercle&)override;

    protected:
        int _vie;
    private:


};

#endif // BRIQUESINCASSABLES_H
