#include "Position.h"

Position::Position(double x,double y):
    _x{x},
    _y{y}
{
}
Position::Position(double xy):
    Position{xy,xy}
{}
Position::Position():
    Position{0.0,0.0}
{}
void Position::x(double val){
    _x=val;
}
void Position::y(double val){
    _y=val;
}
void Position::xy(double x,double y){
    _x=x;
    _y=y;
}
double Position::x()const{return _x;}
double Position::y()const{return _y;}
double Position::distance(const Position& p)const{
    return sqrt(
                ((_x-p.x())*(_x-p.x()))
                            +
                ((_y-p.y())*(_y-p.y()))
            );
}
double Position::distance(int x,int y)const{
    return sqrt((_x-x)*(_x-x) + (_y-y)*(_y-y));
}
Position::~Position()
{}
