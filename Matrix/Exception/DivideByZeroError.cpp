//
// Created by mfbut on 5/19/2019.
//

#include <iostream>
#include <sstream>
#include "DivideByZeroError.h"


const char *Matrix::DivideByZeroError::what() const noexcept {
    return errorString.c_str();
}

Matrix::DivideByZeroError::DivideByZeroError(int line_number, const char* file_name) : line_number(line_number),
    file_name(file_name){
    std::stringstream errorStream;
    errorStream << "A division by 0 occurred on " << file_name << ':' << line_number << std::endl;
    errorString = errorStream.str();
}
