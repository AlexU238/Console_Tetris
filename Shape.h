//
// Created by u238 on 7/17/23.
//

#ifndef TERMINAL_GAME_SHAPE_H
#define TERMINAL_GAME_SHAPE_H

#include <iostream>
using namespace std;

class Shape {

public:

    virtual void rotateRight(char (&matrix)[20][12]) = 0;

    virtual void rotateLeft(char (&matrix)[20][12]) = 0;

    virtual void fall(char (&matrix)[20][12]) = 0;

    virtual void moveRight(char (&matrix)[20][12]) = 0;

    virtual void moveLeft(char (&matrix)[20][12]) = 0;

    virtual void appear(char (&matrix)[20][12]) = 0;

    virtual bool collide(char (&matrix)[20][12]) = 0;

    virtual bool stopFall(char (&matrix)[20][12]) = 0;

    virtual void heYo()=0;

};


#endif //TERMINAL_GAME_SHAPE_H
