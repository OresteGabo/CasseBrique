#include "AfficheurWinbgi.h"
AfficheurWinbgi::AfficheurWinbgi()
{
}
AfficheurWinbgi::~AfficheurWinbgi()
{
}
void AfficheurWinbgi::afficher(CasseBrique* _cassebrique)const{
    afficherBalle(_cassebrique);
    afficherBriques(_cassebrique);
    afficherRaquette(_cassebrique);
}
void AfficheurWinbgi::afficherBalle(CasseBrique* _cassebrique)const{

    Ball* b=_cassebrique->balle();
    setcolor(LIGHTCYAN);
	circle(b->position().x(),b->position().y(),b->rayon());
    setfillstyle(SOLID_FILL,LIGHTCYAN);
	//floodfill(_cassebrique->balle()->position().x(),_cassebrique->balle()->position().y(),LIGHTCYAN);
}
void AfficheurWinbgi::afficherBriques(CasseBrique* _cassebrique)const{
    int taille=_cassebrique->briques().size();
    for(int x=0;x<taille;x++){
        Briques b=_cassebrique->briques()[x];
        if (b.vie() > 0){
            setcolor(b.couleur());
			double x1= b.position().x() - b.largeurBrique() / 2 + 1;
			double y1= b.position().y() - b.hauteurBrique() / 2 + 1;
			double x2= b.position().x() + b.largeurBrique() / 2 - 1;
			double y2= b.position().y() + b.hauteurBrique() / 2 - 1;
			rectangle(x1,y1,x2,y2);
            setfillstyle(SOLID_FILL,b.couleur());
            floodfill(x1+2,y1+2,b.couleur());
        }
    }
}
void AfficheurWinbgi::afficherRaquette(CasseBrique* _cassebrique)const{
    setcolor(GREEN);
    Raquette *r=_cassebrique->raquette();
    double x1= r->position().x() - r->largeur() / 2;
    double y1= r->position().y() - 5;
    double x2= r->position().x() + r->largeur() / 2;
    double y2= r->position().y() + 5;
    rectangle(x1,y1,x2,y2);
}
