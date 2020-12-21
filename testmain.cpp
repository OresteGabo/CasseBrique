/** main.cpp content*/

#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include"Application.h"


int main( ){
    initwindow( RESOLUTION_X , RESOLUTION_Y , "WinBGIm Demo" );
    Application app;
    closegraph();
    return 0 ;
}

/*

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
*/
