//
// Created by george on 6/11/19.
//

#ifndef UNTITLED13_GAMEATTRIBUTES_H
#define UNTITLED13_GAMEATTRIBUTES_H

#include <string>
#include <vector>

namespace BattleShipGame{

    class GameAttributes {
    public:
        GameAttributes(std::vector<std::string> gameAttributes);

        int getRow() const;
        int getCol() const;
        int getNumOfShips() const;
        int seed;
        std::vector<char> ships;
        std::vector<int> healths;

    private:
        int row;
        int col;
        int numOfShips;

    };

}
#endif //UNTITLED13_GAMEATTRIBUTES_H
