#ifndef BRIQUESCASSABLE_H
#define BRIQUESCASSABLE_H
#include "Position.h"
#include "Ball.h"
class Ball;

class BriquesCassable:public Briques
{
    public:
        /** Default constructor */
        BriquesCassable(double xPos, double yPos,int);
        /** Default destructor */
        virtual ~BriquesCassable();
        virtual bool collision(Ball*);
        int couleur()const;
        int vie()const;
        virtual void afficher()const;

    protected:

    private:
        int _vie;
};

#endif // BRIQUESCASSABLE_H
