//
// Created by u238 on 7/17/23.
//


#include "PlayingField.h"

void PlayingField::refresh() {
    chrono::milliseconds duration(100);
    this_thread::sleep_for(duration);
    system("clear");
    //todo: check for rows and move everything down
    for (auto &i: matrix) {
        for (char j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void PlayingField::play() {
    tcgetattr(STDIN_FILENO, &originalSettings);
    memcpy(&modifiedSettings, &originalSettings, sizeof(struct termios));

    // Modify the terminal settings to disable buffering and input echoing
    modifiedSettings.c_lflag &= ~(ICANON | ECHO);
    modifiedSettings.c_cc[VMIN] = 0;
    modifiedSettings.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &modifiedSettings);

    Shape *currentShape;
    while (true){
        refresh();
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(STDIN_FILENO, &readSet);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000; // Adjust timeout as needed

        int numReady = select(STDIN_FILENO + 1, &readSet, nullptr, nullptr, &timeout);
        if (numReady > 0) {
            char ch;
            read(STDIN_FILENO, &ch, 1);

            if (ch == 'q') {
                break; // Press 'q' to quit the game
            }
            switch (ch) {
                case 'a':
                    //move left
                    currentShape->moveLeft(matrix);
                    break;
                case 'd':
                    //move right
                    currentShape->moveRight(matrix);
                    break;
                case 'w':
                    //rotate right
                    currentShape->rotateRight(matrix);
                    break;
                case 's':
                    //rotate left
                    currentShape->rotateLeft(matrix);
                    break;
                case 'q':
                    //quit
                    goto end_loop;
            }
        }


        if(!shapeOnField){
            currentShape=giveRandomShape();
            if(currentShape->canAppear(matrix)){
                currentShape->appear(matrix);
                shapeOnField= true;
            }else{
                currentShape->appear(matrix);
                cout<<"game over?"<<endl;
                break;
            }
        }

        currentShape->fall(matrix);

        if(currentShape->collide(matrix) || currentShape->stopFall(matrix)) {
            shapeOnField= false;
        }


    }
    end_loop:
    restoreTerminalSettings(originalSettings);

}

Shape* PlayingField::giveRandomShape() {
    Shape *shape = new Bar({3,4,5,6,0,0,0,0},SIDE_RIGHT);

    return shape;
}

PlayingField::PlayingField() {
    for (int i=1; i<20;i++) {
        for (int j = 0; j < 12; j++) {
            if (j==0 || j == 11) {
                matrix[i][j] = '|';
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

}

void PlayingField::restoreTerminalSettings(const termios &originalSettings) {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings);
}




