#include <algorithm>

#include "MoreStringFunctions.h"
#include "CharFunctions.h"


void lowerInPlace(std::string& string){
    for(char& letter : string){
        letter = tolower((letter));
    }
//
//    for(int i = 0; i < string.size(); ++i){
//        string.at(i) = tolower(string.at(i));
//    }
//
//    for(/*auto*/ std::string::iterator itr = string.begin();
//    itr != string.end(); ++itr){
//        *itr = tolower(*itr);   //*itr dereferences the iterator in order to obtain the value where its at
}

std::string lower(std::string string){
        lowerInPlace(string);
    return string;
}

void stripInPlace(std::string& string, const std::string& charsToRemove){
    lstripInPlace(string, charsToRemove);
    rstripInPlace(string, charsToRemove);
}

void lstripInPlace(std::string& string, const std::string& charsToRemove){
    auto itr = string.begin();
    for(; itr != string.end(); ++itr){
        if(!wordContains(charsToRemove, *itr)){
            break;
        }
    }
    string.erase(string.begin(), itr);
}

void rstripInPlace(std::string& string, const std::string& charsToRemove){
    auto itr = string.rbegin();
    for(; itr != string.rend(); ++itr){
        if(!wordContains(charsToRemove, *itr)){
            break;
        }
    }
    string.erase(itr.base(), string.end());
}


bool wordContains(const std::string& string, char letter) {
    return std::find(string.cbegin(), string.cend(), letter) != string.cend();
}

std::vector<std::string> split(const std::string& string, const std::string& delimiter) {
    std::vector<std::string> strings;
    std::size_t pos;

    unsigned int substringStart = 0;

    for(pos = string.find(delimiter); pos !=  std::string::npos; pos = string.find(delimiter, pos + delimiter.size())){

        strings.emplace_back(string, substringStart, pos - substringStart);
        substringStart = pos + 1;
    }
    if(substringStart < string.size()){
        strings.emplace_back(string, substringStart, string.size() - substringStart);
    }


    return strings;
}
//bool contains(const std::map<std::string, int>& wordList, std::string& word){
//    return std::find(wordList.cbegin(), wordList.cend(), word) != wordList.cend();
//    for(const auto& curchar : string) {
//        if(curchar == letter){          // or this is okay too, but other way is shorter.
//            return true;
//        }
//    }
//    return false;


