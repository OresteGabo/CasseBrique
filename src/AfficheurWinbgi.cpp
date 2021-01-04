#include "AfficheurWinbgi.h"
AfficheurWinbgi::AfficheurWinbgi()
{
}
AfficheurWinbgi::~AfficheurWinbgi()
{
}
void AfficheurWinbgi::afficher(CasseBrique* _cassebrique)const{
    afficher(_cassebrique->balle());
    afficher(_cassebrique->raquette());
    afficher(_cassebrique->briques());
}
void AfficheurWinbgi::afficher(Ball* b)const{

    setcolor(LIGHTCYAN);
	circle(b->position().x(),b->position().y(),b->rayon());
    setfillstyle(SOLID_FILL,LIGHTCYAN);
	//floodfill(_cassebrique->balle()->position().x(),_cassebrique->balle()->position().y(),LIGHTCYAN);
}
void AfficheurWinbgi::afficher(const std::vector<Briques>& b)const{

    for(unsigned int x=0;x<b.size();x++){
        b[x].afficher();
    }
}
void AfficheurWinbgi::afficher(Raquette* r)const{
    double x1= r->position().x() - r->largeur() / 2;
    double y1= r->position().y() - 5;
    double x2= r->position().x() + r->largeur() / 2;
    double y2= r->position().y() + 5;
    rectangle(x1,y1,x2,y2);
}
