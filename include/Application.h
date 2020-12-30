#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H
#include "CasseBrique.h"
#include<chrono>
#include<iostream>
using namespace std;
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
        void afficheBrique();
        void afficheBalle();
        void afficheMenu();

        CasseBrique _cassebrique;
        Raquette _raquette;
        double _tempsExec;
        int _resolutionX,_resolutionY;
};

#endif // APPLICATION_H
