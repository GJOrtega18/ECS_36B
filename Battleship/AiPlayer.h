//
// Created by Rene Grande on 2019-06-09.
//

#ifndef UNTITLED13_AIPLAYER_H
#define UNTITLED13_AIPLAYER_H

#include <random>
#include <sstream>
#include <ctime>
#include "Player.h"

namespace BattleShipGame{
    class GameAttributes;

    class AiPlayer : public Player {
    public:
        AiPlayer(const BattleShipGame::GameAttributes& gameAttributes);

        static void seed_random_number_generator(int seed);
         void placeShips() override;
         void initializeName() override;


    protected:
        static std::mt19937 randomNumberGenerator;
        std::vector<std::string> possibleShots;
        static int nextAiId;

    private:
        const int aiId;
    };
}


#endif //UNTITLED13_AIPLAYER_H
