//
// Created by Rene Grande on 2019-06-09.
//

#ifndef UNTITLED13_BOARD_H
#define UNTITLED13_BOARD_H

#include <iostream>
#include <vector>
#include <string>
namespace BattleShipGame {
    class Player;
    class ShipPlacement;
    class Board {
    public:

        using iterator = std::vector<std::string>::iterator;
        using const_iterator = std::vector<std::string>::const_iterator;


        explicit Board(int boardRow, int boardCol, char blankChar);
        int getSize() const;

        int getNumRows() const;

        void display() const;
        bool inBounds(int row, int col) const;
        bool isBlankSpace(int row, int col) const;
        void set(int row, int col, char val);

        void AddShip(char ship, ShipPlacement& placement, Player& player);

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        const char& at(int row, int col) const;

        bool canPlaceShipAt(ShipPlacement& placement);

        const char getBlankChar() const;
        bool full() const;

        int getNumCols() const;

    private:
        static bool isBetween(int val, int lower, int upper);

    private:
        std::vector<std::string> boardState;
        int boardRow, boardCol;
        const char blankChar;

    };
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::string& string){
    for(auto& element : string){
        out << element;
    }
    return out;
}





#endif //UNTITLED13_BOARD_H
