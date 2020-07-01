//
// Created by Rene Grande on 2019-06-09.
//

#include "AiPlayer.h"
#include "Utility.h"
#include "ShipPlacement.h"
#include "GameAttributes.h"

int BattleShipGame::AiPlayer::nextAiId = 1;
std::mt19937 BattleShipGame::AiPlayer::randomNumberGenerator((time(nullptr)));



BattleShipGame::AiPlayer::AiPlayer(const BattleShipGame::GameAttributes& gameAttributes) :
        Player(gameAttributes), aiId(AiPlayer::nextAiId) {
    for (int row = 0; row < getBoard().getNumRows(); ++row) {
        for (int col = 0; col < getBoard().getNumCols(); ++col) {
            std::stringstream shots;
            shots << std::to_string(row) << " " <<  std::to_string(col);

            possibleShots.emplace_back(shots.str());
        }

    }
    initializeName();
    if(aiId == 1) {
        seed_random_number_generator(gameAttributes.seed);
    }
    placeShips();
    nextAiId++;

}


void BattleShipGame::AiPlayer::placeShips() {
    std::vector<char> orientation_choice{'h', 'v'};
    const int numRows = getBoard().getNumRows();
    const int numCols = getBoard().getNumCols();

    ShipPlacement placement;
    for(const auto& ship : shipHealths) {
        do {
            char orientation = *chooseRandom(orientation_choice, randomNumberGenerator);
            if (orientation == 'h') {
                placement.rowStart = getRandInt(0, numRows - 1, randomNumberGenerator);
                placement.colStart = getRandInt(0, numCols - ship.second, randomNumberGenerator);
                placement.rowEnd = placement.rowStart;
                placement.colEnd = placement.colStart + ship.second - 1;
            } else {
                placement.rowStart = getRandInt(0, numRows - ship.second, randomNumberGenerator);
                placement.colStart = getRandInt(0, numCols - 1, randomNumberGenerator);
                placement.rowEnd = placement.rowStart + ship.second - 1;
                placement.colEnd = placement.colStart;
            }
        }while(!getBoard().canPlaceShipAt(placement));
        getBoard().AddShip(ship.first, placement, *this);
        std::cout << name << "'s Board" << std::endl;
        getBoard().display();
        std::cout << std::endl;
    }
}

void BattleShipGame::AiPlayer::initializeName() {
    std::stringstream name;
    name << "AI " << aiId;
    setName(name.str());
}

void BattleShipGame::AiPlayer::seed_random_number_generator(int seed) {
    BattleShipGame::AiPlayer::randomNumberGenerator.seed(seed);
}




