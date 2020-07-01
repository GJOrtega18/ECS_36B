#include <iostream>
#include <fstream>
#include "fundefinitions.h"


int main(int argc, char* argv[]) {
    std::string file = argv[1], word, line;

    int count = 1;
    int N = 10;

    if(argc > 2){
        int temp = std::stoi(argv[2]);

        N = temp;
    }
    std::ifstream ifs;

    std::map<int, std::vector<std::string>, std::greater<>> wordList;


    ifs.open (file, std::ifstream::in);


    if(ifs.is_open()) {
        while (ifs >> word) {

            stripInPlace(word);
            lowerInPlace(word);

            if (word == "the" || word == "a" || word == "an" || word == "and" || word == "in" || word == "is" ||
                word == "it") {
                continue;
            } else {
                addWord(wordList, count, word);
            }
        }
    }
    ifs.close();


    for(auto& keys : wordList) {
            for(auto& wordInVector : keys.second) {

                cleanMap(wordList, wordInVector, 1);

            }

    }
    for(auto& keys : wordList) {
        eraseEmptyKeys(wordList, keys.first);

    }
    printWords(wordList, N);

    return 0;
}