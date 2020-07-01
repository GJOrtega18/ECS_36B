//
// Created by george on 5/5/19.
//

#include <iostream>
#include "Board.h"

ConnectNGame::Board::Board(int boardRow, int boardCol, char blankChar) :
        boardRow(boardRow),
        boardCol(boardCol),
        boardState(boardRow, std::string(boardCol, blankChar)),
        blankChar(blankChar) {

}

int ConnectNGame::Board::getSize() const {
    return boardState.size();
}

void ConnectNGame::Board::display() const {

    //print column headers
    std::cout << "  ";
    for (int i = 0; i < boardCol; ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 1;
    for (int i = 0; i < 1; ++i) {
        for(const auto& row : boardState){
            if(rowIndex > boardRow){
                break;
            }

            std::cout << boardRow - rowIndex << ' ';

            for(const auto& elem : row) {
                std::cout << elem << " ";
            }
            rowIndex++;

            std::cout << std::endl;


        }
    }
}

bool ConnectNGame::Board::inBounds(int row, int col) const {
    return isBetween(row, 0, boardRow) &&
           isBetween(col, 0, boardCol);
}

bool ConnectNGame::Board::isBetween(int val, int lower, int upper) {
    return val >= lower && val <= upper;
}

bool ConnectNGame::Board::isBlankSpace(int row, int col) const {
    return boardState.at(row).at(col) == blankChar;
}

void ConnectNGame::Board::set(int row, int col, char val) {
    boardState.at(row).at(col) = val;
}

ConnectNGame::Board::iterator ConnectNGame::Board::begin() {
    return boardState.begin();
}

ConnectNGame::Board::iterator ConnectNGame::Board::end() {
    return boardState.end();
}

ConnectNGame::Board::const_iterator ConnectNGame::Board::cbegin() const {
    return boardState.cbegin();
}

ConnectNGame::Board::const_iterator ConnectNGame::Board::cend() const {
    return  boardState.cend();
}

const char ConnectNGame::Board::getBlankChar() const {
    return blankChar;
}

const char& ConnectNGame::Board::at(int row, int col) const {
    return boardState.at(row).at(col);
}

bool ConnectNGame::Board::full() const {
    int row = 0;
    for (int col = 0; col < getBoardCol(); ++col) {
        if(isBlankSpace(row, col)){
            return false;
        }
    }
    return true;
}

int ConnectNGame::Board::getRowSize() const {
    return boardRow;
}

int ConnectNGame::Board::getBoardCol() const {
    return boardCol;
}