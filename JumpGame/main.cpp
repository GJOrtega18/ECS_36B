#include <iostream>
#include "moveFuncs.h"

int main(int argc, char** argv) {
    int current = 0;
    std::vector<int> fastest, working, values;

    if(argc > 1) {

        for (int i = 1; i < argc; i++) {
            int arg = takeInput(argv[i]);   //take the input
            values.emplace_back(arg);

        }
        makeMove(working, fastest, values, current);//make move


        if (fastest.empty()) {
            std::cout << "There is no solution to the given game." << std::endl;
        } else {
            std::cout << "The solution is: {" << fastest << "}" << std::endl;

        }
    }else{
        std::cout << "There is no solution to the given game." << std::endl;

    }
    return 0;
}