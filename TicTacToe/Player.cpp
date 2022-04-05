//
// Created by george on 4/24/19.
//

#include <iostream>
#include <string>
#include "Player.h"

TicTacToeGame::Player::Player() {
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your piece: ";
    std::cin >> piece;
    std::string extra;
    std::getline(std::cin, extra);
}

const std::string& TicTacToeGame::Player::getName() const {
    return name;
}

char TicTacToeGame::Player::getPiece() const {
    return piece;
}