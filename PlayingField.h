//
// Created by u238 on 7/17/23.
//

#ifndef TERMINAL_GAME_PLAYINGFIELD_H
#define TERMINAL_GAME_PLAYINGFIELD_H

#include <cstring>
#include <csignal>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <thread>
#include <chrono>


#include "Shape.h"
#include "Bar.h"


class PlayingField {

private:
    char matrix[20][12];
    bool shapeOnField= false;
    struct termios originalSettings, modifiedSettings;
public:

    PlayingField();

    void refresh();
    void play();
    Shape* giveRandomShape();
    void restoreTerminalSettings(const termios& originalSettings);
};


#endif //TERMINAL_GAME_PLAYINGFIELD_H
