//
// Created by u238 on 7/17/23.
//

#ifndef TERMINAL_GAME_SHAPE_H
#define TERMINAL_GAME_SHAPE_H

#include <iostream>
using namespace std;

enum Positions {
    UPRIGHT,
    UPSIDE_DOWN,
    SIDE_RIGHT,
    SIDE_LEFT
};

class Shape {

public:

    typedef struct {
        int x1,x2,x3,x4;
        int y1,y2,y3,y4;
    }ShapeCoords;

    Shape()=default;

    virtual ~Shape()=default;

    virtual void rotateRight(char (&matrix)[20][12]) = 0;

    virtual void rotateLeft(char (&matrix)[20][12]) = 0;

    virtual void fall(char (&matrix)[20][12]) = 0;

    virtual void moveRight(char (&matrix)[20][12]) = 0;

    virtual void moveLeft(char (&matrix)[20][12]) = 0;

    virtual bool canAppear(char (&matrix)[20][12]) = 0;

    virtual void appear(char (&matrix)[20][12]) = 0;

    virtual bool collide(char (&matrix)[20][12]) = 0;

    virtual bool stopFall(char (&matrix)[20][12]) = 0;

    virtual void clearShape(char (&matrix)[20][12])=0;

};


#endif //TERMINAL_GAME_SHAPE_H
