//
// Created by george on 6/11/19.
//

#ifndef UNTITLED13_CHEATINGAI_H
#define UNTITLED13_CHEATINGAI_H

#include "AiPlayer.h"

namespace BattleShipGame {
    class CheatingAI : public AiPlayer {
    public:
        CheatingAI(const BattleShipGame::GameAttributes &gameAttributes);
        virtual ~CheatingAI() = default;

        Move getMove() override ;

    private:
        const int aiId;
    };
}

#endif //UNTITLED13_CHEATINGAI_H
