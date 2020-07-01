//
// Created by george on 5/5/19.
//

#ifndef CONNECTN_CONNECTN_H
#define CONNECTN_CONNECTN_H

#include <vector>
#include "Player.h"
#include "Board.h"
namespace ConnectNGame {

    class Move; //forward declaration

    class ConnectN {
    friend class Player;
    public:
        explicit ConnectN(int boardRow, int boardCol, int win);
        virtual ~ConnectN() = default;
        void play();




    private:
        void determineStartingPlayer();
        Move getValidMove() const;

        const Player& getCurrentPlayer() const;
        Player& getPlayer(int num);

        bool isGameOver() const;
        bool gameWon() const;
        bool horzWin() const;
        bool vertWin() const;
        bool diagWin() const;
        bool leftDiagWin() const;
        bool rightDiagWin() const;
        bool tie() const;

        void changeTurn();

        void declareResults() const;

    private:
        Board board;
        std::vector<Player> players;
        int playerTurn, win;
    };

}



#endif //CONNECTN_CONNECTN_H
