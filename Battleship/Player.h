//
// Created by Rene Grande on 2019-06-09.
//

#ifndef UNTITLED13_PLAYER_H
#define UNTITLED13_PLAYER_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "Board.h"
#include "GameAttributes.h"
#include "Move.h"

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element);


namespace BattleShipGame{
    class Player {

    public:
        static int playerCount;
        static std::vector<std::string> names;


        Player(const GameAttributes& gameAttributes);
        virtual ~Player() = default;
        virtual const std::string& getName() const;

        virtual void placeShips();
        virtual void initializeName();
        virtual Board& getBoard();
        virtual Board& getFiringBoard();

        virtual Move getMove();


        virtual bool shipsGone();

        virtual void findOpponetsShips(Player* oppositePlayer);
        std::vector<std::string> opponetsShips;

        virtual void switchMode(int row, int col);
        std::map<char,int> shipHealths;

    protected:
        std::string name;
        Board placementBoard;
        Board firingBoard;


    public:
        virtual void setName(const std::string &name);
    };
}

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element){
    return std::find(container.begin(), container.end(), element) != container.end();

}


#endif //UNTITLED13_PLAYER_H
