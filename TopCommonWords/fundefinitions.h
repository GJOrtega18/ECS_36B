//
// Created by george on 4/19/19.
//

#ifndef TOPCOMMONWORDS_FUNDEFINITIONS_H
#define TOPCOMMONWORDS_FUNDEFINITIONS_H


#include <typeinfo>
#include "functions.h"

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element){
        return std::find(container.begin(), container.end(), element) != container.end();

}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector){
    for(auto& element : vector){
        if(element != vector.back()) {
            out << element << ", ";
        }
        else{
            std::string word = element;
            stripInPlace(word);
            out << word;
        }
    }
    return out;
}

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void sortVector(std::vector<T>& vector){
    for(auto itr = vector.begin(); itr != vector.end(); ++itr){
        auto minItr = findMinItr(itr, vector.end());
        swap(*itr, *minItr);
    }
}

template<typename ItrType>
ItrType findMinItr(const ItrType& start, const ItrType& end){
    ItrType minItr(start);

    for(auto itr = start; itr != end; ++itr){
        if(*itr < *minItr){
            minItr = itr;
        }
    }
    return minItr;

}

template <typename T>
T min(const T& a, const T& b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}


#endif //TOPCOMMONWORDS_FUNDEFINITIONS_H
