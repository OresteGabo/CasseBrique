#ifndef APPLICATION_H
#define APPLICATION_H
#include "CasseBrique.h"
#include<chrono>
class Application
{
    public:
        Application();
        virtual ~Application();
        void execute();
        long initialiser();
        void mvtRaquette();

    protected:

    private:
        CasseBrique _cassebrique;
        Raquette _raquette;
};

#endif // APPLICATION_H
