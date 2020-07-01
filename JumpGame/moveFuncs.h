//
// Created by george on 4/25/19.
//

#ifndef JUMPGAME_MOVEFUNCS_H
#define JUMPGAME_MOVEFUNCS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using vector = std::vector<int>;

int takeInput(char* arg);

vector& makeMove(vector &working, vector &fastest, vector &values, int current);

template <typename ContainerType, typename ElementType>
bool contains(const ContainerType& container, const ElementType& element);



void compareSolutions(vector& fastest, vector& working);



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
            out << element;
        }
    }
    return out;
}


#endif //JUMPGAME_MOVEFUNCS_H
