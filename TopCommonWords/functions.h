//
// Created by george on 4/15/19.
//

#ifndef TOPCOMMONWORDS_FUNCTIONS_H
#define TOPCOMMONWORDS_FUNCTIONS_H

#include <iostream>
#include <ostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "MoreStringFunctions.h"

using cmp = bool (*) (const std::string&, const std::string&);
using wordList = std::map<int, std::vector<std::string>, std::greater<>>;

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element);


// sorting functions
template <typename T>
T min(const T& a, const T& b);

template <typename T>
void swap(T& a, T& b);

template <typename T>
void sortVector(std::vector<T>& vector);

template<typename ItrType>
ItrType findMinItr(const ItrType& start, const ItrType& end);






template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector);

void cleanMap(wordList& wordList, std::string& word, int count);
void eraseEmptyKeys(wordList& wordList, int count);
void addWord(wordList& wordList, int count, std::string& word);
void printWords(wordList& wordList, int num);



#endif //TOPCOMMONWORDS_FUNCTIONS_H
