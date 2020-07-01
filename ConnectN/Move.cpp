//
// Created by george on 5/5/19.
//

#include <string>
#include "Move.h"
#include "Player.h"
#include "Board.h"

ConnectNGame::Move::Move(const ConnectNGame::Player &maker) : maker(maker), row(-99), col(-98), parsedSuccessfully(false) {

}

void ConnectNGame::Move::parseInput(std::stringstream& input) {
    parsedSuccessfully = static_cast<bool>(input); //input must start out as being good

    input  >> col;
    //we must have read both row and col
    parsedSuccessfully = parsedSuccessfully && static_cast<bool>(input);
    std::string leftovers;
    input >> leftovers;
    //and we weren't able to read anything after the  col
    parsedSuccessfully = parsedSuccessfully && !input;

}

bool ConnectNGame::Move::isValid(const Board& board) {
    row = board.getRowSize() -1;
    if(col >= board.getBoardCol() || col < 0) {
        return false;
    }
    for(int i =1; i< board.getSize(); ++i){
        if(!board.isBlankSpace(row,col)){
            row -= 1;
        }
    }

     if(board.isBlankSpace(row, col)) {
         return parsedSuccessfully && board.inBounds(row, col) && board.isBlankSpace(row, col);
     }
    return false;
}

void ConnectNGame::Move::make(ConnectNGame::Board& board) {
    board.set(row, col, maker.getPiece());
}