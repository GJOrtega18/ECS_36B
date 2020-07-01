//
// Created by george on 4/25/19.
//
#include <cstdlib>
#include "moveFuncs.h"

int takeInput(char* arg) {
    return std::stoi(std::string(arg));
}


void compareSolutions(vector& fastest, vector& working) {
    if (fastest.empty()){
        fastest = working;
    }

    else if( working.size() < fastest.size()){
        fastest.clear();
        fastest = working;


    } else{
    }


}

vector& makeMove(vector& working, vector& fastest, vector& values, int current) {
    working.emplace_back(current);


    int value = values.at(current);
    int leftIndex = current - value;
    int rightIndex = current + value;




    if (leftIndex > 0) {
        if(!contains(working, leftIndex)) {
            std::vector<int> left = makeMove(working, fastest, values, leftIndex);
        }
    }


    if (rightIndex < values.size()) {
        if (!contains(working, rightIndex)) {

            std::vector<int> right = makeMove(working, fastest, values, rightIndex);
        }
    }
    if (value == values.back()){
        if (current == values.size()-1)
        compareSolutions(fastest, working);
    }

    working.pop_back();


  return fastest;
}


