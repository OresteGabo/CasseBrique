#pragma once
#ifndef POSITION_H
#define POSITION_H
#include<cmath>

class Position
{
    public:
        Position(double x,double y);
        Position(double xy);
        Position();

        virtual ~Position();
        double x()const;
        double y()const;
        void x(double);
        void y(double);
        void xy(double x,double y);
        double distance(const Position& p)const;
        double distance(int x,int y)const;

    protected:

    private:
        double _x;
        double _y;
};

#endif // POSITION_H
