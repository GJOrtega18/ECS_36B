//
// Created by george on 6/11/19.
//

#include "HuntAndDestroyAI.h"


//
// Created by george on 6/11/19.
//

#include "Utility.h"


BattleShipGame::HuntAndDestroyAI::HuntAndDestroyAI(const BattleShipGame::GameAttributes& gameAttributes) :
        AiPlayer(gameAttributes) , mode("Hunt"), destroyShots(){
}

BattleShipGame::Move BattleShipGame::HuntAndDestroyAI::getMove() {
    Move aiMove(this);
    if(destroyShots.empty()){
        std::stringstream choice;
        auto itr = chooseRandom(possibleShots, randomNumberGenerator);
        choice << *(itr);
        possibleShots.erase(itr);
        aiMove.parseInput(choice);
    }else{
        std::stringstream choice;
        auto itr = destroyShots.begin();
        choice << *(itr);
        aiMove.parseInput(choice);
        destroyShots.erase(itr);

    }
    return aiMove;
}

void BattleShipGame::HuntAndDestroyAI::switchMode(int row, int col) {
    addShots(row, col);

}

void BattleShipGame::HuntAndDestroyAI::addShots(int row, int col) {
    std::string L,T,R,D;
    L = std::to_string(row) + " " + std::to_string(col-1);
    T = std::to_string(row-1) + " " + std::to_string(col);
    R = std::to_string(row) + " " + std::to_string(col+1);
    D = std::to_string(row+1) + " " + std::to_string(col);
    if(getBoard().inBounds(row, col-1) && getFiringBoard().isBlankSpace(row, col-1)
        && contains(L, possibleShots)) {
        auto itr = std::find(possibleShots.begin(), possibleShots.end(), L);
        possibleShots.erase(itr);
        destroyShots.push_back(L);
    }
    if(getBoard().inBounds(row -1, col) && getFiringBoard().isBlankSpace(row-1, col)
        && contains(T, possibleShots)) {

        auto itr = std::find(possibleShots.begin(), possibleShots.end(), T);
        possibleShots.erase(itr);
        destroyShots.push_back(T);
    }
    if(getBoard().inBounds(row, col+1) && getFiringBoard().isBlankSpace(row, col+1)
        && contains(R, possibleShots)) {
        auto itr = std::find(possibleShots.begin(), possibleShots.end(), R);
        possibleShots.erase(itr);
        destroyShots.push_back(R);
    }
    if(getBoard().inBounds(row+1, col) && getFiringBoard().isBlankSpace(row+1, col)
        && contains(D, possibleShots)) {
        auto itr = std::find(possibleShots.begin(), possibleShots.end(), D);
        possibleShots.erase(itr);
        destroyShots.push_back(D);
    }
}




