//
// Created by george on 5/5/19.
//

#include <iostream>
#include <sstream>
#include "Move.h"
#include "ConnectN.h"

ConnectNGame::ConnectN::ConnectN(int boardRow, int boardCol, int win) :
        board(boardRow,boardCol, '*'), players(2), playerTurn(-1),
        win(win) {

}

void ConnectNGame::ConnectN::play() {
    determineStartingPlayer();

    while (true) {
        board.display(); //show the game state

            //get move
        Move move = getValidMove();
        //make move
        move.make(board);
        //makeMove(move);
        if (isGameOver()) {
            break;
        }

        //switch the turn
        changeTurn();
    }
    //
    board.display();
    //declare the results
    declareResults();

}

void ConnectNGame::ConnectN::determineStartingPlayer() {
    playerTurn = 0;
}

ConnectNGame::Move ConnectNGame::ConnectN::getValidMove() const {
    Move playerMove(getCurrentPlayer());
    do {
        std::cout << getCurrentPlayer().getName() << ", please enter a column to play in: ";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream userIn(line);
        playerMove.parseInput(userIn);
    } while (!playerMove.isValid(board));
    return playerMove;
}

const ConnectNGame::Player& ConnectNGame::ConnectN::getCurrentPlayer() const {
    return players.at(playerTurn);
}

ConnectNGame::Player& ConnectNGame::ConnectN::getPlayer(int num) {
    return players.at(num);
}

bool ConnectNGame::ConnectN::isGameOver() const {
    return gameWon() || tie();
}

bool ConnectNGame::ConnectN::gameWon() const {
    return horzWin() || vertWin() || diagWin();
}

bool ConnectNGame::ConnectN::horzWin() const {
    for (int row = 1; row != board.getRowSize()+1; ++row) {
        int col = 0, count = 0;
        char firstChar = board.at(board.getRowSize()-row, col);

        for (col = 0; col <= board.getBoardCol(); ++col) {
            if(count == win) {
                break;
            }
            if(col >= board.boardCol){
                break;
            }
            char elem = board.at(board.getRowSize() - row, col);


            if(elem == board.blankChar){
                count = 0;
                continue;
            }
            if (elem != firstChar) {
                if(elem != board.blankChar) {
                    firstChar = elem;
                }
                count = 0;
            }
            count++;
        }
        if (count == win) {
            return true;
        }
    }
    return false;
}

bool ConnectNGame::ConnectN::vertWin() const {
    for (int col = 0; col != board.getSize(); ++col) {
        if(col >= board.boardCol){
            break;
        }
        if (board.isBlankSpace(board.getRowSize()-1, col)) {
            continue;
        }
        int count = 0;
        char firstChar = board.at(board.getRowSize()-1, col);
        for (int row = 1; row != board.getRowSize()+1; ++row) {
            if (count == win) {
                break;
            }
                char elem = board.at(board.getRowSize() - row, col);
            if(row > board.getRowSize()+1){
                break;
            }
            if (elem != firstChar) {
                if(elem != board.blankChar) {
                    firstChar = elem;
                }
                count = 0;
            }
            count++;
        }
        if (count == win) {
            return true;
        }
    }
    return false;
}

//X
//  X
//    X

bool ConnectNGame::ConnectN::diagWin() const {
    return leftDiagWin() || rightDiagWin();
}

//X
//  X
//    X
bool ConnectNGame::ConnectN::leftDiagWin() const {
    for (int row = 1; row != board.getRowSize()+1; ++row) {
        for(int col = 0; col != board.getBoardCol(); ++col) {
            int count = 0;
            if(col >= board.boardCol){
                break;
            }
            char firstChar = board.at(board.getRowSize() - row, col);
            for (int i = 0; i < board.getRowSize()+1; ++i) {
                if (count == win) {
                    return true;
                }
                if (board.getRowSize() - row - i < 0 || col-i < 0 ) {
                    break;
                }
                char elem = board.at(board.getRowSize() - row - i, col-i);
                if (elem == board.blankChar) {
                    count = 0;
                    continue;
                }
                if (elem != firstChar) {
                    if (elem != board.blankChar) {
                        firstChar = elem;
                    }
                    count = 0;
                }
                count++;
            }

        }
    }
    return false;
}

//    X
//  X
//X
bool ConnectNGame::ConnectN::rightDiagWin() const {
    for (int row = 1; row != board.getRowSize()+1; ++row) {
        for(int col = 0; col != board.getSize(); ++col) {
            int count = 0;
            if(col >= board.boardCol){
                break;
            }
            char firstChar = board.at(board.getRowSize() - row, col);
            for (int i = 0; i < board.getRowSize()+1; ++i) {
                if (count == win) {
                    return true;
                }
                if (board.getRowSize() - row - i < 0 || col+i >= board.boardCol ) {
                    break;
                }

                char elem = board.at(board.getRowSize() - row - i, col+i);
                if (elem == board.blankChar) {
                    count = 0;
                    continue;
                }
                if (elem != firstChar) {
                    if (elem != board.blankChar) {
                        firstChar = elem;
                    }
                    count = 0;
                }
                count++;
            }

        }
    }
    return false;

}

bool ConnectNGame::ConnectN::tie() const {
    return  !gameWon() && board.full() ;
}

void ConnectNGame::ConnectN::changeTurn() {
    playerTurn = (playerTurn + 1) % players.size();
}

void ConnectNGame::ConnectN::declareResults() const {
    if (tie()) {
        std::cout << "Tie game." << std::endl;
    } else {
        std::cout << getCurrentPlayer().getName() << " won the game!" << std::endl;
    }
}



