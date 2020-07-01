//
// Created by Rene Grande on 2019-06-09.
//

#include "Board.h"
#include "Player.h"
#include "ShipPlacement.h"

BattleShipGame::Board::Board(int boardRow, int boardCol, char blankChar) :
        boardRow(boardRow),
        boardCol(boardCol),
        boardState(boardRow, std::string(boardCol, blankChar)),
        blankChar(blankChar) {

}

int BattleShipGame::Board::getSize() const {
    return boardState.size();
}

void BattleShipGame::Board::display() const {

    //print column headers
    std::cout << "  ";
    for (int i = 0; i < boardCol; ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (int i = 0; i < 1; ++i) {
        for(const auto& row : boardState){
            if(rowIndex > boardRow){
                break;
            }

            std::cout << rowIndex << ' ';

            for(const auto& elem : row) {
                std::cout << elem << " ";
            }
            rowIndex++;

            std::cout << std::endl;


        }
    }
}

bool BattleShipGame::Board::inBounds(int row, int col) const {
    return isBetween(row, 0, boardRow) &&
           isBetween(col, 0, boardCol);
}

bool BattleShipGame::Board::isBetween(int val, int lower, int upper) {
    return val >= lower && val < upper;
}

bool BattleShipGame::Board::isBlankSpace(int row, int col) const {
    return boardState.at(row).at(col) == blankChar;
}

void BattleShipGame::Board::set(int row, int col, char val) {
    boardState.at(row).at(col) = val;
}

BattleShipGame::Board::iterator BattleShipGame::Board::begin() {
    return boardState.begin();
}

BattleShipGame::Board::iterator BattleShipGame::Board::end() {
    return boardState.end();
}

BattleShipGame::Board::const_iterator BattleShipGame::Board::cbegin() const {
    return boardState.cbegin();
}

BattleShipGame::Board::const_iterator BattleShipGame::Board::cend() const {
    return  boardState.cend();
}

const char BattleShipGame::Board::getBlankChar() const {
    return blankChar;
}

const char& BattleShipGame::Board::at(int row, int col) const {
    return boardState.at(row).at(col);
}

bool BattleShipGame::Board::full() const {
    int row = 0;
    for (int col = 0; col < getNumCols(); ++col) {
        if(isBlankSpace(row, col)){
            return false;
        }
    }
    return true;
}

int BattleShipGame::Board::getNumRows() const {
    return boardRow;
}

int BattleShipGame::Board::getNumCols() const {
    return boardCol;
}

bool BattleShipGame::Board::canPlaceShipAt(BattleShipGame::ShipPlacement& placement) {
    bool possible = true;
    for (int i = 0; placement.rowStart + i <= placement.rowEnd ; ++i) {
        for (int j = 0; placement.colStart + j <= placement.colEnd ; ++j) {
            possible = isBlankSpace(placement.rowStart + i, placement.colStart + j);
            if(!possible){
                break;
            }
        }
        if(!possible){
            break;
        }
    }

    return inBounds(placement.rowStart,placement.colStart) &&
            inBounds(placement.rowEnd, placement.colEnd) && possible;
}

void BattleShipGame::Board::AddShip(char ship, BattleShipGame::ShipPlacement &placement, BattleShipGame::Player& player) {
    for (int i = 0; placement.rowStart + i <= placement.rowEnd ; ++i) {
        for (int j = 0; placement.colStart + j <= placement.colEnd ; ++j) {
            set(placement.rowStart + i, placement.colStart + j, ship);
        }
    }
}
