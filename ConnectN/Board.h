//
// Created by george on 5/5/19.
//

#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H

#include <vector>
#include <string>
namespace ConnectNGame {
    class Board {
    public:
        friend class ConnectN;

        using iterator = std::vector<std::string>::iterator;
        using const_iterator = std::vector<std::string>::const_iterator;


        explicit Board(int boardRow, int boardCol, char blankChar);
        int getSize() const;

        int getRowSize() const;

        void display() const;
        bool inBounds(int row, int col) const;
        bool isBlankSpace(int row, int col) const;
        void set(int row, int col, char val);

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        const char& at(int row, int col) const;

        const char getBlankChar() const;
        bool full() const;

        int getBoardCol() const;

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




#endif //CONNECTN_BOARD_H
