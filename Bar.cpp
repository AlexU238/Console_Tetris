//
// Created by u238 on 7/17/23.
//

#include "Bar.h"
#include <iostream>

using namespace std;

void Bar::rotateRight(char (&matrix)[20][12]) {

    if(currentPosition==1 && shapeCoords.x1 == shapeCoords.x2 && shapeCoords.x2 == shapeCoords.x3 && shapeCoords.x3 == shapeCoords.x4 && shapeCoords.x1 != 1 && shapeCoords.x1 != 10 && matrix[shapeCoords.y2][shapeCoords.x2-1]!='0' && matrix[shapeCoords.y2][shapeCoords.x2+2]!='0' && matrix[shapeCoords.y2][shapeCoords.x2+1]!='0') {
            clearShape(matrix);
            shapeCoords.y1 = shapeCoords.y3 = shapeCoords.y4 = shapeCoords.y2;
            shapeCoords.x1 = shapeCoords.x2 - 1;
            shapeCoords.x3 = shapeCoords.x2 + 1;
            shapeCoords.x4 = shapeCoords.x2 + 2;
            currentPosition = SIDE_LEFT;

    }else {
        if(matrix[shapeCoords.y2-1][shapeCoords.x2]!='0' && matrix[shapeCoords.y2+1][shapeCoords.x2]!='0' && matrix[shapeCoords.y2+2][shapeCoords.x2]!='0') {
            clearShape(matrix);
            shapeCoords.x1 = shapeCoords.x3 = shapeCoords.x4 = shapeCoords.x2;
            shapeCoords.y1 = shapeCoords.y2 - 1;
            shapeCoords.y3 = shapeCoords.y2 + 1;
            shapeCoords.y4 = shapeCoords.y2 + 2;
            currentPosition = UPSIDE_DOWN;
        }
    }
}

void Bar::rotateLeft(char (&matrix)[20][12]) {
    rotateRight(matrix);
}

void Bar::fall(char (&matrix)[20][12]) {

    if (shapeCoords.y1 < 19 && shapeCoords.y4 < 19) {
        clearShape(matrix);

        matrix[++shapeCoords.y1][shapeCoords.x1] = '0';
        matrix[++shapeCoords.y2][shapeCoords.x2] = '0';
        matrix[++shapeCoords.y3][shapeCoords.x3] = '0';
        matrix[++shapeCoords.y4][shapeCoords.x4] = '0';
    }

}

void Bar::moveRight(char (&matrix)[20][12]) {
    if (shapeCoords.x1 > 0 && shapeCoords.x4 < 10) {
        clearShape(matrix);
        matrix[shapeCoords.y1][++shapeCoords.x1] = '0';
        matrix[shapeCoords.y2][++shapeCoords.x2] = '0';
        matrix[shapeCoords.y3][++shapeCoords.x3] = '0';
        matrix[shapeCoords.y4][++shapeCoords.x4] = '0';
    }

}

void Bar::moveLeft(char (&matrix)[20][12]) {
    if (shapeCoords.x1 > 1 && shapeCoords.x4 < 10) {
        clearShape(matrix);
        matrix[shapeCoords.y1][--shapeCoords.x1] = '0';
        matrix[shapeCoords.y2][--shapeCoords.x2] = '0';
        matrix[shapeCoords.y3][--shapeCoords.x3] = '0';
        matrix[shapeCoords.y4][--shapeCoords.x4] = '0';
    }
}

bool Bar::canAppear(char (&matrix)[20][12]) {
    return (matrix[shapeCoords.y1+1][shapeCoords.x1]!='0'
    && matrix[shapeCoords.y2+1][shapeCoords.x2]!='0'
    && matrix[shapeCoords.y3+1][shapeCoords.x3]!='0'
    && matrix[shapeCoords.y4+1][shapeCoords.x4]!='0' );
}

void Bar::appear(char (&matrix)[20][12]) {
    matrix[shapeCoords.y1][shapeCoords.x1] = '0';
    matrix[shapeCoords.y2][shapeCoords.x2] = '0';
    matrix[shapeCoords.y3][shapeCoords.x3] = '0';
    matrix[shapeCoords.y4][shapeCoords.x4] = '0';
}

bool Bar::collide(char (&matrix)[20][12]) {

    switch (currentPosition) {
        case UPRIGHT:
        case UPSIDE_DOWN:
            return (matrix[shapeCoords.y4 + 1][shapeCoords.x4] == '0' );
        case SIDE_LEFT:
        case SIDE_RIGHT:
            return (shapeCoords.y1==shapeCoords.y2 && shapeCoords.y2==shapeCoords.y3 && shapeCoords.y3==shapeCoords.y4 && (matrix[shapeCoords.y1 + 1][shapeCoords.x1] == '0' || matrix[shapeCoords.y2 + 1][shapeCoords.x2] == '0' || matrix[shapeCoords.y3 + 1][shapeCoords.x3] == '0' || matrix[shapeCoords.y4 + 1][shapeCoords.x4] == '0'));
        default:
            return false;
    }
}

void Bar::clearShape(char (&matrix)[20][12]) {
    matrix[shapeCoords.y1][shapeCoords.x1] = ' ';
    matrix[shapeCoords.y2][shapeCoords.x2] = ' ';
    matrix[shapeCoords.y3][shapeCoords.x3] = ' ';
    matrix[shapeCoords.y4][shapeCoords.x4] = ' ';
}

bool Bar::stopFall(char (&matrix)[20][12]) {
    return ((shapeCoords.y1 + 1) == 20 || (shapeCoords.y4 + 1) == 20);
}

Bar::Bar(const Shape::ShapeCoords &shapeCoords, Positions currentPosition) : shapeCoords(shapeCoords),
                                                                             currentPosition(currentPosition) {}








