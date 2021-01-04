#ifndef BRIQUESCASSABLES_H
#define BRIQUESCASSABLES_H
#include "Briques.h"

class BriquesCassables//:public Briques
{
    public:
        /** Default constructor */
        BriquesCassables();
        /** Default destructor */
        virtual ~BriquesCassables();


    private:
        int _vie;
};

#endif // BRIQUESCASSABLES_H
