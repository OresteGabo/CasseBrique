#pragma once
#ifndef POSITION_H
#define POSITION_H
#include<cmath>

class Position
{
    public:
        Position(double,double);
        Position(double);
        Position();

        virtual ~Position();
        double x()const;
        double y()const;
        void x(double);
        void y(double);
        void xy(double,double);
        double distance(const Position&)const;
        double distance(int,int)const;

    private:
        double _x;
        double _y;
};

#endif // POSITION_H
