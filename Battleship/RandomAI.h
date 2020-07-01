//
// Created by george on 6/11/19.
//

#ifndef UNTITLED13_RANDOMAI_H
#define UNTITLED13_RANDOMAI_H

#include "AiPlayer.h"
namespace BattleShipGame {
    class RandomAI : public AiPlayer{
    public:
        RandomAI(const BattleShipGame::GameAttributes& gameAttributes);

        Move getMove() override;

    private:
        const int aiId;
    };
}

#endif //UNTITLED13_RANDOMAI_H
