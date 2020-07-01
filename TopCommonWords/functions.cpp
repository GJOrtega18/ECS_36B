//
// Created by george on 4/15/19.
//

#include "fundefinitions.h"
#include "functions.h"


void addWord(wordList& wordList, int count, std::string& word){
    if(contains(wordList[count], word)){

        count += 1;
        addWord(wordList, count, word);

    } else {

        wordList[count].push_back(word);
    }
}


void printWords(wordList& wordList, int num = 10) {
    int i = 1;

    for(auto& wordAndCount : wordList){
        auto& count = wordAndCount.first;
        auto& word = wordAndCount.second;
        if (word.empty()){
            continue;
        }
        sortVector(word);
        std::cout << i <<".) These words appeared "<< count << " times: {" << word << "}" << std::endl;
        if(i >= num){
            break;
        }else{
            ++i;
        }
    }
}

void cleanMap(wordList& wordList, std::string& word, int count = 1) {
    auto itr = std::find(wordList[count].begin(), wordList[count].end(), word);
    if(contains(wordList[count+1], word)) {
        wordList[count].erase(itr);
        cleanMap(wordList, word, count + 1);
    }

}

void eraseEmptyKeys(wordList& wordList, int count ) {
        if (wordList[count].empty()) {
            wordList.erase(count);
        }else{

            eraseEmptyKeys(wordList, count +1);
        }
    }
