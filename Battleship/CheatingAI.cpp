//
// Created by george on 6/11/19.
//

#include "CheatingAI.h"
#include "Utility.h"


BattleShipGame::CheatingAI::CheatingAI(const BattleShipGame::GameAttributes& gameAttributes) :
        AiPlayer(gameAttributes), aiId(AiPlayer::nextAiId) {

}

BattleShipGame::Move BattleShipGame::CheatingAI::getMove()  {
    Move aiMove(this);
    std::stringstream choice;
    auto itr = opponetsShips.begin();
    choice << *(itr);
    opponetsShips.erase(itr);
    aiMove.parseInput(choice);
    return aiMove;
}


