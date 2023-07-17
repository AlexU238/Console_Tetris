//
// Created by u238 on 7/17/23.
//

#ifndef TERMINAL_GAME_BAR_H
#define TERMINAL_GAME_BAR_H

#include "Shape.h"

class Bar: public Shape{

    int x1,x2,x3,x4;
    int y1,y2,y3,y4;

public:

    Bar()=default;

    virtual ~Bar()=default;

    void rotateRight(char (&matrix)[20][12]) override;

    void rotateLeft(char (&matrix)[20][12]) override;

    void fall(char (&matrix)[20][12]) override;

    void moveRight(char (&matrix)[20][12]) override;

    void moveLeft(char (&matrix)[20][12]) override;

    void appear(char (&matrix)[20][12]) override;

    bool collide(char (&matrix)[20][12]) override;

    bool stopFall(char (&matrix)[20][12]) override;

    void heYo() override;
};


#endif //TERMINAL_GAME_BAR_H
