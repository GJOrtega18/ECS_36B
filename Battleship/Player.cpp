//
// Created by Rene Grande on 2019-06-09.
//

#include "Player.h"

int BattleShipGame::Player::playerCount = 0;
std::vector<std::string> BattleShipGame::Player::names;


BattleShipGame::Player::Player(const GameAttributes& gameAttributes) :
    placementBoard(gameAttributes.getRow(),gameAttributes.getCol(), '*'),
    firingBoard(gameAttributes.getRow(),gameAttributes.getCol(), '*')
    {

    for (int i = 0; i < gameAttributes.ships.size(); ++i) {
        shipHealths.insert({gameAttributes.ships.at(i), gameAttributes.healths.at(i)});

    }
}

const std::string& BattleShipGame::Player::getName() const {
    return name;
}


void BattleShipGame::Player::setName(const std::string &Name) {
    name = Name;
}

BattleShipGame::Board &BattleShipGame::Player::getBoard() {
    return placementBoard;
}

BattleShipGame::Board &BattleShipGame::Player::getFiringBoard() {
    return firingBoard;
}

bool BattleShipGame::Player::shipsGone() {
    for (const auto& ship : shipHealths) {
        if(ship.second != 0){
            return false;
        }
    }
    return true;
}

void BattleShipGame::Player::placeShips() {

}

void BattleShipGame::Player::initializeName() {

}

BattleShipGame::Move BattleShipGame::Player::getMove() {
    return BattleShipGame::Move(nullptr);
}


void BattleShipGame::Player::findOpponetsShips(Player* oppositePlayer) {
    for (int row = 0; row < getBoard().getNumRows(); ++row) {
        for (int col = 0; col < getBoard().getNumCols(); ++col) {
            std::string shot;
            shot = std::to_string(row) + " " + std::to_string(col);
            if(!oppositePlayer->getBoard().isBlankSpace(row,col))
                opponetsShips.push_back(shot);
        }

    }
}

void BattleShipGame::Player::switchMode(int row, int col) {

}
