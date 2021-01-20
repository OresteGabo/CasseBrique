#pragma once
#ifndef BRIQUESINCASSABLE_H
#define BRIQUESINCASSABLE_H

#include <Briques.h>


class BriquesIncassable : public Briques
{
    public:
        /** Default constructor */
        BriquesIncassable(double,double);
        /** Default destructor */
        virtual ~BriquesIncassable();
        virtual bool vivant()const override;
        virtual bool utilisable()const override;
        virtual double solidite()const override;
        virtual int style()const override;
        virtual void agirCollision(Cercle&)override;
};

#endif // BRIQUESINCASSABLE_H
