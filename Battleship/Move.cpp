//
// Created by Rene Grande on 2019-06-11.
//


#include <string>
#include "Move.h"
#include "Player.h"
#include "Board.h"

BattleShipGame::Move::Move(BattleShipGame::Player* maker) : maker(maker), row(-99), col(-98), parsedSuccessfully(false) {

}

void BattleShipGame::Move::parseInput(std::stringstream& input) {
    parsedSuccessfully = static_cast<bool>(input); //input must start out as being good

    input >> row >> col;
    //we must have read both row and col
    parsedSuccessfully = parsedSuccessfully && static_cast<bool>(input);
    std::string leftovers;
    input >> leftovers;
    //and we weren't able to read anything after the  col
    parsedSuccessfully = parsedSuccessfully && !input;

}

bool BattleShipGame::Move::isValid(const Board& board) {

    if(board.isBlankSpace(row, col)) {
        return parsedSuccessfully && board.inBounds(row, col) && board.isBlankSpace(row, col);
    }
    return false;
}

void BattleShipGame::Move::make(BattleShipGame::Player* oppositePlayer) {
    if(oppositePlayer->getBoard().isBlankSpace(row,col)){
        setO(maker->getFiringBoard());
        setO(oppositePlayer->getBoard());
        std::cout << maker->getName() << "'s Firing Board" << std::endl;
        maker->getFiringBoard().display();
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << maker->getName() << "'s Placement Board" << std::endl;
        maker->getBoard().display();
        std::cout << "Missed." << std::endl;
        std::cout << std::endl;


    } else{
        char oppositeShip = oppositePlayer->getBoard().at(row,col);
        setX(maker->getFiringBoard());
        oppositePlayer->shipHealths[oppositeShip] -= 1;
        setX(oppositePlayer->getBoard());
        std::cout << maker->getName() << "'s Firing Board" << std::endl;
        maker->getFiringBoard().display();

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << maker->getName() << "'s Placement Board" << std::endl;
        maker->getBoard().display();
        std::cout << maker->getName() <<  " hit " << oppositePlayer->getName()<< "'s "
        << oppositeShip << "!" << std::endl;

        maker->switchMode(row, col);

        if(oppositePlayer->shipHealths[oppositeShip] == 0){
            std::cout << maker->getName() <<  " destroyed " << oppositePlayer->getName()<< "'s "
                      << oppositeShip << "!" << std::endl << std::endl;
        }
    }
}

void BattleShipGame::Move::setX(BattleShipGame::Board &board) {
    board.set(row,col, 'X');

}

void BattleShipGame::Move::setO(BattleShipGame::Board &board) {
    board.set(row,col, 'O');

}

BattleShipGame::Move& BattleShipGame::Move::operator=(const Move& rhs) {
    this->maker = rhs.maker;
    this->row = rhs.row;
    this->col = rhs.col;
    this->parsedSuccessfully = rhs.parsedSuccessfully;
    return *this;
}



