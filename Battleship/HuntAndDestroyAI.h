//
// Created by george on 6/11/19.
//

#ifndef UNTITLED13_HUNTANDDESTROYAI_H
#define UNTITLED13_HUNTANDDESTROYAI_H

#include "AiPlayer.h"
namespace BattleShipGame {

    class HuntAndDestroyAI : public AiPlayer{
    public:
        HuntAndDestroyAI(const BattleShipGame::GameAttributes& gameAttributes);

        Move getMove() override;
        void switchMode(int row, int col) override;
        std::string mode;

        void addShots(int row, int col);

    private:
        std::vector<std::string> destroyShots;
    };
}

#endif //UNTITLED13_HUNTANDDESTROYAI_H
