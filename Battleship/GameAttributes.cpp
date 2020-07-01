//
// Created by george on 6/11/19.
//

#include "GameAttributes.h"
#include <ctime>

BattleShipGame::GameAttributes::GameAttributes(std::vector<std::string> gameAttributes) : seed(time(nullptr))
{
    row = std::stoi(gameAttributes.at(0));
    col = std::stoi(gameAttributes.at(1));
    numOfShips = std::stoi(gameAttributes.at(2));

    for (int i = 3; i < gameAttributes.size(); ++i) {
        if(i%2 == 0){
            continue;
        }
        ships.push_back(gameAttributes.at(i).at(0));
    }
    for (int i = 3; i < gameAttributes.size(); ++i) {
        if(i%2 == 1){
            continue;
        }
        healths.push_back(std::stoi(gameAttributes.at(i)));
    }

}

int BattleShipGame::GameAttributes::getRow() const {
    return row;
}

int BattleShipGame::GameAttributes::getCol() const {
    return col;
}

int BattleShipGame::GameAttributes::getNumOfShips() const {
    return numOfShips;
}
