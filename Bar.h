//
// Created by u238 on 7/17/23.
//

#ifndef TERMINAL_GAME_BAR_H
#define TERMINAL_GAME_BAR_H

#include "Shape.h"

class Bar: public Shape{

    ShapeCoords shapeCoords;
    Positions currentPosition;

public:

    Bar(const ShapeCoords &shapeCoords, Positions currentPosition);

    Bar()=default;

    ~Bar() override=default;

    void rotateRight(char (&matrix)[20][12]) override;

    void rotateLeft(char (&matrix)[20][12]) override;

    void fall(char (&matrix)[20][12]) override;

    void moveRight(char (&matrix)[20][12]) override;

    void moveLeft(char (&matrix)[20][12]) override;

    void appear(char (&matrix)[20][12]) override;

    bool canAppear(char (&matrix)[20][12]) override;

    bool collide(char (&matrix)[20][12]) override;

    bool stopFall(char (&matrix)[20][12]) override;

    void clearShape(char (&matrix)[20][12]) override;
};


#endif //TERMINAL_GAME_BAR_H
