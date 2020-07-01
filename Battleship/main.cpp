#include <iostream>
#include <fstream>
#include "BattleShip.h"
#include "AiPlayer.h"

int chooseGameMode(){
    int gameMode;
    do {
        std::cout << "What type of game do you want to play?" << std::endl;
        std::cout << "1. Human vs Human" << std::endl;
        std::cout << "2. Human vs AI" << std::endl;
        std::cout << "3. AI vs AI" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> gameMode;
    }while(gameMode < 0 || gameMode > 3);

    return gameMode;
}

int main(int arc, char* arg[]) {
    std::vector<std::string> configFile;
    std::string file = arg[1];

    std::string next;


    std::ifstream ifs;
    ifs.open(file, std::ifstream::in);
    if (ifs.is_open()) {
        while (ifs >> next) {
            configFile.push_back(next);

        }
    }
    ifs.close();
    BattleShipGame::GameAttributes gameAttributes(configFile);
    if(arc >2) {
        gameAttributes.seed = std::stoi(arg[2]);
    }
    int gameMode = chooseGameMode();

    BattleShipGame::BattleShip game(gameAttributes, gameMode);

    game.play();

    return 0;

}