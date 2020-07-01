//
// Created by george on 5/5/19.
//

#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H


#include <sstream>

namespace ConnectNGame {
    class Player;
    class Board;

    class Move {
    public:
        Move(const Player& maker);
        void parseInput(std::stringstream& input);
        bool isValid(const Board& board);
        void make(Board& board);
    private:
        const Player& maker;
        int row , col;
        bool parsedSuccessfully;
    };
}


#endif //CONNECTN_MOVE_H
