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

        void afficher(Ball*)const;
        void afficher(const std::vector<Briques>& br)const;
        void afficher(Raquette*)const;

};

#endif // AFFICHEURWINBGI_H
