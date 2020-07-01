//
// Created by george on 5/5/19.
//

#include "Player.h"
#include "ConnectN.h"

int ConnectNGame::Player::playerCount = 0;
std::vector<std::string> ConnectNGame::Player::names, ConnectNGame::Player::pieces;


ConnectNGame::Player::Player() {
    std::string extra;
    playerCount++;
    std::string tempName ;

    do{
        std::cout << "Player " << playerCount << ", please enter your name: ";
        std::getline(std::cin, tempName);
    }while((!nameIsValid(tempName)));

    name = tempName;
    names.emplace_back(name);

    do {
        std::cout << name << ", please enter the character you want to use for your piece: ";

        std::getline(std::cin, extra);
    }while(!pieceIsValid(extra));
    piece = extra[0];
    pieces.emplace_back(extra);
}

const std::string& ConnectNGame::Player::getName() const {
    return name;
}

char ConnectNGame::Player::getPiece() const {

    return piece;
}

bool ConnectNGame::Player::nameIsValid(std::string& player) {
    const char blank = ' ';
    for(char i : player){
        if (i == blank){
            return false;
        }
    }

    if(contains(names, player)){
        return false;
    }
    return true;
}

bool ConnectNGame::Player::pieceIsValid(std::string& pieceChoice) {
    return pieceChoice.size() == 1 && !contains(pieces, pieceChoice);
}
