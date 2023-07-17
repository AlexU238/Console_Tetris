//
// Created by u238 on 7/17/23.
//

#include <csignal>
#include "Bar.h"
#include <iostream>

using namespace std;

void Bar::rotateRight(char (&matrix)[20][12]) {

}

void Bar::rotateLeft(char (&matrix)[20][12]) {

}

void Bar::fall(char (&matrix)[20][12]) {

    if(y1<19 && y4<19){
        matrix[y1][x1] = ' ';
        matrix[y2][x2] = ' ';
        matrix[y3][x3] = ' ';
        matrix[y4][x4] = ' ';

        matrix[++y1][x1] = '0';
        matrix[++y2][x2] = '0';
        matrix[++y3][x3] = '0';
        matrix[++y4][x4] = '0';
    }

}

void Bar::moveRight(char (&matrix)[20][12]) {
    if(x1>0 && x4<10){
        matrix[y1][x1] = ' ';
        matrix[y2][x2] = ' ';
        matrix[y3][x3] = ' ';
        matrix[y4][x4] = ' ';
        matrix[y1][++x1] = '0';
        matrix[y2][++x2] = '0';
        matrix[y3][++x3] = '0';
        matrix[y4][++x4] = '0';
    }

}

void Bar::moveLeft(char (&matrix)[20][12]) {
    if(x1>1 && x4<10){
        matrix[y1][x1] = ' ';
        matrix[y2][x2] = ' ';
        matrix[y3][x3] = ' ';
        matrix[y4][x4] = ' ';
        matrix[y1][--x1] = '0';
        matrix[y2][--x2] = '0';
        matrix[y3][--x3] = '0';
        matrix[y4][--x4] = '0';
    }
}

void Bar::appear(char (&matrix)[20][12]) {
    x1=3;
    x2=x1+1;
    x3=x2+1;
    x4=x3+1;
    y1=y2=y3=y4=0;
    matrix[y1][x1] = '0';
    matrix[y2][x2] = '0';
    matrix[y3][x3] = '0';
    matrix[y4][x4] = '0';
}

bool Bar::collide(char (&matrix)[20][12]) {
    return ((matrix[y1+1][x1]=='0' && (y1+1)!=y2) || (matrix[y4+1][x4]==0 && (y4+1)!=y3));
}

void Bar::heYo() {
    cout<<"Yo, bar"<<endl;
}

bool Bar::stopFall(char (&matrix)[20][12]) {
    return ((y1+1)==20 || (y4+1)==20 );
}


