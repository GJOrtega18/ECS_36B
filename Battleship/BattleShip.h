//
// Created by george on 6/11/19.
//

#ifndef UNTITLED13_BATTLESHIP_H
#define UNTITLED13_BATTLESHIP_H

#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "Player.h"
#include "Move.h"

namespace BattleShipGame {
    class BattleShip {
    public:
        explicit BattleShip(GameAttributes& gameAttributes, int gameMode);
        void play();

        void determineStartingPlayer();

        const Player* getCurrentPlayer() const ;
        Player* getCurrentPlayer();
        Player* getPlayer(int num);


     //   std::unique_ptr<Player*>& getAIPlayer(int num);

        Move getValidMove(const std::string& playerType);

        bool isGameOver() const;
        bool gameWon() const;

        bool player1Dead() const;
        bool player2Dead() const;

        void changeTurn();
        void declareResults() const;

        void makeAIPlayer();

    private:
        int playerTurn;
        GameAttributes gameAttributes;
        std::vector<std::unique_ptr<Player>> players;
    };
}

#endif //UNTITLED13_BATTLESHIP_H
