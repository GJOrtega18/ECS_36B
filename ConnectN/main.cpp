#include <iostream>
#include "ConnectN.h"


int main(int arc, char* arg[]) {
    int row = std::stoi(arg[1]);
    int col = std::stoi(arg[2]);
    int win = std::stoi(arg[3]);

    ConnectNGame::ConnectN game(row,col,win);
    game.play();

    return 0;
}