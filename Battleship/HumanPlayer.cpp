//
// Created by george on 6/11/19.
//

#include "HumanPlayer.h"
#include "ShipPlacement.h"


BattleShipGame::HumanPlayer::HumanPlayer(GameAttributes& gameAttributes):
        Player(gameAttributes){
    playerCount++;
    initializeName();
    placeShips();

}
void BattleShipGame::HumanPlayer::placeShips() {
    const int numRows = getBoard().getNumRows();
    const int numCols = getBoard().getNumCols();

    ShipPlacement placement;
    getBoard().display();

    for(const auto& ship : shipHealths) {
        char orientation;
        int row, col;
        do {
            std::cout << name << ", do you want to place " << ship.first << " horizontally or vertically?" << std::endl;
            std::cout << "Enter h for horizontal or v for vertical" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> orientation;
        }while(orientation != 'h' && orientation != 'v');


        do {
            std::cout << name << ", enter the row and column you want to place "<< ship.first << ", which is " << ship.second << " long, at with a space in between row and col: ";
            std::cin >> row >> col;
            if (orientation == 'h') {
                placement.rowStart = row;
                placement.colStart = col;
                placement.rowEnd = placement.rowStart;
                placement.colEnd = placement.colStart + ship.second - 1;
            } else {
                placement.rowStart = row;
                placement.colStart = col;
                placement.rowEnd = placement.rowStart + ship.second - 1;
                placement.colEnd = placement.colStart;
            }
        }while(!getBoard().canPlaceShipAt(placement));
        getBoard().AddShip(ship.first, placement, *this);
        getBoard().display();
    }
}

bool BattleShipGame::HumanPlayer::nameIsValid(std::string& player) {
    const char blank = ' ';
    for(char i : player){
        if (i == blank){
            return false;
        }
    }

    return !contains(names,player);
}

void BattleShipGame::HumanPlayer::initializeName() {
    std::string extra;

    std::string tempName;
    do{
        std::cout << "Player " << playerCount << " please enter your name: ";
        std::cin >> tempName;
    }while((!nameIsValid(tempName)));
    setName(tempName);
    names.emplace_back(name);
}


