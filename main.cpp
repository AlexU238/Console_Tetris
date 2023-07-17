#include <iostream>
#include <csignal>
#include "Shape.h"
#include "Bar.h"
#include "PlayingField.h"

using namespace std;

void refresh(char (&matrix)[20][12]){
    for (auto & i : matrix) {
        for (char j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}


int main() {
    system("clear");

    // for(int i=0; i<10; i++){
    //   cout<<i<<endl;
    //   sleep(1);
    //    system("clear");
    //}

    PlayingField playingField = PlayingField();

    playingField.play();











    return 0;
}
