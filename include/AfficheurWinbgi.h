#ifndef AFFICHEURWINBGI_H
#define AFFICHEURWINBGI_H
#include"CasseBrique.h"

class AfficheurWinbgi
{
    public:
        /** Default constructor */
        AfficheurWinbgi();
        /** Default destructor */
        ~AfficheurWinbgi();
        void afficher(CasseBrique*)const;
    protected:

    private:
        //CasseBrique* _cassebrique;

        void afficherBalle(CasseBrique*)const;
        void afficherBriques(CasseBrique*)const;
        void afficherRaquette(CasseBrique*)const;

};

#endif // AFFICHEURWINBGI_H
