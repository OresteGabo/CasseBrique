#pragma once
#ifndef BRIQUESSANSROBOND_H
#define BRIQUESSANSROBOND_H

#include "BriquesCassable.h"


class BriquesSansRobond : public BriquesCassable
{
    public:
        BriquesSansRobond(double x,double y,int v);
        virtual ~BriquesSansRobond();
        virtual int style()const override;
        virtual void agirCollision(Cercle&)override;
};

#endif // BRIQUESSANSROBOND_H
