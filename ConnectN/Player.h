//
// Created by george on 5/5/19.
//

#ifndef CONNECTN_PLAYER_H
#define CONNECTN_PLAYER_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element);


namespace ConnectNGame{
class ConnectN;
    class Player {

    public:
        static int playerCount;
        static std::vector<std::string> names,pieces;


        Player();
        const std::string& getName() const;
        char getPiece() const;

        bool nameIsValid(std::string& player);
        bool pieceIsValid(std::string& pieceChoice);
    private:
        std::string name;
        char piece;
    };
}

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element){
    return std::find(container.begin(), container.end(), element) != container.end();

}

#endif //CONNECTN_PLAYER_H
