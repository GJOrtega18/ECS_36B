//
// Created by george on 6/11/19.
//

#include "RandomAI.h"
#include "Utility.h"


BattleShipGame::RandomAI::RandomAI(const BattleShipGame::GameAttributes& gameAttributes) :
        AiPlayer(gameAttributes), aiId(AiPlayer::nextAiId) {
}

BattleShipGame::Move BattleShipGame::RandomAI::getMove()  {
    Move aiMove(this);
    std::stringstream choice;
    auto itr = chooseRandom(possibleShots, randomNumberGenerator);
    choice << *(itr);
    possibleShots.erase(itr);
    aiMove.parseInput(choice);
    return aiMove;
}
