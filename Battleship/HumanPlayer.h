//
// Created by george on 6/11/19.
//

#ifndef UNTITLED13_HUMANPLAYER_H
#define UNTITLED13_HUMANPLAYER_H

#include "Player.h"

namespace BattleShipGame {
    class HumanPlayer : public Player {
    public:
        explicit HumanPlayer(GameAttributes& gameAttributes);
        virtual ~HumanPlayer() = default;

        void placeShips() override ;
        void initializeName() override;
        bool nameIsValid(std::string& player);

    };
}

#endif //UNTITLED13_HUMANPLAYER_H
