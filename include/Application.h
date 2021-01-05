#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H
#include "CasseBrique.h"
#include<chrono>
#include<iostream>
#include<memory>
#include<iostream>
using namespace std;
using std::vector;
using std::unique_ptr;
using std::make_unique;
class Application
{
    public:
        Application();
        virtual ~Application();
        void executer();
        long initialiser();
        void mvtRaquette();
        int resolutionX()const;
        int resolutionY()const;

        void resolutionX(int);
        void resolutionY(int);

    protected:

    private:
        void afficherParametres();
        void afficheMenuBrique();
        void afficheMenuBalle();
        void afficheMenu();
        void finirLeJeux();

        void afficher(const Balle&)const;
        void afficher(const vector<Briques*> br)const;
        void afficher(const Raquette&)const;
        void afficher()const;

        CasseBrique* _cassebrique;
        Raquette* _raquette;
        double _tempsExec;
        int _resolutionX,_resolutionY;
};

#endif // APPLICATION_H
