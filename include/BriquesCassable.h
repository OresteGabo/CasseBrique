#ifndef BRIQUESCASSABLE_H
#define BRIQUESCASSABLE_H
#include"Briques.h"
#include "Position.h"
#include "Ball.h"
class Ball;
class BriquesCassable:public Briques{
    public:
        /** Default constructor */
        BriquesCassable(double xPos, double yPos,int );
        /** Default destructor */
        virtual ~BriquesCassable();

        //virtual bool BallCollision(Ball*)override;
        //virtual void afficher()const override;
        int couleur()const;

    protected:

    private:
        int _vie;
};

#endif // BRIQUESCASSABLE_H
