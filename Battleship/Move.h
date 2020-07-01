//
// Created by Rene Grande on 2019-06-11.
//

#ifndef UNTITLED13_MOVE_H
#define UNTITLED13_MOVE_H


#include <sstream>

namespace BattleShipGame {
    class Player;
    class Board;

    class Move {
    public:
        Move(Player* maker);
        Move& operator=(const Move& rhs);
        void parseInput(std::stringstream& input);
        bool isValid(const Board& board);

        void make(Player* oppositePlayer);
        void setX(Board& board);
        void setO(Board& board);




    private:
        Player* maker;
        int row , col;
        bool parsedSuccessfully;
    };
}


#endif //UNTITLED13_MOVE_H
