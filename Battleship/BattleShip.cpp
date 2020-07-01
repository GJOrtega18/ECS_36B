//
// Created by george on 6/11/19.
//

#include "BattleShip.h"
#include "Move.h"
#include "HumanPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntAndDestroyAI.h"

BattleShipGame::BattleShip::BattleShip(GameAttributes& gameAttributes, int gameMode):
 playerTurn(-1), gameAttributes(gameAttributes)
{
    if(gameMode == 1){
        players.push_back(std::make_unique<HumanPlayer>(this->gameAttributes));
        players.push_back(std::make_unique<HumanPlayer>(this->gameAttributes));

    }else if(gameMode == 2){
        players.push_back(std::make_unique<HumanPlayer>(this->gameAttributes));
        makeAIPlayer();
    }else{
        makeAIPlayer();
        makeAIPlayer();
    }
}

void BattleShipGame::BattleShip::play() {
    determineStartingPlayer();
    getPlayer(0)->findOpponetsShips(getPlayer(1));
    getPlayer(1)->findOpponetsShips(getPlayer(0));

    while (true) {
        if(getCurrentPlayer()->getName().at(0) != 'A' &&
           getCurrentPlayer()->getName().at(1) != 'I') {
            std::cout << getCurrentPlayer()->getName() << "'s Firing Board" << std::endl;
            getCurrentPlayer()->getFiringBoard().display();

            std::cout << std::endl << getCurrentPlayer()->getName() << "'s Placement Board" << std::endl;
            getCurrentPlayer()->getBoard().display(); //show the game state
        }
        //get move
        Move move(getCurrentPlayer());
        if(getCurrentPlayer()->getName().at(0) == 'A' &&
            getCurrentPlayer()->getName().at(1) == 'I'){
            move = getValidMove("AI");
        }else{
            move = getValidMove("Human");

        }
        //make move
        move.make(getPlayer((playerTurn+1) % players.size()));

        //makeMove(move);

        if (isGameOver()) {
            break;
        }

        //switch the turn
        changeTurn();
    }
    //

    //declare the results
    declareResults();

}

void BattleShipGame::BattleShip::determineStartingPlayer() {
    playerTurn = 0;
}

BattleShipGame::Move BattleShipGame::BattleShip::getValidMove(const std::string& playerType) {
    Move playerMove(getCurrentPlayer());
    if(playerType == "Human") {
        do {
            std::cout << getCurrentPlayer()->getName()
                      << ", where would you like to fire?" << std::endl
                      << "Enter your attack coordinate in the form row col: ";
            std::string row, col, line;
            std::cin >> row;
            std::cin >> col;
            line = row + " " + col;
            std::stringstream userIn(line);
            playerMove.parseInput(userIn);
        } while (!playerMove.isValid(getCurrentPlayer()->getFiringBoard()));
    } else{

        playerMove = (getPlayer(playerTurn))->getMove();
    }
    return playerMove;
}

const BattleShipGame::Player* BattleShipGame::BattleShip::getCurrentPlayer() const {
    return &*(players.at(playerTurn));
}


BattleShipGame::Player* BattleShipGame::BattleShip::getCurrentPlayer() {
    return &*(players.at(playerTurn));
}

//std::unique_ptr<BattleShipGame::Player*>& BattleShipGame::BattleShip::getAIPlayer(int num) {
//    return *players.at(num);
//}

bool BattleShipGame::BattleShip::isGameOver() const {
    return gameWon();
}

bool BattleShipGame::BattleShip::gameWon() const {
    return player1Dead() || player2Dead();
}



void BattleShipGame::BattleShip::changeTurn() {
    playerTurn = (playerTurn + 1) % players.size();
}

void BattleShipGame::BattleShip::declareResults() const {

        std::cout << std::endl << getCurrentPlayer()->getName() << " won the game!" << std::endl;
}

bool BattleShipGame::BattleShip::player1Dead() const {
    return (players.at(0))->shipsGone();
}

bool BattleShipGame::BattleShip::player2Dead() const{
    return (players.at(1))->shipsGone();
}

void BattleShipGame::BattleShip::makeAIPlayer() {
    int choice = -2;
    do {
        std::cout << "What AI do you want?" << std::endl;
        std::cout << "1. Cheating AI" << std::endl;
        std::cout << "2. Random AI" << std::endl;
        std::cout << "3. Hunt Destroy AI" << std::endl;
        std::cout << "Your choice: " ;
        std::cin >> choice;
    }while(choice < 0 || choice > 3);

    if(choice == 1){
        players.push_back(std::make_unique<CheatingAI>(gameAttributes));
    }
    else if(choice == 2){
        players.push_back(std::make_unique<RandomAI>(gameAttributes));
    }else{
        players.push_back(std::make_unique<HuntAndDestroyAI>(gameAttributes));
    }

}

BattleShipGame::Player* BattleShipGame::BattleShip::getPlayer(int num) {
    return &*players.at(num);
}



